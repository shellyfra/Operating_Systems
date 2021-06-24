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
//MallocMetadata *bins[HISTOGRAM_BIN_COUNT];
MallocMetadata * block_head=NULL;
MallocMetadata * mmaped_head=NULL;
MallocMetadata * wilderness_chunk=NULL;

size_t _size_meta_data();
static MallocMetadata*  _splitBlocks(MallocMetadata* free_block,size_t size);
static MallocMetadata *_getFreeBlock(const size_t &size, MallocMetadata **prev_block);
static void _mergeAdjacentBlocks(MallocMetadata * block_metadata);
static void _mergeRightBlock(MallocMetadata *block_metadata);
static void _deleteFromHistogram(MallocMetadata * block_metadata);
static void _insertToHistrogram(const size_t &size, MallocMetadata *new_block_metadata);
void * _metadataToPtr(MallocMetadata *metadata_block);
void _addToFreelist(MallocMetadata *freed_block);

//size_t num_free_blocks=0;
MallocMetadata* _splitBlocks(MallocMetadata* free_block,size_t size)
{
     size_t secondary_size = free_block->block_size-size -_size_meta_data();
     // TODO check
    //_deleteFromHistogram(free_block, false);
    // Need to split blocks
    // Calc new pointer to second block
    MallocMetadata *secondary_block_metadata_ptr = (MallocMetadata *)((char *)free_block + size);
    secondary_block_metadata_ptr->block_size = secondary_size;
    secondary_block_metadata_ptr->real_size = 0;
    secondary_block_metadata_ptr->is_free = true;
    
    // The secondary block is free
    secondary_block_metadata_ptr->prev = free_block;
    secondary_block_metadata_ptr->next = free_block->next;
    _addToFreelist(secondary_block_metadata_ptr);    
    //_insertToHistrogram(secondary_size, secondary_block_metadata_ptr);
    
    
    free_block->block_size = size;
    free_block->next = secondary_block_metadata_ptr;
    free_block->next_free = NULL;
    free_block->prev_free = NULL;

    
    if(wilderness_chunk == free_block)
    {
        // Free block was wilderness, and now secondary is wilderness
        wilderness_chunk = secondary_block_metadata_ptr;
    }
    //_insertToHistrogram(size, free_block);
    return secondary_block_metadata_ptr;
}

static MallocMetadata *_getFreeBlock(const size_t &size)
{
    unsigned short bin_index = size / HISTOGRAM_BIN_SIZE;
    MallocMetadata *block_it = bins_free[bin_index];
    while (!block_it && bin_index<HISTOGRAM_BIN_COUNT )
    {
        // Fetch next bins block with larger size
        block_it =bins_free[bin_index++];
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
    _deleteFromHistogram(block_metadata);
    _deleteFromHistogram(block_metadata->next);
    
    if (wilderness_chunk == block_metadata->next)
    {
        wilderness_chunk = block_metadata;
    }
    
    //_deleteFromHistogram(temp_next, false);

    // Add the next block size and its metadata that was saved
    MallocMetadata* old_next =  block_metadata->next;
    block_metadata->next = old_next->next;
    if(old_next->next)
    {
        old_next->next->prev = block_metadata;
    }
    block_metadata->block_size += old_next->block_size +_size_meta_data();
    // Now final block is larger, we'll need to re-insert the block to free list if it is free:
    if(block_metadata->is_free && old_next->is_free)
    {
        _addToFreelist(block_metadata);
    }
    

}
static void _mergeAdjacentBlocks(MallocMetadata * block_metadata)
{
    // Try mergin right
    if(block_metadata->next && block_metadata->next->is_free)
    {
        _mergeRightBlock(block_metadata);
    }
    // Try merging left
    if(block_metadata->prev && block_metadata->prev->is_free)
    {
        _mergeRightBlock(block_metadata->prev);
    }
    
    
}
/*
static void _deleteFromHistogram(MallocMetadata * block_metadata,bool free_hist)
{
    // Need maybe to update the free histogram
        MallocMetadata **histogram = free_hist ? bins_free : bins;
        unsigned short bin_index = block_metadata->block_size / HISTOGRAM_BIN_SIZE;
        MallocMetadata *bin_head = histogram[bin_index];
        MallocMetadata * prev_ptr = free_hist ? block_metadata->prev_free : block_metadata->prev;
        MallocMetadata * next_ptr = free_hist ? block_metadata->next_free : block_metadata->next;

        if(!free_hist && bin_head == block_metadata )
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
*/

static void _deleteFromHistogram(MallocMetadata * block_metadata)
{
    /*
    if(!block_metadata->is_free)
    {
        // It is not present in the free lists
        return;
    }
    */
    // Need maybe to update the free histogram
        MallocMetadata **histogram = bins_free;
        unsigned short bin_index = block_metadata->block_size / HISTOGRAM_BIN_SIZE;
        MallocMetadata *bin_head = histogram[bin_index];
        MallocMetadata * prev_ptr =  block_metadata->prev_free;
        MallocMetadata * next_ptr =  block_metadata->next_free;

        /* HEAD will never change!
        if(!free_hist && bin_head == block_metadata )
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
        */
        // Need to update free lists and next/prev free list pointer
        
        if( histogram[bin_index] == block_metadata)
        {
            histogram[bin_index] = block_metadata->next_free;
        }
        if(prev_ptr)
        {
            MallocMetadata ** to_change =   & prev_ptr->next_free ;
            *to_change = next_ptr;
        }
        if(next_ptr)
        {
            MallocMetadata ** to_change =  & next_ptr->prev_free ;
            *to_change = prev_ptr;
        }

}
/*
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
*/
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
void _trySplitBlock(MallocMetadata *free_block , size_t requested_size)
{
    
        size_t secondary_size = 0;
        if  (free_block->block_size >=_size_meta_data() +requested_size)
        {
            secondary_size = free_block->block_size-requested_size -_size_meta_data();
        }
        

        _deleteFromHistogram(free_block);    
        if(secondary_size >= MIN_BLOCK_SIZE)
        {
            MallocMetadata* new_free_block =  _splitBlocks(free_block,requested_size);
          //  if(new_free_block->next && new_free_block->next->is_free)
          //  {
                // Relevant when reallocating
          //      _mergeRightBlock(new_free_block);
          //  }
        }  
}
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
                //_deleteFromHistogram(wilderness_chunk,false);
            }
        }
        
        void *block_ptr = sbrk(size_for_sbrk);
        if (*((int *)block_ptr) == SBRK_FAILURE)
        {
            return NULL;
        }

        MallocMetadata *new_block_metadata_ptr = wilderness_is_free ? wilderness_chunk : (MallocMetadata *)block_ptr;
        //wilderness_chunk = new_block_metadata_ptr;
        new_block_metadata_ptr->block_size = size;
        new_block_metadata_ptr->real_size = size;
        new_block_metadata_ptr->is_free = false;        
        //_insertToHistrogram(size, new_block_metadata_ptr);

        if(!block_head)
        {
            block_head =new_block_metadata_ptr;
        }
        if(wilderness_chunk && !wilderness_is_free)
        {   
            // Wilderness chunk was last one and not free
            wilderness_chunk->next = new_block_metadata_ptr;
            new_block_metadata_ptr->prev = wilderness_chunk;
        }
        
        wilderness_chunk =new_block_metadata_ptr;
        return _metadataToPtr(new_block_metadata_ptr);
    }
    else
    {
        // Found a free block with sufficient size
        // Delete it from the free lists histogram:
        
        free_block->real_size = size;   
        free_block->is_free = false;
        
        _trySplitBlock(free_block,size);
        
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
void _addToFreelist(MallocMetadata *freed_block)
{
// Add to free list and change pointers in histogram accordingly
    size_t freed_block_size = freed_block->block_size;
    unsigned short bin_index =  freed_block_size / HISTOGRAM_BIN_SIZE;

    MallocMetadata* block_it = bins_free[bin_index];
    MallocMetadata* prev = NULL;
    if(!block_it)
    {
        // First block in bin
        bins_free[bin_index] = freed_block;
        return;
    }
    while (block_it  && block_it->block_size <= freed_block_size)
    {
        prev=block_it;
        block_it=block_it->next_free;
    }

if(block_it)
{
    block_it->prev_free = freed_block;
}
     if(prev)
     {
         prev->next_free = freed_block;
     }
     freed_block->prev_free = prev;
     freed_block->next_free = block_it;
    /*
    // Update next free pointer
    MallocMetadata *block_it =freed_block->next;
    while (block_it && !block_it->is_free)
    {
        block_it= block_it->next;
    }
    freed_block->next_free = block_it;
    if (block_it)
    {
        block_it->prev_free = freed_block;
    }

    // Update prev free pointer
    block_it = freed_block->prev;
    while (block_it && !block_it->is_free)
    {
        block_it = block_it->prev;
    }
    freed_block->prev_free = block_it;
    if (block_it)
    {
        block_it->next_free = freed_block;
    }
    */
}
/*
● Releases the usage of the block that starts with the pointer ‘p’.
● If ‘p’ is NULL or already released, simply returns.
● Presume that all pointers ‘p’ truly points to the beginning of an allocated block.
*/
void sfree(void *p)
{
    MallocMetadata *freed_block;
    if (!p || (freed_block = _voidPtrToMetadata(p))->is_free)
    {
        return;
    }
    if (freed_block->is_mmaped)
    {
        removeNode(freed_block);
        if (freed_block == mmaped_head)
        {
            mmaped_head = freed_block->next;
        }

        int err = munmap(p,freed_block->block_size + _size_meta_data());
        if (err != 0)
        {
            // TODO : check this case
            std::cout << "munmap failed!!" << std::endl;
            
        }
        return;
    }
    freed_block->real_size = 0;
    freed_block->is_free = true;

    _addToFreelist(freed_block);
    _mergeAdjacentBlocks(freed_block);

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
        _trySplitBlock(block_metadata_ptr,size);
        return oldp;
    }

    // We need to find a new block
    void *new_block_ptr=oldp;
    bool mallocd=false;
    bool was_wilderness=false;
    // Try merging left
    
    size_t left_merge_size = block_metadata_ptr->block_size;
    left_merge_size+= (block_metadata_ptr->prev &&  block_metadata_ptr->prev->is_free ) ? block_metadata_ptr->prev->block_size+_size_meta_data() : 0;

    size_t right_merge_size = block_metadata_ptr->block_size;
    right_merge_size+= (block_metadata_ptr->next &&  block_metadata_ptr->next->is_free ) ? block_metadata_ptr->next->block_size+_size_meta_data() : 0;

    size_t adjacent_merge = left_merge_size+right_merge_size - block_metadata_ptr->block_size;

  //  bool mallocd = false;
    if(left_merge_size>=size)
    {
        new_block_ptr =_metadataToPtr(block_metadata_ptr->prev);
        _mergeRightBlock(block_metadata_ptr->prev);
        _trySplitBlock(block_metadata_ptr,size);
    }
    else if(right_merge_size>=size)
    {
        _mergeRightBlock(block_metadata_ptr);
        _trySplitBlock(block_metadata_ptr,size);
    }
    else if (adjacent_merge >= size)
    {
        new_block_ptr = _metadataToPtr(block_metadata_ptr->prev);
        _mergeAdjacentBlocks(block_metadata_ptr);
        _trySplitBlock(block_metadata_ptr, size);
    }
    else
    {
        mallocd = true;
        if (block_metadata_ptr == wilderness_chunk)
        {
            was_wilderness=true;
            wilderness_chunk->is_free = true;
        }
        new_block_ptr = smalloc(size);
    }
    if (!new_block_ptr)
    {
        
        return NULL;
    }
    if(mallocd && !was_wilderness)
    {
        sfree(oldp);
    }
    // Found new block, copy content
    if(new_block_ptr != oldp)
    {
        memcpy(new_block_ptr, oldp, block_metadata_ptr->block_size);
    }
    
    MallocMetadata *new_metadata =_voidPtrToMetadata(new_block_ptr);
    new_metadata->real_size=size;
    new_metadata->is_free=false;

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