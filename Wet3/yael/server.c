#include "segel.h"
#include "request.h"
#include "queue.h"
#include <stdbool.h>

// 
// server.c: A very, very simple web server
//
// To run:
//  ./server <portnum (above 2000)>
//
// Repeatedly handles HTTP requests sent to this port number.
// Most of the work is done within routines written in request.c
//

//global declerations
Queue* queue;
pthread_mutex_t active_mutex;
int count_active_threads = 0;
pthread_mutex_t second_active_mutex;

int get_count_active_threads() {
    pthread_mutex_lock(&active_mutex);
    int result = count_active_threads;
    pthread_mutex_unlock(&active_mutex);
    return result;
}

void set_count_active_threads(int new_val) {
    pthread_mutex_lock(&active_mutex);
    count_active_threads = new_val;
    pthread_mutex_unlock(&active_mutex);
}

//declerations for functions we implement after the main
void* startRoutine(void* id);
void dropTail(int client);
bool dropHead(int* fd);
void dropRandom();
bool schedAlgorithm(int max_queue_size,int client,char* sched);

// HW3: Parse the new arguments too
void getargs(int* port, int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    *port = atoi(argv[1]);
}

int main(int argc, char *argv[])
{
    // declerations
    int threads_number =  atoi(argv[2]); //the size of the thread pool
    int max_queue_size =  atoi(argv[3]); // the maximum size of queue
    char* full_queue = argv[4]; // algorithm which handles a full queue
    int listenfd, connfd, port, clientlen;
    struct timeval arrival;
    struct sockaddr_in clientaddr;
    
    pthread_mutex_init(&active_mutex, NULL);
    queue = createQueue(max_queue_size);
    pthread_t* threadPool = (pthread_t*)malloc(sizeof(pthread_t)*max_queue_size);
    if (threadPool == NULL){
        destroyQueue(queue);
    }
    StatThreads* statisticsThreads = createStatisticsThreads(threads_number);

    getargs(&port, argc, argv);

    // 
    // HW3: Create some threads...
    //

    for(int  i = 0; i < threads_number; i++){
        int* id = (int*)malloc(sizeof(int));
        if(id == NULL){
            perror("out of memory");
            return 0;
        }
        *id = i;
        //create a new thread
        // the attr is NULL so the default attributes are used
        //it returns 0 in case of success, otherwise returns a number that indicate the error
        if(pthread_create(&threadPool[i], NULL, startRoutine,id) != 0) 
        {
            // if failed to create, try to work with one less thread
            threads_number--;
        }

        statisticsThreadsInit(&(statisticsThreads[i]), *id);
    }

    listenfd = Open_listenfd(port);

    while (1) {
        clientlen = sizeof(clientaddr);
        //accept a new connection on a socket
        //returns non negative file descriptor of the accepted socket in case of success
        //returns -1 in case the function failed
        connfd = Accept(listenfd, (SA*)&clientaddr, (socklen_t*) &clientlen);
       // printf("the new connFD is : %d\n",connfd);
        if (connfd<0){
            perror("accept failed");
        }

        //get the current day and time and store it in arrival
        //returns 0 for success
        if(gettimeofday(&arrival, NULL) != 0){
            perror("getting time failed");
        }

        if (getQueueSize(queue) + get_count_active_threads() >= max_queue_size){

            if(schedAlgorithm(max_queue_size, connfd, full_queue)){
                continue;
            }
        }

        int* client = (int*)malloc(sizeof(int));

        if(client == NULL){
            perror("out of memory");
            return 0;
        }

        *client = connfd;
        if (!queuePush(queue, client, &arrival)){
            Close(connfd);
            free(client);
            continue;
        }
    }
}


// Usage of time_val substraction
static struct timeval timeval_subtract(struct timeval start, struct timeval end)
{
    struct timeval diff;

    if (start.tv_usec < end.tv_usec){
        int nsec = (end.tv_usec - start.tv_usec) / 1000000 + 1;
        end.tv_usec -= 1000000 * nsec;
        end.tv_sec += nsec;
    }

    if (start.tv_usec - end.tv_usec > 1000000){
        int nsec = (start.tv_usec - end.tv_usec) / 1000000;
        end.tv_usec += 1000000 * nsec;
        end.tv_sec -= nsec;
    }

    diff.tv_sec = start.tv_sec - end.tv_sec;
    diff.tv_usec = start.tv_usec - end.tv_usec;

    return diff;
}

void* startRoutine(void* id){
    
    StatThreads statThreads;
    statThreads.thread_id = *(int*)id;
    statThreads.count = 0;
    statThreads.static_count = 0;
    statThreads.dynamic_count = 0;
    while(1){
        int* current;
        struct timeval dispatch;
        
        current = queuePop(queue, &statThreads);
        gettimeofday(&dispatch, NULL);
        statThreads.dispatch = timeval_subtract(statThreads.arrival , dispatch);
        //(dispatch.tv_sec + (dispatch.tv_usec)/1.0e6) - statThreads.arrival;
        set_count_active_threads(count_active_threads + 1);

        if(current != NULL){
            requestHandle(*current, &statThreads);
            close(*current);
            free(current);
            set_count_active_threads(count_active_threads-1);
        }
    }
}


void block(){
//todo yael- fix this

}

void dropTail(int client){
    close(client);
}

bool dropHead(int* fd){
    if (getQueueSize(queue) == 0) {
        return true;
    }
    fd = queuePop(queue, NULL);
    close(*fd);
    free(fd);
    return false;
}

void dropRandom(){
    int to_remove = getQueueSize(queue)/4 + (getQueueSize(queue) % 4 != 0);
    int* tmp;

    while(to_remove)    {
        int random = rand()%to_remove;
        tmp = queueRemoveByIndex(queue, random);

        if(tmp){
            close(*tmp);
            free(tmp);
        }
        to_remove--;
    }
}

bool schedAlgorithm(int max_queue_size, int client,char* sched){
    int* fd = NULL;

    //for main thread the code block until a buffer becomes available
    if(!strcmp(sched,"block")){
        return false;
    }
    //drop the new request immediatly by closing the socket and continue listening for new requests
    else if(!strcmp(sched,"dt")){
        dropTail(client);
        return true;
    }
    //drop the oldest request in the queue that isn't currently being proccessed by
    //a thread and add the new request to the end of the queue
    else if(!strcmp(sched,"dh")){
        if (dropHead(fd)) {
            close(client); 
            return true;
        }
        return false;
    }
    //when the queue is full and a new request arrives, drop 1/4 of the requests in the queue that
    // aren't handled by a thread randomly
    else if(!strcmp(sched,"random")){
        dropRandom();
        return false;
    }

    return false;
}
