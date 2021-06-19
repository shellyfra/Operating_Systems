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
void* smalloc(size_t size)
{
    
    // TODO implement
    return NULL;
}
