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
 
void enqueue(Queue* queue, Connection item )
{
    
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

}

void enqueue_drop_head(Queue* queue, Connection item)
{
    // We reach this function when a lock is in effect!

    // Get dropped connection:   
    Connection dropped_con = dequeue_non_block(queue);

    // Close the connection:   
    Close(dropped_con.connfd);

    // Enquque the new connection:
    enqueue(queue,item);

   
}
void deleteNode(Queue* queue, node* to_delete)
{
    
    if (queue->head == NULL || to_delete == NULL)
        return;
 
    // If node to be deleted is the head node
    if (queue->head == to_delete)
    {
        queue->head = to_delete->next;
    }
    if(queue->tail == to_delete)
    {
        queue->tail = to_delete->prev;
    }
 
    // Change next of to_delete if node to be deleted is NOT the last node
    if (to_delete->next != NULL)
    {
        to_delete->next->prev = to_delete->prev;
    }

 
    // Change prev of to_delete only if node to be deleted is NOT the head node
    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
 
    // Release memory and decrement count
    free(to_delete);
    queue->element_count--;
    
}
 

void enqueue_drop_random(Queue* queue, Connection item)
{
    // We reach this function when a lock is in effect!
    
    int drop_count = 0;
    int drop_num = (queue->element_count / 4) + ((queue->element_count % 4) != 0); // delete at least 1 element

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
    int * indices_array = (int*) malloc(sizeof(int)*(queue->element_count));
    int * indices_to_remove = (int*) malloc(sizeof(int)*(queue->element_count));
    for (unsigned int i = 0; i < queue->element_count; i++)
    {
        indices_array[i]=i;
    }
    while (drop_count < drop_num) { // choose 1/4 of the elements in the arrays
        int rand_index_in_array = rand() % (queue->element_count-drop_count); // random int between 0 and random range
        int rand_index = indices_array[rand_index_in_array]; // Guaranteed to be an index that wasn't selected
        indices_to_remove[rand_index]=1;
        // Swap indexes in array:
        int temp = indices_array[queue->element_count-1-drop_count];
        indices_array[queue->element_count-1-drop_count] = rand_index;
        indices_array[rand_index_in_array] = temp;

        drop_count++;
        
    }
    // Free the indices array
    free(indices_array);
    node* it = queue->head;
    unsigned int count =0;

    // Iterate over queue and delete nodes which were selected
    while (it)
    {
        if(indices_to_remove[count])
        {
            node* temp =it->next;
            // Close connection before removing
            Close(it->con.connfd);
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
    // Enqueue the new item
    enqueue(queue,item);    
}

Connection dequeue_non_block(Queue* queue)
{
    // This is a "Force" dequeue - should only be used when a lock is in effect, and the queue is not empty
        
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
    
    return item;
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
int getTotalElements(Queue* queue  )
{
    return queue->element_count;
}