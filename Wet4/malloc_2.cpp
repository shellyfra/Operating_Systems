#include <unistd.h>
#include <string.h>

struct MallocMetadata
{
    size_t block_size;
    bool is_free;
    MallocMetadata* next;
    MallocMetadata* prev;
};
MallocMetadata * block_head=NULL;
static MallocMetadata * _getFreeBlock(const size_t &size,MallocMetadata ** prev_block)
{
    MallocMetadata* block_it = block_head;
    *prev_block=NULL;
    while (block_it)
    {
        if(block_it->is_free && block_it->block_size>=size)
        {
            break;
        }
        *prev_block =block_it;
        block_it = block_it->next;
    }
    return block_it;
}
/* smalloc
● Searches for a free block with up to ‘size’ bytes or allocates (sbrk()) one if none are
found.
● Return value:
    i. Success – returns pointer to the first byte in the allocated block (excluding the
    meta-data of course)
    ii. Failure –
        a. If size is 0 returns NULL.
        b. If ‘size’ is more than 10^8 , return NULL.
        c. If sbrk fails in allocating the needed space, return NULL.

*/
const size_t SMALLOC_MAX_SIZE =100000000;
const int SBRK_FAILURE = -1;
void *smalloc(size_t size)
{
    // TODO check if allocating in ascending order
    if (size == 0 || size > SMALLOC_MAX_SIZE)
    {
        return NULL;
    }
    MallocMetadata* prev_block;
    MallocMetadata* free_block = _getFreeBlock(size,&prev_block);

    if (!free_block)
    {   // Call sbrk
        void *block_ptr = sbrk(size+sizeof(MallocMetadata));
        if (*((int *)block_ptr) == SBRK_FAILURE)
        {
            return NULL;
        }
        
        MallocMetadata* new_block_metadata_ptr = (MallocMetadata*)block_ptr;        
        new_block_metadata_ptr->block_size =size;
        new_block_metadata_ptr->is_free=false;
        new_block_metadata_ptr->prev=prev_block;        
        if(prev_block)
        {

            prev_block->next = new_block_metadata_ptr;
        }
        else
        {   // This is the first node of the list
            block_head =new_block_metadata_ptr;
        }    
        return block_ptr+sizeof(MallocMetadata);    
    }
    else
    {
        // Found a free block with sufficient size
        free_block->is_free = false;
        return ((void *)free_block)+sizeof(MallocMetadata);    
    }
   
}
/*
● Searches for a free block of up to ‘num’ elements, each ‘size’ bytes that are all set to 0
or allocates if none are found. In other words, find/allocate size * num bytes and set all
bytes to 0.
● Return value:
    i. Success - returns pointer to the first byte in the allocated block.
    ii. Failure –
        a. If size is 0 returns NULL.
        b. If ‘size * num’ is more than 10^8 , return NULL.
        c. If sbrk fails in allocating the needed space, return NULL
*/
void* scalloc(size_t num, size_t size)
{
    void* block_ptr = smalloc(num*size);
    if(!block_ptr)
    {
        return NULL;
    }
    memset(block_ptr,0,num*size);
    return block_ptr;
}

/*
● Releases the usage of the block that starts with the pointer ‘p’.
● If ‘p’ is NULL or already released, simply returns.
● Presume that all pointers ‘p’ truly points to the beginning of an allocated block.
*/
void sfree(void* p)
{
    if (!p) 
    {
        return;
    }
    MallocMetadata * block_metadata_ptr =(MallocMetadata *)( p-sizeof(MallocMetadata));
    if (block_metadata_ptr->is_free)
    {
        return;
    }
    block_metadata_ptr->is_free = true;
}
/*
● If ‘size’ is smaller than the current block’s size, reuses the same block. Otherwise,
finds/allocates ‘size’ bytes for a new space, copies content of oldp into the new
allocated space and frees the oldp.
● Return value:
    i. Success –
        a. Returns pointer to the first byte in the (newly) allocated space.
        b. If ‘oldp’ is NULL, allocates space for ‘size’ bytes and returns a pointer to it.
    ii. Failure –
        a. If size is 0 returns NULL.
        b. If ‘size’ if more than 10^8 , return NULL.
        c. If sbrk fails in allocating the needed space, return NULL.
        d. Do not free ‘oldp’ if srealloc() fails.

*/
void* srealloc(void* oldp, size_t size)
{
    if (size == 0 || size > SMALLOC_MAX_SIZE)
    {
        return NULL;
    }
    if (!oldp) 
    {
        //b. If ‘oldp’ is NULL, allocates space for ‘size’ bytes and returns a pointer to it.
        return smalloc(size);
    }
    MallocMetadata * block_metadata_ptr =(MallocMetadata *)( oldp-sizeof(MallocMetadata));
    /*
    if (block_metadata_ptr->is_free) 
    {
        //what to do ?
        return NULL;
    }
    */
    if (size <= block_metadata_ptr->block_size)
    {
        return oldp;
    }
    // We need to find a new block
    void* new_block_ptr = smalloc(size);
    if(!new_block_ptr)
    {
        return NULL;
    }
    // Found new block, copy content
    memcpy(new_block_ptr,oldp,block_metadata_ptr->block_size);
    block_metadata_ptr->is_free=true;
    return new_block_ptr;
}
/*
● Returns the number of allocated blocks in the heap that are currently free.
*/
size_t _num_free_blocks()
{
    size_t count=0;
    MallocMetadata * block_it = block_head;
    while (block_it)
    {
        if(block_it->is_free)
        {
            count++;
        }
        block_it=block_it->next;
    }
    return count;
}

/*
● Returns the number of bytes in all allocated blocks in the heap that are currently free,
excluding the bytes used by the meta-data structs.
*/
size_t _num_free_bytes()
{
   size_t count=0;
    MallocMetadata * block_it = block_head;
    while (block_it)
    {
        if(block_it->is_free)
        {
            count+=block_it->block_size;
        }
        block_it=block_it->next;
    }
    return count;
}
/*
● Returns the overall (free and used) number of allocated blocks in the heap.
*/
size_t _num_allocated_blocks()
{
    size_t count = 0;
    MallocMetadata *block_it = block_head;
    while (block_it)
    {
        count++;
        block_it = block_it->next;
    }
    return count;
}

/*
● Returns the overall number (free and used) of allocated bytes in the heap, excluding
the bytes used by the meta-data structs.
*/
size_t _num_allocated_bytes()
{
    size_t count = 0;
    MallocMetadata *block_it = block_head;
    while (block_it)
    {
        count += block_it->block_size;
        block_it = block_it->next;
    }
    return count;
}
/*
● Returns the overall number of meta-data bytes currently in the heap.
*/
size_t _num_meta_data_bytes()
{
   
    return _num_allocated_blocks()*sizeof(MallocMetadata);
}
/*
● Returns the number of bytes of a single meta-data structure in your system.
*/
size_t _size_meta_data()
{
    return sizeof(MallocMetadata);
}