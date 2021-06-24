#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct node_t {
    int *soket;
    struct timeval arrival;
    struct node_t* next;
    struct node_t* prev;
} Node;

typedef struct queue{
    Node* first;
    Node* last;
    int queue_size;
    int max_queue_size;
} Queue;

typedef struct statistics_threads{
    int thread_id;
    struct timeval arrival;
    struct timeval dispatch;
    int count;
    int static_count;
    int dynamic_count;
} StatThreads;

Queue* createQueue(int max);

int* queuePop(Queue* queue, StatThreads* statThreads);

bool queuePush(Queue* queue,int* new_socket, struct timeval *arrival);

int* queueRemoveByIndex(Queue* queue, int indexToRemove);

int getQueueSize(Queue* queue);

StatThreads* createStatisticsThreads(int queue_size);

void statisticsThreadsInit(StatThreads* stat,int thread_id);

void destroyQueue(Queue* queue);

#endif
