#include "segel.h"
#include "request.h"

//
// server.c: A very, very simple web server
//
// To run:
//  ./server <portnum (above 2000)>
//
// Repeatedly handles HTTP requests sent to this port number.
// Most of the work is done within routines written in request.c
//

enum SCHED_ALGS{BLOCK=0 , DT, DH, RNADOM};
// HW3: Parse the new arguments too
void getargs(enum SCHED_ALGS *sched_alg, int *threads_count,int *queue_size, int *port, int argc, char *argv[])
{
    if (argc < 5)
    {
        fprintf(stderr, "Usage: %s <portnum> <threads> <queue_size> <schedalg>\n", argv[0]);
        exit(1);
    }
    *port = atoi(argv[1]);
    
}

int main(int argc, char *argv[])
{
    int listenfd, connfd, port, clientlen,threads_count,queue_size;
    enum SCHED_ALGS sched_alg;
    struct sockaddr_in clientaddr;

    getargs(&sched_alg, &threads_count,&queue_size, &port, argc, argv);

    //
    // HW3: Create some threads...
    //

    listenfd = Open_listenfd(port);
    while (1)
    {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t *)&clientlen);

        //
        // HW3: In general, don't handle the request in the main thread.
        // Save the relevant info in a buffer and have one of the worker threads
        // do the work.
        //
        requestHandle(connfd);

        Close(connfd);
    }
}
