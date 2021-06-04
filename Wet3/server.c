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

enum SCHED_ALGS{BLOCK=0 , DT, DH, RANDOM};
// HW3: Parse the new arguments too
void getargs(enum SCHED_ALGS *sched_alg, int *threads_count,int *queue_size, int *port, int argc, char *argv[])
{
    
    if (argc < 5 )
    {
        fprintf(stderr, "Usage: %s <portnum> <threads> <queue_size> <schedalg>\n", argv[0]);
        exit(1);
    }
    short valid_args = 1;   
    *port = atoi(argv[1]);
    *threads_count = atoi(argv[2]);
    *queue_size = atoi(argv[3]);
    
    if(!strcmp(argv[4],SCHED_ALG_BLOCK))
    {
        *sched_alg = BLOCK;
    }
    else if (!strcmp(argv[4],SCHED_ALG_DT))
   {
       *sched_alg = DT;
   }
    else if (!strcmp(argv[4],SCHED_ALG_DH))
   {
       *sched_alg = DH;
   }
   else if (!strcmp(argv[4],SCHED_ALG_RANDOM))
   {
       *sched_alg = RANDOM;
   }
   else
   {
       valid_args = 0;
       
   }
    valid_args =valid_args && (*port)>=0 && (*threads_count)>0 && (*queue_size)>0;
    if(!valid_args)
    {
        fprintf(stderr, "Usage: %s <portnum> <threads> <queue_size> <schedalg>\n", argv[0]); // TODO make clearer
        exit(1);
    }
}
void* threadWrapper(void* id_in_threads)
{
    // Shai
    //requestHandle ()
    return NULL;
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

    Queue * waiting_queue = newQueue(queue_size);
    pthread_cond_t waiting_queue_cond_t;
    pthread_cond_init(&waiting_queue_cond_t, NULL);
    pthread_mutex_t waiting_queue_mutex;
    pthread_mutex_init(&waiting_queue_mutex, NULL);

    Queue * running_queue = newQueue(queue_size);
    pthread_mutex_t running_queue_mutex;
    pthread_mutex_init(&running_queue_mutex, NULL);
    pthread_cond_t running_queue_cond_t;
    pthread_cond_init(&running_queue_cond_t, NULL);

    for (int i = 0; i < threads_count ; ++i) {
        pthread_create(&threads[i], NULL, threadWrapper, (void*)i);
    }

    listenfd = Open_listenfd(port);
    while (1)
    {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t *)&clientlen);

        if(getTotalElements(waiting_queue,waiting_queue_mutex)
            +getTotalElements(running_queue,running_queue_mutex)>=queue_size)
        {
            // TODO handle overload alg (part 2)
        }
        else
        {
            enqueue(waiting_queue, connfd,waiting_queue_cond_t,waiting_queue_mutex);
        }
        //
        // HW3: In general, don't handle the request in the main thread.
        // Save the relevant info in a buffer and have one of the worker threads
        // do the work.
        //
        requestHandle(connfd);

        Close(connfd);
    }
    free(threads);
    free(waiting_queue);
    free(running_queue);
}
