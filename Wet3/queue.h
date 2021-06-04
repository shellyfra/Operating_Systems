#ifndef __QUEUE_H__


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct connection_t {
    int connfd;
    struct timeval  start_req_arrival;
    double  start_req_dispatch;
} Connection;

typedef struct Queue_t {
    int start, end;
    unsigned int element_count;
    unsigned int size;
    Connection* elements;
} Queue;

Queue *newQueue(unsigned int size);
int isFull(Queue* queue);
 
int isEmpty(Queue* queue);
 
void enqueue(Queue* queue, Connection item , pthread_cond_t condition ,pthread_mutex_t mutex );
 
// Function to remove an item from queue.
// It changes front and size
Connection dequeue(Queue* queue, pthread_cond_t condition ,pthread_mutex_t mutex );
int getTotalElements(Queue* queue ,pthread_mutex_t mutex );
// Function to get front of queue
int front(Queue* queue);
// Function to get rear of queue
int rear(Queue* queue);
#endif
