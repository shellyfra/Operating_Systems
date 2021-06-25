
#include <unistd.h>

static const size_t MAX_SIZE = 100000000;

void* smalloc(size_t size) {
    if ((size == 0) || (size > MAX_SIZE)) {
        return NULL;
    }
    void * start_of_mem = sbrk(size);
    if (start_of_mem == (void *)-1) {
        return NULL;
    }
    return start_of_mem;
}
