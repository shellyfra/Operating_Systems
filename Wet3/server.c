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
    DT,
    DH,
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
        *sched_alg = DT;
    }
    else if (!strcmp(argv[4], SCHED_ALG_DH))
    {
        *sched_alg = DH;
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
pthread_cond_t waiting_queue_cond_t = PTHREAD_COND_INITIALIZER;
pthread_mutex_t waiting_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

Queue *running_queue;
pthread_mutex_t running_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t running_queue_cond_t = PTHREAD_COND_INITIALIZER;

void* threadWrapper(void* id_in_threads)
{
    int threadnumber = (intptr_t) id_in_threads;
    fprintf(stdout, "Creating thread number %d",threadnumber);
    while (RUN_ALWAYS)
    {
        // This will run and wait for the lock when there is an available connection:
        Connection con = dequeue(waiting_queue,waiting_queue_cond_t,waiting_queue_mutex);
        struct timeval current_time;
        gettimeofday(&current_time,NULL);
        double  elapsedTime = (current_time.tv_sec - con.start_req_arrival.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (current_time.tv_usec - con.start_req_arrival.tv_usec) / 1000.0;   // us to ms
        con.start_req_dispatch = elapsedTime;

        // Add the connection to the running queue
        // enqueue(running_queue,con,running_queue_cond_t,running_queue_mutex);

        // Actually handle the request. Will block the thread
        requestHandle(con.connfd);
  
        // Close the connection
        Close(con.connfd);
        // TODO remove from running queue
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t * threads;
    int listenfd, connfd, port, clientlen,threads_count,queue_size;
    enum SCHED_ALGS sched_alg;
    struct sockaddr_in clientaddr;

    getargs(&sched_alg, &threads_count,&queue_size, &port, argc, argv);
    threads = (pthread_t*)malloc(sizeof(pthread_t)*threads_count);
    memset(threads, 0, threads_count*sizeof(threads[0]));
    // TODO check return values for errors


    waiting_queue = newQueue(queue_size);
    running_queue = newQueue(queue_size);

    for (int i = 0; i < threads_count ; ++i) {
        int rc = pthread_create(&threads[i], NULL, threadWrapper, (void*)(intptr_t)i);
        if(rc)
        {
            fprintf(stderr, "pthread_create failure for thread %d", i);
        }
    }

    listenfd = Open_listenfd(port);
    while (RUN_ALWAYS)
    {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t *)&clientlen);
        Connection c;
        c.connfd = connfd;
        gettimeofday(&c.start_req_arrival,NULL);
        if (getTotalElements(waiting_queue, waiting_queue_mutex) + getTotalElements(running_queue, running_queue_mutex) >= queue_size)
        {
            // TODO handle overload alg (part 2)
        }
        else
        {
            enqueue(waiting_queue, c, waiting_queue_cond_t, waiting_queue_mutex);
        }
    }
    free(threads);
    free(waiting_queue);
    free(running_queue);
}
