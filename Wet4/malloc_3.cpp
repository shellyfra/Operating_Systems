#include <unistd.h>
#include <string.h>

#ifdef DEBUG
#define DO_IF_DEBUG(command) \
    do                       \
    {                        \
        printf("Executing ");    \
        printf(#command);    \
        printf("\n");        \
        command              \
    } while (0)
#else
#define DO_IF_DEBUG(command)      \
    do                            \
    {                             \
        /* empty intentionally */ \
    } while (0)
#endif


struct MallocMetadata
{
    size_t block_size;
    size_t real_size;
    bool is_free;
    MallocMetadata *next;
    MallocMetadata *prev;
    MallocMetadata *next_free;
    MallocMetadata *prev_free;
};
const unsigned short HISTOGRAM_BIN_COUNT = 128;
const unsigned short MIN_BLOCK_SIZE = 128;
const unsigned short HISTOGRAM_BIN_SIZE = 1024;
const size_t SMALLOC_MAX_SIZE = 100000000;
const int SBRK_FAILURE = -1;

MallocMetadata *bins_free[HISTOGRAM_BIN_COUNT];
MallocMetadata *bins[HISTOGRAM_BIN_COUNT];
MallocMetadata * block_head=NULL;

size_t _size_meta_data();

//size_t num_free_blocks=0;
static MallocMetadata *_getFreeBlock(const size_t &size, MallocMetadata **prev_block)
{
    unsigned short bin_index = size / HISTOGRAM_BIN_SIZE;
    MallocMetadata *block_it = bins_free[bin_index];
    while (!block_it && bin_index<HISTOGRAM_BIN_COUNT )
    {
        // Fetch next bins block with larger size
        block_it =bins_free[++bin_index];
    }
    
    *prev_block = NULL;
    while (block_it)
    {
        if (block_it->block_size >= size)//block_it->is_free && block_it->block_size >= size)
        {
            return block_it;
        }
        *prev_block = block_it;
        block_it = block_it->next_free;
    }
    return block_it;
}

static void _deleteFromHistogram(MallocMetadata * block_metadata, MallocMetadata *histogram[HISTOGRAM_BIN_COUNT])
{
    // Need maybe to update the free histogram
        unsigned short bin_index = block_metadata->block_size / HISTOGRAM_BIN_SIZE;
        MallocMetadata *bin_head = histogram[bin_index];
        if(bin_head == block_metadata )
        {
            // Change head of the bin
            MallocMetadata* new_head=NULL;
            if(block_metadata->next_free && (block_metadata->next_free->block_size/ HISTOGRAM_BIN_SIZE == bin_index))
            {
                // Next free block is in the same bin range, make it the new head
                new_head = block_metadata->next_free;
            }
            histogram[bin_index] = new_head;
        }
        // Need to update free lists and next/prev free list pointer
        MallocMetadata * prev_free = block_metadata->prev_free;
        MallocMetadata * next_free = block_metadata->next_free;
        if(prev_free)
        {
            prev_free->next_free = next_free;
        }
        if(next_free)
        {
            next_free->prev_free = prev_free;
        }

}
static void _insertToHistrogram(const size_t &size, MallocMetadata *new_block_metadata)
{
    unsigned short bin_index = size / HISTOGRAM_BIN_SIZE;
    unsigned short temp_bin_index = bin_index;
    MallocMetadata *block_it = bins[temp_bin_index];
    while (!block_it && temp_bin_index>=0 )
    {
        // Fetch next bins block with larger size
        block_it =bins[--temp_bin_index];
    }
    if(!block_it)
    {
        block_it = block_head;
    }
   
    new_block_metadata->prev=NULL;
    new_block_metadata->prev_free=NULL;
    new_block_metadata->next=NULL;
    new_block_metadata->next_free=NULL;

    MallocMetadata *prev_block = NULL;
    while (block_it && block_it->block_size <= size)
    {  
        prev_block = block_it;
        block_it = block_it->next;
    }
    if(!prev_block)
    {
        // If prev block is NULL, this could happen if the first
        // block_it is larger than the current size, then try fetch
        // The previous block of block_it
        prev_block =  block_it? block_it->prev : NULL;
    }
    
    // block_it will be the first block that is larger than the current
    if (!prev_block)
    {
        // First block - we need to insert to the head of the list
        block_head = new_block_metadata;
    }
    else
    {
        // prev_block exists, so this is not the first node
        // Next node is saved in block_it
        prev_block->next = new_block_metadata;
    }
    new_block_metadata->next = block_it;
    new_block_metadata->prev = prev_block;
    if(block_it)
    {
        // We know block_it is the first that is larger than size
        // So the prev node of it should be the current block
        block_it->prev = new_block_metadata;
    }
    if(bins[bin_index] == NULL || bins[bin_index]->block_size > size)
    {
        bins[bin_index] = new_block_metadata;
    }
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

void *smalloc(size_t size)
{
    if (size == 0 || size > SMALLOC_MAX_SIZE)
    {
        return NULL;
    }
    MallocMetadata *prev_block;
    MallocMetadata *free_block = _getFreeBlock(size, &prev_block);

    if (!free_block)
    { // Call sbrk to allocate a new block
        void *block_ptr = sbrk(size + _size_meta_data());
        if (*((int *)block_ptr) == SBRK_FAILURE)
        {
            return NULL;
        }

        MallocMetadata *new_block_metadata_ptr = (MallocMetadata *)block_ptr;
        new_block_metadata_ptr->block_size = size;
        new_block_metadata_ptr->real_size = size;
        new_block_metadata_ptr->is_free = false;        
        _insertToHistrogram(size, new_block_metadata_ptr);
        return (void *)((char *)block_ptr + _size_meta_data());
    }
    else
    {
        // Found a free block with sufficient size     
        _deleteFromHistogram(free_block,bins_free);    


        size_t secondary_size = free_block->block_size-size -_size_meta_data();
        if(secondary_size >= MIN_BLOCK_SIZE)
        {
            _deleteFromHistogram(free_block,);
            // Need to split blocks
            // Calc new pointer to second block
            MallocMetadata *secondary_block_metadata_ptr = (MallocMetadata *)((char*)free_block+size);
            secondary_block_metadata_ptr->block_size = secondary_size;
            secondary_block_metadata_ptr->real_size = 0;
            secondary_block_metadata_ptr->is_free = true; 
             _insertToHistrogram(secondary_size,secondary_block_metadata_ptr);

            free_block->block_size - secondary_size +_size_meta_data();
            free_block->real_size = size;
            free_block->is_free = false;     
            _insertToHistrogram(size, free_block);
        }  
        //num_free_blocks--;
        
        return (void *)((char *)free_block + _size_meta_data());
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
void *scalloc(size_t num, size_t size)
{
    void *block_ptr = smalloc(num * size);
    if (!block_ptr)
    {
        return NULL;
    }
    memset(block_ptr, 0, num * size);
    return block_ptr;
}

/*
● Releases the usage of the block that starts with the pointer ‘p’.
● If ‘p’ is NULL or already released, simply returns.
● Presume that all pointers ‘p’ truly points to the beginning of an allocated block.
*/
void sfree(void *p)
{
    // TODO add challenge 2
    if (!p)
    {
        return;
    }
    MallocMetadata *block_metadata_ptr = (MallocMetadata *)((char *)p - _size_meta_data());
    if (block_metadata_ptr->is_free)
    {
        return;
    }
    //num_free_blocks++;
    block_metadata_ptr->real_size = 0;
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
void *srealloc(void *oldp, size_t size)
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
    MallocMetadata *block_metadata_ptr = (MallocMetadata *)((char *)oldp - _size_meta_data());
    if (size <= block_metadata_ptr->block_size)
    {
        // Old block is large enough to contain new size
        // NUm of free blocks doess not change
        block_metadata_ptr->real_size = size;
        return oldp;
    }
    // We need to find a new block
    void *new_block_ptr = smalloc(size);
    if (!new_block_ptr)
    {
        return NULL;
    }
    // Found new block, copy content
    memcpy(new_block_ptr, oldp, block_metadata_ptr->block_size);
    sfree(oldp);
    //num_free_blocks--;

    return new_block_ptr;
}
/*
● Returns the number of allocated blocks in the heap that are currently free.
*/
size_t _num_free_blocks()
{
    size_t count = 0;
    MallocMetadata *block_it = block_head;
    while (block_it)
    {
        if (block_it->is_free)
        {
            count++;
        }
        block_it = block_it->next;
    }
    return count;
}

/*
● Returns the number of bytes in all allocated blocks in the heap that are currently free,
excluding the bytes used by the meta-data structs.
*/
size_t _num_free_bytes()
{
    size_t count = 0;
    MallocMetadata *block_it = block_head;
    while (block_it)
    {
        if (block_it->is_free)
        {
            count += block_it->block_size;
        }
        else
        {
            count += (block_it->block_size - block_it->real_size);
        }
        block_it = block_it->next;
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

    return _num_allocated_blocks() * _size_meta_data();
}
/*
● Returns the number of bytes of a single meta-data structure in your system.
*/
size_t _size_meta_data()
{
    return sizeof(MallocMetadata);
}