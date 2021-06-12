#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "segel.h"
typedef struct connection_t
{
    int connfd;
    struct timeval start_req_arrival;
    struct timeval start_req_dispatch;
    struct timeval start_req_interval;
} Connection;

typedef struct node_t
{
    Connection con;
    struct node_t *next;
    struct node_t *prev;
} node;
typedef struct Queue_t
{
    node *head, *tail;
    unsigned int element_count;
    unsigned int size;
    node *elements;
} Queue;

Queue *newQueue(unsigned int size);
int isFull(Queue *queue);

int isEmpty(Queue *queue);

void enqueue(Queue *queue, Connection item);
void enqueue_drop_head(Queue *queue, Connection item);
void enqueue_drop_random(Queue *queue, Connection item);
// Function to remove an item from queue.
// It changes front and size
Connection dequeue_non_block(Queue* queue);
Connection dequeue(Queue *queue, pthread_cond_t *condition, pthread_mutex_t *mutex);
int getTotalElements(Queue *queue);
// Function to get front of queue
int front(Queue *queue);
// Function to get rear of queue
int rear(Queue *queue);
#endif
