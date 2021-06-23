#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <iostream>

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
    bool is_mmaped;
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
const unsigned int MIN_MMAPED_SIZE = 128*1024;
const unsigned short HISTOGRAM_BIN_SIZE = 1024;
const size_t SMALLOC_MAX_SIZE = 100000000;
const int SBRK_FAILURE = -1;

MallocMetadata *bins_free[HISTOGRAM_BIN_COUNT];
MallocMetadata *bins[HISTOGRAM_BIN_COUNT];
MallocMetadata * block_head=NULL;
MallocMetadata * mmaped_head=NULL;
MallocMetadata * wilderness_chunk=NULL;

size_t _size_meta_data();
static void _splitBlocks(MallocMetadata* free_block,size_t size);
static MallocMetadata *_getFreeBlock(const size_t &size, MallocMetadata **prev_block);
static void _mergeAdjacentBlocks(MallocMetadata * block_metadata);
static void _mergeRightBlock(MallocMetadata *block_metadata);
static void _deleteFromHistogram(MallocMetadata * block_metadata,bool free_hist=true);
static void _insertToHistrogram(const size_t &size, MallocMetadata *new_block_metadata);
void * _metadataToPtr(MallocMetadata *metadata_block);

//size_t num_free_blocks=0;
static void _splitBlocks(MallocMetadata* free_block,size_t size)
{
     size_t secondary_size = free_block->block_size-size -_size_meta_data();
    _deleteFromHistogram(free_block, false);
    // Need to split blocks
    // Calc new pointer to second block
    MallocMetadata *secondary_block_metadata_ptr = (MallocMetadata *)((char *)free_block + size);
    secondary_block_metadata_ptr->block_size = secondary_size;
    secondary_block_metadata_ptr->real_size = 0;
    secondary_block_metadata_ptr->is_free = true;
    _insertToHistrogram(secondary_size, secondary_block_metadata_ptr);
    
    if(wilderness_chunk == free_block)
    {
        // Free block was wilderness, and now secondary is wilderness
        wilderness_chunk = secondary_block_metadata_ptr;
    }
    free_block->block_size = size;
    _insertToHistrogram(size, free_block);
}

static MallocMetadata *_getFreeBlock(const size_t &size)
{
    unsigned short bin_index = size / HISTOGRAM_BIN_SIZE;
    MallocMetadata *block_it = bins_free[bin_index];
    while (!block_it && bin_index<HISTOGRAM_BIN_COUNT )
    {
        // Fetch next bins block with larger size
        block_it =bins_free[++bin_index];
    }
    
    while (block_it && block_it->block_size < size)
    {            
        block_it = block_it->next_free;
    }
    return block_it;
}

static void _mergeRightBlock(MallocMetadata *block_metadata)
{
    // Should merge right block
    MallocMetadata *temp_next = block_metadata->next_free;
    if (wilderness_chunk == temp_next)
    {
        wilderness_chunk = block_metadata;
    }
    _deleteFromHistogram(temp_next);
    _deleteFromHistogram(temp_next, false);

    // Add the next block size and its metadata that was saved
    block_metadata->block_size += temp_next->block_size +_size_meta_data();

}
static void _mergeAdjacentBlocks(MallocMetadata * block_metadata)
{
    if(block_metadata->next_free && block_metadata->next_free == block_metadata->next)
    {
        _mergeRightBlock(block_metadata);
    }
    if(block_metadata->prev_free && block_metadata->prev_free == block_metadata->prev)
    {
        _mergeRightBlock(block_metadata->prev_free);
    }
    // Now final block is larger, we'll need to re-insert the block:
    // TODO add to free list again   
}

static void _deleteFromHistogram(MallocMetadata * block_metadata,bool free_hist)
{
    // Need maybe to update the free histogram
        MallocMetadata **histogram = free_hist ? bins_free : bins;
        unsigned short bin_index = block_metadata->block_size / HISTOGRAM_BIN_SIZE;
        MallocMetadata *bin_head = histogram[bin_index];
        MallocMetadata * prev_ptr = free_hist ? block_metadata->prev_free : block_metadata->prev;
        MallocMetadata * next_ptr = free_hist ? block_metadata->next_free : block_metadata->next;

        if(bin_head == block_metadata )
        {
            // Change head of the bin
            // Initialize head to NULL so that maybe the bin will be empty
            MallocMetadata* new_head=NULL;
            if(next_ptr && (next_ptr->block_size/ HISTOGRAM_BIN_SIZE == bin_index))
            {
                // Next free block is in the same bin range, make it the new head
                new_head = block_metadata->next_free;
            }
            histogram[bin_index] = new_head;
        }
        // Need to update free lists and next/prev free list pointer
        
 
        if(prev_ptr)
        {
            MallocMetadata ** to_change = free_hist ?  & prev_ptr->next_free :  & prev_ptr->next;
            *to_change = next_ptr;
        }
        if(next_ptr)
        {
            MallocMetadata ** to_change = free_hist ? & next_ptr->prev_free :  & next_ptr->prev;
            *to_change = prev_ptr;
        }

}
static void _insertToHistrogram(const size_t &size, MallocMetadata *new_block_metadata)
{
    // TODO if bins should be size with the meta data?
    unsigned short bin_index = size / HISTOGRAM_BIN_SIZE;
    short temp_bin_index = bin_index;
    MallocMetadata *block_it = bins[temp_bin_index];
    while (!block_it && temp_bin_index>=0 )
    {
        // Fetch next bins block with larger size
        block_it =bins[--temp_bin_index];
    }
    if(!block_it)
    {
        // if no node was found, take head
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
    
    MallocMetadata *free_block = _getFreeBlock(size);

    if (!free_block)
    { // Call sbrk to allocate a new block

        if(size>=MIN_MMAPED_SIZE)
        {
            MallocMetadata* mmaped_ptr = (MallocMetadata *)mmap( NULL, size + _size_meta_data(),
                                                                 PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
            if ((void*)mmaped_ptr == MAP_FAILED) {
                return NULL;
            }
            mmaped_ptr->next = NULL;
            mmaped_ptr->prev = NULL;
            MallocMetadata* temp = mmaped_head;
            mmaped_head = mmaped_ptr;
            mmaped_ptr->next = temp;
            if (temp) {
                temp->prev = mmaped_ptr;
            }
            mmaped_ptr->is_mmaped = true;
            mmaped_ptr->real_size = size;
            mmaped_ptr->is_free = false;
            mmaped_ptr->next_free = NULL;
            mmaped_ptr->prev_free = NULL;

            return _metadataToPtr(mmaped_ptr);
        }
        size_t size_for_sbrk=size + _size_meta_data();
        bool wilderness_is_free = false;
        if(wilderness_chunk)
        {
            wilderness_is_free = wilderness_chunk->is_free;
            if(wilderness_is_free)
            {
                size_for_sbrk = size - wilderness_chunk->block_size;
                _deleteFromHistogram(wilderness_chunk);
                _deleteFromHistogram(wilderness_chunk,false);
            }
        }
        
        void *block_ptr = sbrk(size_for_sbrk);
        if (*((int *)block_ptr) == SBRK_FAILURE)
        {
            return NULL;
        }

        MallocMetadata *new_block_metadata_ptr = wilderness_is_free ? wilderness_chunk : (MallocMetadata *)block_ptr;
        wilderness_chunk = new_block_metadata_ptr;
        new_block_metadata_ptr->block_size = size;
        new_block_metadata_ptr->real_size = size;
        new_block_metadata_ptr->is_free = false;        
        _insertToHistrogram(size, new_block_metadata_ptr);
        return _metadataToPtr(new_block_metadata_ptr);
    }
    else
    {
        // Found a free block with sufficient size     
        _deleteFromHistogram(free_block);    
        free_block->real_size = size;   
        free_block->is_free = false;

        size_t secondary_size = free_block->block_size-size -_size_meta_data();
        if(secondary_size >= MIN_BLOCK_SIZE)
        {
            _splitBlocks(free_block,size);
        }  
        //num_free_blocks--;
        
        return _metadataToPtr(free_block);
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

void removeNode(MallocMetadata *block_metadata_ptr)
{
        if (block_metadata_ptr-> prev)
        {
            block_metadata_ptr->prev->next = block_metadata_ptr->next;
        }
        if (block_metadata_ptr->next)
        {
            block_metadata_ptr->next->prev = block_metadata_ptr->prev;
        }
        
}
    MallocMetadata * _voidPtrToMetadata(void *p)
    {
        return (MallocMetadata *)((char *)p - _size_meta_data());
    }

    void * _metadataToPtr(MallocMetadata *metadata_block)
    {
        return (void *)((char *)metadata_block + _size_meta_data());
    }

/*
● Releases the usage of the block that starts with the pointer ‘p’.
● If ‘p’ is NULL or already released, simply returns.
● Presume that all pointers ‘p’ truly points to the beginning of an allocated block.
*/
void sfree(void *p)
{
    MallocMetadata *block_metadata_ptr;
    if (!p || (block_metadata_ptr = _voidPtrToMetadata(p))->is_free)
    {
        return;
    }
    if (block_metadata_ptr->is_mmaped)
    {
        removeNode(block_metadata_ptr);
        if (block_metadata_ptr == mmaped_head)
        {
            mmaped_head = block_metadata_ptr->next;
        }

        int err = munmap(p,block_metadata_ptr->block_size + _size_meta_data());
        if (err != 0)
        {
            // TODO : check this case
            std::cout << "munmap failed!!" << std::endl;
            
        }
        return;
    }
    block_metadata_ptr->real_size = 0;
    block_metadata_ptr->is_free = true;

    // Add to free list and change pointers in histogram accordingly
    size_t freed_block_size = block_metadata_ptr->block_size;
    unsigned short bin_index =  freed_block_size / HISTOGRAM_BIN_SIZE;
    if (bins_free[bin_index] == NULL || bins_free[bin_index]->block_size > freed_block_size)
    {
        bins_free[bin_index] = block_metadata_ptr;
    }

    // Update next free pointer
    MallocMetadata *block_it =block_metadata_ptr->next;
    while (block_it && !block_it->is_free)
    {
        block_it= block_it->next;
    }
    block_metadata_ptr->next_free = block_it;
    if (block_it)
    {
        block_it->prev_free = block_metadata_ptr;
    }

    // Update prev free pointer
    block_it = block_metadata_ptr->prev;
    while (block_it && !block_it->is_free)
    {
        block_it = block_it->prev;
    }
    block_metadata_ptr->prev_free = block_it;
    if (block_it)
    {
        block_it->next_free = block_metadata_ptr;
    }
    _mergeAdjacentBlocks(block_metadata_ptr);

    //num_free_blocks++;
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
    MallocMetadata *block_metadata_ptr = _voidPtrToMetadata(oldp);
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