#include "queue.h"
#include <sys/time.h>
#include <math.h>
#include <stdio.h>

node* newNode(Connection con)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->con = con;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Queue *newQueue(unsigned int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->element_count = 0;
    queue->head = NULL;
    queue->tail =  NULL; 
   // queue->elements = (Connection*)malloc(sizeof(Connection)* queue->size);

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
    // Create a new node
    node* temp = newNode(item);
  
    // If queue is empty, then new node is head and tail both
    if (queue->tail == NULL) {
        queue->head = temp;
        queue->tail = temp;       
    }    
    else
    {
      // Add the new node at the head of the queue
        node* old_head = queue->head;
        queue->head = temp;
        queue->head->next = old_head;
        old_head->prev = queue->head;
        
    }
    queue->element_count++;

    //queue->end = (queue->end + 1) % queue->size;
    //queue->elements[queue->end] = item;
    //queue->element_count++;
    pthread_cond_signal(condition);
    pthread_mutex_unlock(mutex);
}

void enqueue_drop_head(Queue* queue, Connection item , pthread_cond_t* condition ,pthread_mutex_t* mutex)
{
    //TODO: Shai comment: Shouldn't this be just dequeue() and followed by enqueue(item) ?
    int empty; // if by the time the thread reached here the queue got empty that it waited in dequeue forever
    pthread_mutex_lock(mutex);
    empty = isEmpty(queue);
    pthread_mutex_unlock(mutex);
    if (!empty) dequeue(queue,condition,mutex);
    enqueue(queue,item, condition,mutex);

    // TODO: Shelly's code :
    /*
    pthread_mutex_lock(mutex);
    // This is the critical part modyifing queue properties
    
    queue->elements[queue->start].connfd = -1; // invalid connfd in order to check for errors if we accidentally try to run this element
    queue->start = (queue->start + 1) % queue->size; // drop the first element

    queue->end = (queue->end + 1) % queue->size; // add the new request to the end - should be same place where connfd = -1
    queue->elements[queue->end] = item;
    //queue->element_count++; added and removed so number is the same
    pthread_cond_signal(condition);
    pthread_mutex_unlock(mutex);
    */
}
void deleteNode(Queue* queue, node* to_delete)
{
    
    if (queue->head == NULL || to_delete == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (queue->head == to_delete)
    {
        queue->head = to_delete->next;
    }
    if(queue->tail == to_delete)
    {
        queue->tail = to_delete->prev;
    }
 
    /* Change next only if node to be deleted is NOT the last node */
    if (to_delete->next != NULL)
    {
        to_delete->next->prev = to_delete->prev;
    }

 
    /* Change prev only if node to be deleted is NOT the head node */
    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
 
    /* Finally, free the memory occupied by del*/
    free(to_delete);
    queue->element_count--;
    
}
 

void enqueue_drop_random(Queue* queue, Connection item , pthread_cond_t* condition ,pthread_mutex_t* mutex)
{
    pthread_mutex_lock(mutex);
    // This is the critical part modyifing queue properties
    int empty; // if by the time the thread reached here the queue got empty that it waited in dequeue forever
    empty = isEmpty(queue);
    if (empty) {
        //pthread_cond_signal(condition);
        pthread_mutex_unlock(mutex);
        enqueue(queue,item, condition,mutex);
        return;
    }

    //Connection * new_elements_array= (Connection*)malloc(sizeof(Connection)* queue->size);
    int drop_count = 0;
    double num_to_ceil = (double)queue->size/(double)4;
    double drop_num = ceil(num_to_ceil); // delete at least 1 element

    // Create indexes array:  [0,1,2...,q_size-1]
    // This array will be used to generate different indices without repeating them.
    // We will always randomize in a decrementing range and swap selected indices with end of array.
    // E.G the index number 2 was selected, with a 5 element array:
    //          <-  range  ->
    //          [0,1,2,3,4,5]
    //               ^
    // We swap it with the end of the array and decrement range size such that:
    //
    //          <- range->
    //          [0,1,5,3,4,2]
    //
    // Now 2 will never be generated again, as we made sure to make it out of bounds.
    int * indices_array = (int*) malloc(sizeof(int)*(queue->size));
    int * indices_to_remove = (int*) malloc(sizeof(int)*(queue->size));
    for (unsigned int i = 0; i < queue->size; i++)
    {
        indices_array[i]=i;
    }
    while (drop_count < drop_num) { // choose 1/4 of the elements in the arrays
        int rand_index_in_array = rand() % (queue->size-drop_count); // random int between 0 and queue size
        int rand_index = indices_array[rand_index_in_array]; // Guaranteed to be an index that wasn't selected
        indices_to_remove[rand_index]=1;
        // Swap indexes in array:
        int temp = indices_array[queue->size-drop_count];
        indices_array[queue->size-drop_count] = rand_index;
        indices_array[rand_index_in_array] = temp;

        drop_count++;
        
    }
    free(indices_array);
    node* it = queue->head;
    unsigned int count =0;
    while (it)
    {
        if(indices_to_remove[count])
        {
            node* temp =it->next;
            deleteNode(queue,it);
            it=temp;
        }
        else
        {
            it = it->next;        
        }        
        count++;
    }
    free(indices_to_remove);

    /*
    while (drop_count < drop_num) { // choose 1/4 of the elements in the arrays
        int rand_index_in_array = rand() % (queue->size-drop_count); // random int between 0 and queue size
        int rand_index = indices_array[rand_index_in_array]; // Guaranteed to be an index that wasn't selected
        //if (queue->elements[rand_index].connfd != -1) { // id item wasn't already chosen
        queue->elements[rand_index].connfd = -1 ; // change to invalid value

        // Swap indexes in array:
        int temp = indices_array[queue->size-drop_count];
        indices_array[queue->size-drop_count] = rand_index;
        indices_array[rand_index_in_array] = temp;

        drop_count++;
        //}
    }
  
    
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
*/
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
        // Give up processor until not empty
        pthread_cond_wait(condition,mutex);
    }
        
    // Store previous tail and move front one node ahead
    node* temp = queue->tail;
  
    queue->tail = queue->tail->prev;
  
    
    if (queue->tail == NULL)
    {
        // If we dequeued last element
        queue->head = NULL;
    }
        
    Connection item = temp->con;
    free(temp);
    queue->element_count--;

    /*
    queue->start = (queue->start + 1) % queue->size;
    queue->element_count--;
    */
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