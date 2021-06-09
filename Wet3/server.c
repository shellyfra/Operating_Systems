#include "segel.h"
#include "request.h"
#include "queue.h"
#include <pthread.h>
//
// server.c: A very, very simple web server
//
// To run:
//  ./server <portnum (above 2000)>
//
// Repeatedly handles HTTP requests sent to this port number.
// Most of the work is done within routines written in request.c
//
#define SCHED_ALG_BLOCK "block"
#define SCHED_ALG_DT "dt"
#define SCHED_ALG_DH "dh"
#define SCHED_ALG_RANDOM "random"
#define RUN_ALWAYS (1)

enum SCHED_ALGS
{
    BLOCK = 0,
    DROP_TAIL,
    DROP_HEAD,
    RANDOM
};
// HW3: Parse the new arguments too
void getargs(enum SCHED_ALGS *sched_alg, int *threads_count, int *queue_size, int *port, int argc, char *argv[])
{

    if (argc < 5)
    {
        fprintf(stderr, "Usage: %s <portnum> <threads> <queue_size> <schedalg>\n", argv[0]);
        exit(1);
    }
    short valid_args = 1;
    *port = atoi(argv[1]);
    *threads_count = atoi(argv[2]);
    *queue_size = atoi(argv[3]);

    if (!strcmp(argv[4], SCHED_ALG_BLOCK))
    {
        *sched_alg = BLOCK;
    }
    else if (!strcmp(argv[4], SCHED_ALG_DT))
    {
        *sched_alg = DROP_TAIL;
    }
    else if (!strcmp(argv[4], SCHED_ALG_DH))
    {
        *sched_alg = DROP_HEAD;
    }
    else if (!strcmp(argv[4], SCHED_ALG_RANDOM))
    {
        *sched_alg = RANDOM;
    }
    else
    {
        valid_args = 0;
    }
    valid_args = valid_args && (*port) >= 0 && (*threads_count) > 0 && (*queue_size) > 0;
    if (!valid_args)
    {
        fprintf(stderr, "Usage: %s <portnum> <threads> <queue_size> <schedalg>\n", argv[0]); // TODO make clearer
        exit(1);
    }
}

Queue *waiting_queue;
pthread_cond_t waiting_queue_cond_t;
pthread_mutex_t waiting_queue_mutex;

pthread_cond_t waiting_queue_cond_block;
//pthread_mutex_t waiting_queue_mutex_block;

Queue *running_queue;
pthread_mutex_t running_queue_mutex;
pthread_cond_t running_queue_cond_t;

enum SCHED_ALGS sched_alg; // Setup once in the master thread. Will never change
void *threadWrapper(void *ts)
{
    thread_statistics *thread_statistics_p = (thread_statistics *)ts;
    //fprintf(stdout, "Creating thread number %d", thread_statistics_p->thread_id);
    while (RUN_ALWAYS)
    {
        // This will run and wait for the lock when there is an available connection:
        Connection con = dequeue(waiting_queue, &waiting_queue_cond_t, &waiting_queue_mutex);

        gettimeofday(&con.start_req_dispatch, NULL);

        // Add the connection to the running queue
        pthread_mutex_lock(&running_queue_mutex);

        enqueue(running_queue, con);

        pthread_cond_signal(&running_queue_cond_t);
        // Release lock on waiting queue
        pthread_mutex_unlock(&running_queue_mutex);


        // Handle the request. Will block the thread
        requestHandle(con.connfd, thread_statistics_p, con);

        // Close the connection
        Close(con.connfd);
        // Dequeuing is not in order. Only used for evaluating how many requests are running,
        // So we don't care if this thread deque's another thread's request

        dequeue(running_queue, &running_queue_cond_t, &running_queue_mutex);
        // Signal the block algorithm that it can insert a new request if it was blocked:
        if (sched_alg == BLOCK)
        {
            pthread_cond_signal(&waiting_queue_cond_block);
        }
    }

    // Will never reach here..
    free(thread_statistics_p);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t *threads;
    int listenfd, connfd, port, clientlen, threads_count, queue_size;

    struct sockaddr_in clientaddr;

    getargs(&sched_alg, &threads_count, &queue_size, &port, argc, argv);

    threads = (pthread_t *)malloc(sizeof(pthread_t) * threads_count);
    memset(threads, 0, threads_count * sizeof(threads[0]));
    // TODO check return values for errors

    waiting_queue = newQueue(queue_size);
    running_queue = newQueue(queue_size);

    pthread_cond_init(&waiting_queue_cond_t, NULL);
    pthread_mutex_init(&waiting_queue_mutex, NULL);

    pthread_cond_init(&waiting_queue_cond_block, NULL);
    //pthread_mutex_init(&waiting_queue_mutex_block, NULL);

    pthread_cond_init(&running_queue_cond_t, NULL);
    pthread_mutex_init(&running_queue_mutex, NULL);

    for (int i = 0; i < threads_count; ++i)
    {
        thread_statistics *ts = (thread_statistics *)malloc(sizeof(thread_statistics));

        ts->thread_id = i;
        int rc = pthread_create(&threads[i], NULL, threadWrapper, (void *)ts);
        if (rc)
        {
            fprintf(stderr, "pthread_create failure for thread %d", i);
        }
    }

    listenfd = Open_listenfd(port);
    while (RUN_ALWAYS)
    {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t *)&clientlen);
        Connection con;
        con.connfd = connfd;
        gettimeofday(&con.start_req_arrival, NULL);

        // Start of critical region:

        pthread_mutex_lock(&waiting_queue_mutex);
        int num_of_requests = getTotalElements(waiting_queue) + getTotalElements(running_queue);
        //printf("waiting queue : %d, running queue : %d \n",  getTotalElements(waiting_queue, &waiting_queue_mutex), getTotalElements(running_queue, &running_queue_mutex));
        if (num_of_requests >= queue_size)
        {
            // num_of_requests in waiting queue is gurantedd not to change here! since we locked the waiting queue!
            switch (sched_alg)
            {
            case BLOCK:
                // Use another lock, although there is only one server thread
                //pthread_mutex_lock(&waiting_queue_mutex_block);

                // Give up proccessor until signaled by the dequeing from running_queue

                while (getTotalElements(waiting_queue) + getTotalElements(running_queue) >= queue_size)
                {
                    // Give up processor there's apce for the new request.
                    // This will block any incoming requests, but will not block threads from dequeueing the waiting queue
                    pthread_cond_wait(&waiting_queue_cond_block,&waiting_queue_mutex);
                }
                //pthread_cond_wait(&waiting_queue_cond_block, &waiting_queue_mutex_block);

                // No need for a while to check the number of requests again,
                // Since we only have dequeing once the server gave up the proccessor

                //pthread_mutex_unlock(&waiting_queue_mutex_block);

                // Guaranteed to have space for more requests now:
                enqueue(waiting_queue, con);
                break;
            case DROP_TAIL:
                // Do not handle, drop immediately:
                Close(con.connfd);
                break;
            case DROP_HEAD:
                if(getTotalElements(waiting_queue) == 0)
                {
                    // If all requests are being handled and the queue is full, drop the request
                    Close(con.connfd);
                }
                else
                {
                    enqueue_drop_head(waiting_queue, con);
                }
                
                break;
            case RANDOM:
                if(getTotalElements(waiting_queue) == 0)
                {
                    // If all requests are being handled and the queue is full, drop the request
                    Close(con.connfd);
                }
                else
                {
                    enqueue_drop_random(waiting_queue, con);
                }

                break;
            default:
                break;
            }
        }
        else
        {
            enqueue(waiting_queue, con);
        }

        // Signal all threads to keep processing from wating queue
        pthread_cond_signal(&waiting_queue_cond_t);
        // Release lock on waiting queue
        pthread_mutex_unlock(&waiting_queue_mutex);
        // End of critical region
    }
    free(threads);
    free(waiting_queue);
    free(running_queue);
}
