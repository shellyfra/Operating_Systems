#include "queue.h"

Queue *newQueue(unsigned int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->element_count = 0;
    queue->start = 0;

    
    queue->end =  - 1; // So that the first element will be added at 0 index
    queue->elements = (Connection*)malloc(sizeof(Connection)* queue->size);
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->element_count);
}
 
int isEmpty(Queue* queue)
{
    return (queue->element_count == 0);
}
 
void enqueue(Queue* queue, Connection item , pthread_cond_t* condition ,pthread_mutex_t* mutex )
{
    pthread_mutex_lock(mutex);
    // This is the critical part modyifing queue properties
    if (isFull(queue)) // TODO add in overloading handling PT2
        return;
    queue->end = (queue->end + 1) % queue->size;
    queue->elements[queue->end] = item;
    queue->element_count++;
    pthread_cond_signal(condition);
    pthread_mutex_unlock(mutex);
}
 
// Function to remove an item from queue.
// It changes front and size
Connection dequeue(Queue* queue, pthread_cond_t* condition ,pthread_mutex_t* mutex )
{
    pthread_mutex_lock(mutex);
    // This is the critical part modyifing queue properties
    while (isEmpty(queue))
    {
        pthread_cond_wait(condition,mutex);
    }
        
    Connection item = queue->elements[queue->start];
    queue->start = (queue->start + 1) % queue->size;
    queue->element_count--;
    pthread_mutex_unlock(mutex);
    return item;
}
int getTotalElements(Queue* queue ,pthread_mutex_t* mutex )
{
    pthread_mutex_lock(mutex);

    int elements_count = queue->element_count;
    pthread_mutex_unlock(mutex);
    return elements_count;
}
 /*
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
*/