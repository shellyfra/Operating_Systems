#include "queue.h"
#include <sys/time.h>
#include <math.h>
#include <stdio.h>

Queue *newQueue(unsigned int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->element_count = 0;
    queue->start = 0;

    queue->end =  - 1; // So that the first element will be added at 0 index
    queue->elements = (Connection*)malloc(sizeof(Connection)* queue->size);

    srand(time(NULL));   // Initialization of rand function, should only be called once.

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
    if (isFull(queue)){ // TODO add in overloading handling PT2
        pthread_mutex_unlock(mutex);
        return;
    }

    queue->end = (queue->end + 1) % queue->size;
    queue->elements[queue->end] = item;
    queue->element_count++;
    pthread_cond_signal(condition);
    pthread_mutex_unlock(mutex);
}

void enqueue_drop_head(Queue* queue, Connection item , pthread_cond_t* condition ,pthread_mutex_t* mutex)
{
    pthread_mutex_lock(mutex);
    // This is the critical part modyifing queue properties
    queue->elements[queue->start].connfd = -1; // invalid connfd in order to check for errors if we accidentally try to run this element
    queue->start = (queue->start + 1) % queue->size; // drop the first element

    queue->end = (queue->end + 1) % queue->size; // add the new request to the end - should be same place where connfd = -1
    queue->elements[queue->end] = item;
    //queue->element_count++; added and removed so number is the same
    pthread_cond_signal(condition);
    pthread_mutex_unlock(mutex);
}

void enqueue_drop_random(Queue* queue, Connection item , pthread_cond_t* condition ,pthread_mutex_t* mutex)
{
    pthread_mutex_lock(mutex);
    // This is the critical part modyifing queue properties
    Connection * new_elements_array= (Connection*)malloc(sizeof(Connection)* queue->size);
    int drop_count = 0;
    double num_to_ceil = (double)queue->size/(double)4;
    double drop_num = ceil(num_to_ceil); // delete at least 1 element

    // Create indexes array:  [0,1,2...,q_size-1]
    // This array will be used to generate different indices without repeating them.
    // We will always randomize in a decrementing range and swap selected indices with end of array.
    // E.G the index number 2 was slected, with a 5 element array:
    //          <-  range  ->
    //          [0,1,2,3,4,5]
    //               ^
    // We swap it with the end of the array and decrement range size such that:
    //
    //          <- range->
    //          [0,1,5,3,4,2]
    //
    // Now 2 will never be generated again, as we made sure to make it out of bounds.
    int * indexes_array = (int*) malloc(sizeof(int)*(queue->size));
    for (unsigned int i = 0; i < queue->size; i++)
    {
        indexes_array[i]=i;
    }
    

    while (drop_count < drop_num) { // choose 1/4 of the elements in the arrays
        int rand_index_in_array = rand() % (queue->size-drop_count); // random int between 0 and queue size
        int rand_index = indexes_array[rand_index_in_array]; // Guaranteed to be an index that wasn't selected
        //if (queue->elements[rand_index].connfd != -1) { // id item wasn't already chosen
        queue->elements[rand_index].connfd = -1 ; // change to invalid value

        // Swap indexes in array:
        int temp = indexes_array[queue->size-drop_count];
        indexes_array[queue->size-drop_count] = rand_index;
        indexes_array[rand_index_in_array] = temp;

        drop_count++;
        //}
    }
    free(indexes_array);

    int new_elements_index = 0;
    int old_queue_index = queue->start;
    for (int i = 0; i < queue->size; i++) { // add all un-chosen elements to the new array
        if (queue->elements[old_queue_index].connfd != -1) {
            new_elements_array[new_elements_index].connfd = queue->elements[old_queue_index].connfd;
            new_elements_array[new_elements_index].start_req_arrival = queue->elements[old_queue_index].start_req_arrival;
            new_elements_array[new_elements_index].start_req_dispatch = queue->elements[old_queue_index].start_req_dispatch;
            new_elements_index++;
        }
        old_queue_index = (old_queue_index + 1) % queue->size;
    }
    
    free(queue->elements); // delete old array
    queue->elements = new_elements_array;

    //change start and end for new queue
    queue->start = 0;
    queue->end = new_elements_index; // if for example added 5 elements -> last one is array[4] and the new one is array[5]
    queue->elements[queue->end] = item;
    queue->element_count = new_elements_index +1; // how many added to the new list + the new element ( = 1 )

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