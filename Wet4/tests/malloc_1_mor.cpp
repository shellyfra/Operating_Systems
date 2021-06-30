#include <unistd.h>
#define TRESHHOLD (100000000)

void* smalloc(size_t size){
    void *status = nullptr;
    if (size == 0 || size > TRESHHOLD)
        return nullptr;
    status = sbrk(size); // gets old program break or fail
    if(*((int*)status) == -1){
        return nullptr;
    } else{
        return status; // old program break
    }
}