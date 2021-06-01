#ifndef __QUEUE_H__


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Queue_t {
    int start, end;
    unsigned int element_count;
    unsigned int size;
    int* elements;
} Queue;

Queue *newQueue(unsigned int size);
int isFull(Queue* queue);
 
int isEmpty(Queue* queue);
 
void enqueue(Queue* queue, int item , pthread_cond_t condition ,pthread_mutex_t mutex );
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue, pthread_cond_t condition ,pthread_mutex_t mutex );
int getTotalElements(Queue* queue ,pthread_mutex_t mutex );
// Function to get front of queue
int front(Queue* queue);
// Function to get rear of queue
int rear(Queue* queue);
#endif
