#include "queue.h"
#include "segel.h"

pthread_mutex_t mutex;
pthread_cond_t  enter_cond_request;
pthread_cond_t  remove_cond_request;

Queue* createQueue(int max){
    if (max<0){
        perror("negative maximum");
        return NULL;
    }

    Queue* queue = (Queue*)malloc(sizeof(Queue));

    // in case malloc failed
    if (queue == NULL){
        perror("out of memory");
        return NULL;
    }
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&enter_cond_request, NULL);
    pthread_cond_init(&remove_cond_request, NULL);
    queue->first = NULL;
    queue->last = NULL;
    queue->queue_size = 0;
    queue->max_queue_size = max;
     
    return queue;
}

int* queuePop(Queue* queue, StatThreads* statThreads){
    if (!queue){
        perror("empty value");
        return NULL;
    }
    pthread_mutex_lock(&mutex);

    while (queue->queue_size <= 0){
        pthread_cond_wait(&enter_cond_request,&mutex);
    }

    int* ret = queue->first->soket;
    Node* curNodeInQueue = queue->first;
    if (NULL != statThreads){
        statThreads->arrival = curNodeInQueue->arrival;
    }
    queue->first = queue->first->next;
    
    if (queue->first == NULL){
        queue->last = NULL;
    }

    queue->queue_size--;
    pthread_cond_signal(&remove_cond_request);
    pthread_mutex_unlock(&mutex);
    free(curNodeInQueue);
    return ret;
}

//return true if push success
bool queuePush(Queue* queue, int* client_socket, struct timeval* arrival){
    if (!queue || !client_socket || !arrival){
        perror("empty value");
        return false;
    }
    pthread_mutex_unlock(&mutex);
    while (queue->queue_size == queue->max_queue_size){
        pthread_cond_wait(&remove_cond_request,&mutex);
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        perror("out of memory");
        return false;
    }

    struct timeval temp = *arrival;
    //new_node->arrival = temp.tv_sec + (temp.tv_usec)/1.0e6;
    new_node->arrival = temp;
    new_node->soket = client_socket;
    new_node->next = NULL;
    
    if (queue->last == NULL){
        queue->first = new_node;
    }
    else{
        queue->last->next = new_node;
    }
    
    queue->last = new_node;
    queue->queue_size++;
    pthread_cond_signal(&enter_cond_request);
    pthread_mutex_unlock(&mutex);
    return true;
}

int* deleteNodeFromQueue(Queue* queue, Node* nodeToDelete, Node* prevToDelete){
    if (!queue){
        perror("empty value");
        return NULL;
    }

    if (nodeToDelete == prevToDelete) {
        queue->first = queue->first->next;
    }
    if (nodeToDelete->next == NULL){
        if (nodeToDelete == prevToDelete) {
            queue->last = NULL;
        } else {
            queue->last = prevToDelete;
        }
    }
    prevToDelete->next = nodeToDelete->next;
    int* retVal = nodeToDelete->soket;
    free(nodeToDelete);
    queue->queue_size--;
    return retVal;
}

int* queueRemoveByIndex(Queue* queue, int indexToRemove){
    if (!queue){
        perror("empty value");
        return NULL;
    }

    pthread_mutex_lock(&mutex);
    if(queue->queue_size <= indexToRemove){
        perror("the index to remove is smaller than the size of the queue");
        pthread_mutex_unlock(&mutex);
        return NULL;
    }

    Node* curNodeInQueue = queue->first;
    Node* prevNodeInQueue = queue->first;

    // find the node we want to remove from queue
    for (int i = 0; i < indexToRemove - 1; i++){
        prevNodeInQueue = prevNodeInQueue->next;
    }
    for (int i = 0; i < indexToRemove ; i++){
        curNodeInQueue = curNodeInQueue->next;
    }

    int * result = deleteNodeFromQueue(queue, curNodeInQueue, prevNodeInQueue);
    pthread_mutex_unlock(&mutex);
    return result;
}

int getQueueSize(Queue* queue){
    pthread_mutex_lock(&mutex);
    int queue_size = queue->queue_size;
    pthread_mutex_unlock(&mutex);
    return queue_size;
}

StatThreads* createStatisticsThreads(int size){
    StatThreads* ret = (StatThreads*)malloc(sizeof(StatThreads)*size);

    // in case malloc failed
    if (ret == NULL){
        perror("out of memory");
        return NULL;
    }

    return ret;
}

void statisticsThreadsInit(StatThreads* stat,int id){
    stat->thread_id = id;
    //stat->arrival = 0;
    //stat->dispatch = 0;
    stat->count = 0;
    stat->static_count = 0;
    stat->dynamic_count = 0;
}

void destroyQueue(Queue* queue){
    if (!queue){
        return;
    }

    while(queue->queue_size > 0){
        deleteNodeFromQueue(queue,queue->first, queue->first);
    }
    free(queue);
}
