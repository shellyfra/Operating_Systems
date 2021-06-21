#include <unistd.h>

/* smalloc
● Tries to allocate ‘size’ bytes.
● Return value:
    i. Success –a pointer to the first allocated byte within the allocated block.
    ii. Failure –
        a. If ‘size’ is 0 returns NULL.
        b. If ‘size’ is more than 10^8 , return NULL.
        c. If sbrk fails, return NULL.
*/
const size_t SMALLOC_MAX_SIZE =100000000;
const int SBRK_FAILURE = -1;
void* smalloc(size_t size)
{
    if(size==0 || size > SMALLOC_MAX_SIZE)
    {
        return NULL;
    }
    void *block_ptr =sbrk(size);
    if(*((int*)block_ptr)==SBRK_FAILURE)
    {
        return NULL;
    }
    return block_ptr;
}
