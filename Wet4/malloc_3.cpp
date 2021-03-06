#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <iostream>

#include <iomanip>

#ifdef DEBUG
#define DO_IF_DEBUG(command)  \
    do                        \
    {                         \
        printf("Executing "); \
        printf(#command);     \
        printf("\n");         \
        command               \
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
    bool is_free;
    size_t block_size;
    //size_t real_size;
    MallocMetadata *next;
    MallocMetadata *prev;
    MallocMetadata *next_free;
    MallocMetadata *prev_free;
};
const unsigned short HISTOGRAM_BIN_COUNT = 128;
const unsigned short MIN_BLOCK_SIZE = 128;
const unsigned int MIN_MMAPED_SIZE = 128 * 1024;
const unsigned short HISTOGRAM_BIN_SIZE = 1024;
const size_t SMALLOC_MAX_SIZE = 100000000;
const int SBRK_FAILURE = -1;

MallocMetadata *bins_free[HISTOGRAM_BIN_COUNT];
//MallocMetadata *bins[HISTOGRAM_BIN_COUNT];
MallocMetadata *block_head = NULL;
size_t mmaped_size = 0;
size_t mmaped_blocks = 0;
//MallocMetadata * mmaped_head=NULL;
MallocMetadata *wilderness_chunk = NULL;

size_t _size_meta_data();
static MallocMetadata *_splitBlocks(MallocMetadata *free_block, size_t size);
static MallocMetadata *_getFreeBlock(const size_t &size);
static void _mergeAdjacentBlocks(MallocMetadata *block_metadata);
static void _mergeRightBlock(MallocMetadata *block_metadata);
static void _deleteFromHistogram(MallocMetadata *block_metadata);
static void _printNodesList(const char *func, size_t size);
static void _printNodesFreeList();
void *_metadataToPtr(MallocMetadata *metadata_block);
void _addToFreelist(MallocMetadata *freed_block);

static void _printNodesList(const char *func, size_t size)
{
    size_t count = 0;
    MallocMetadata *block_it = block_head;
    std::cout << "[" << func << " with size " << size << "] " << std::endl;
    while (block_it)
    {
        std::cout << "\t******* Node " << std::setw(4) << count << " *********"
                  << "\t-> ";
        block_it = block_it->next;
        count++;
    }
    std::cout << std::endl;
    block_it = block_head;
    while (block_it)
    {
        std::cout << "\t* block size = " << std::setw(10) << block_it->block_size << " *\t   ";
        block_it = block_it->next;
    }
    std::cout << std::endl;
    block_it = block_head;
    while (block_it)
    {
        std::cout << "\t* block free = " << std::setw(10) << block_it->is_free << " *\t   ";
        block_it = block_it->next;
    }
    std::cout << std::endl;
    block_it = block_head;
    while (block_it)
    {
        std::cout << "\t* block mmaped = " << std::setw(8) << block_it->is_mmaped << " *\t   ";
        block_it = block_it->next;
    }
    std::cout << std::endl;
    block_it = block_head;
    while (block_it)
    {
        unsigned short bin_index = block_it->block_size / HISTOGRAM_BIN_SIZE;
        if (bins_free[bin_index] == block_it)
        {
            std::cout << "\t* free_HEAD [" << std::setw(3) << bin_index << "]" << std::setw(14) << " *\t   ";
        }
        else
        {
            std::cout << "\t* " << std::setw(29) << " *\t   ";
        }
        block_it = block_it->next;
    }
    std::cout << std::endl;
    block_it = block_head;
    while (block_it)
    {
        if (block_it == wilderness_chunk)
        {
            std::cout << "\t* WILDERNESS" << std::setw(19) << " *\t   ";
        }
        else
        {
            std::cout << "\t* " << std::setw(29) << " *\t   ";
        }

        block_it = block_it->next;
    }
    std::cout << std::endl;
    block_it = block_head;
    while (block_it)
    {
        std::cout << "\t***************************"
                  << "\t   ";
        block_it = block_it->next;
    }

    std::cout << std::endl;
}

static void _printNodesFreeList()
{
    for (int i = 0; i < HISTOGRAM_BIN_COUNT; ++i)
    {
        MallocMetadata *block_it = bins_free[i];
        if (bins_free[i])
        {
            std::cout << "bins_free[" << i << "]" << std::endl;
            while (block_it)
            {
                std::cout << "block size = " << block_it->block_size << "\t -->   ";
                block_it = block_it->next_free;
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
static void _printDebugInfo(const char *func, size_t size)
{
    _printNodesList(func, size);
    _printNodesFreeList();
}

//size_t num_free_blocks=0;
MallocMetadata *_voidPtrToMetadata(void *p)
{
    return (MallocMetadata *)((char *)p - _size_meta_data());
}

void *_metadataToPtr(MallocMetadata *metadata_block)
{
    return (void *)((char *)metadata_block + _size_meta_data());
}

MallocMetadata *_splitBlocks(MallocMetadata *free_block, size_t size)
{
    size_t secondary_size = free_block->block_size - size - _size_meta_data();
    // TODO check
    //_deleteFromHistogram(free_block, false);
    // Need to split blocks
    // Calc new pointer to second block
    MallocMetadata *secondary_block_metadata_ptr = (MallocMetadata *)((char *)_metadataToPtr(free_block) + size);
    secondary_block_metadata_ptr->block_size = secondary_size;
    //secondary_block_metadata_ptr->real_size = 0;
    secondary_block_metadata_ptr->is_free = true;
    secondary_block_metadata_ptr->is_mmaped = false;
    secondary_block_metadata_ptr->next_free = NULL;
    secondary_block_metadata_ptr->prev_free = NULL;
    secondary_block_metadata_ptr->prev = free_block;
    secondary_block_metadata_ptr->next = free_block->next;
    if (free_block->next)
    {
        free_block->next->prev = secondary_block_metadata_ptr;
    }
    _addToFreelist(secondary_block_metadata_ptr);
    //_insertToHistrogram(secondary_size, secondary_block_metadata_ptr);

    free_block->block_size = size;
    free_block->next = secondary_block_metadata_ptr;
    free_block->next_free = NULL;
    free_block->prev_free = NULL;

    if (wilderness_chunk == free_block)
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
    MallocMetadata *block_it;
    while (bin_index < HISTOGRAM_BIN_COUNT)
    {
        block_it = bins_free[bin_index++];
        if (!block_it)
        {
            continue;
        }
        while (block_it && block_it->block_size < size)
        {
            block_it = block_it->next_free;
        }
        if (block_it && block_it->block_size >= size)
        {
            return block_it;
        }
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
    MallocMetadata *old_next = block_metadata->next;
    block_metadata->next = old_next->next;
    if (old_next->next)
    {
        old_next->next->prev = block_metadata;
    }
    block_metadata->block_size += old_next->block_size + _size_meta_data();
    // Now final block is larger, we'll need to re-insert the block to free list if it is free:
    if (block_metadata->is_free && old_next->is_free)
    {
        _addToFreelist(block_metadata);
    }
}
static void _mergeAdjacentBlocks(MallocMetadata *block_metadata)
{
    // Try mergin right
    if (block_metadata->next && block_metadata->next->is_free)
    {
        _mergeRightBlock(block_metadata);
    }
    // Try merging left
    if (block_metadata->prev && block_metadata->prev->is_free)
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

static void _deleteFromHistogram(MallocMetadata *block_metadata)
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
    MallocMetadata *prev_ptr = block_metadata->prev_free;
    MallocMetadata *next_ptr = block_metadata->next_free;

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

    if (histogram[bin_index] == block_metadata)
    {
        histogram[bin_index] = block_metadata->next_free;
    }
    if (prev_ptr)
    {
        MallocMetadata **to_change = &prev_ptr->next_free;
        *to_change = next_ptr;
    }
    if (next_ptr)
    {
        MallocMetadata **to_change = &next_ptr->prev_free;
        *to_change = prev_ptr;
    }
    block_metadata->next_free = NULL;
    block_metadata->prev_free = NULL;
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

void _trySplitBlock(MallocMetadata *free_block, size_t requested_size)
{

    size_t secondary_size = 0;
    if (free_block->block_size >= _size_meta_data() + requested_size)
    {
        secondary_size = free_block->block_size - requested_size - _size_meta_data();
    }

    _deleteFromHistogram(free_block);
    if (secondary_size >= MIN_BLOCK_SIZE)
    {
        _splitBlocks(free_block, requested_size);
        //  if(new_free_block->next && new_free_block->next->is_free)
        //  {
        // Relevant when reallocating
        //      _mergeRightBlock(new_free_block);
        //  }
    }
}
void *smalloc_mmap(size_t size)
{
    MallocMetadata *mmaped_ptr = (MallocMetadata *)mmap(NULL, size + _size_meta_data(),
                                                        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    if ((void *)mmaped_ptr == MAP_FAILED)
    {
        return NULL;
    }

    mmaped_ptr->next = NULL;
    mmaped_ptr->prev = NULL;
    //MallocMetadata* temp = mmaped_head;
    //mmaped_head = mmaped_ptr;
    //mmaped_ptr->next = temp;
    //if (temp) {
    //    temp->prev = mmaped_ptr;
    //}
    mmaped_ptr->is_mmaped = true;
    mmaped_ptr->block_size = size;
    //mmaped_ptr->real_size = size;
    mmaped_ptr->is_free = false;
    mmaped_ptr->next_free = NULL;
    mmaped_ptr->prev_free = NULL;
    mmaped_size += size;
    mmaped_blocks++;
    DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
    return _metadataToPtr(mmaped_ptr);
}
/* smalloc
??? Searches for a free block with up to ???size??? bytes or allocates (sbrk()) one if none are
found.
??? Return value:
    i. Success ??? returns pointer to the first byte in the allocated block (excluding the
    meta-data of course)
    ii. Failure ???
        a. If size is 0 returns NULL.
        b. If ???size??? is more than 10^8 , return NULL.
        c. If sbrk fails in allocating the needed space, return NULL.

*/
void *smalloc(size_t size)
{
    if (size == 0 || size > SMALLOC_MAX_SIZE)
    {
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return NULL;
    }
    if (size > MIN_MMAPED_SIZE)
    {
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return smalloc_mmap(size);
    }
    MallocMetadata *free_block = _getFreeBlock(size);

    if (!free_block)
    { // Call sbrk to allocate a new block

        size_t size_for_sbrk = size + _size_meta_data();
        bool wilderness_is_free = false;
        if (wilderness_chunk && wilderness_chunk->block_size <= HISTOGRAM_BIN_COUNT * HISTOGRAM_BIN_SIZE)
        {
            wilderness_is_free = wilderness_chunk->is_free;
            if (wilderness_is_free)
            {
                if (size > wilderness_chunk->block_size)
                {
                    size_for_sbrk = size - wilderness_chunk->block_size;
                    _deleteFromHistogram(wilderness_chunk);
                }
                else
                {                                                           // if wilderness_chunk  > size to allocate
                    MallocMetadata *temp_old_wilderness = wilderness_chunk; // save the start of the current block because wilderness will change
                    _trySplitBlock(wilderness_chunk, size);
                    DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
                    return _metadataToPtr(temp_old_wilderness);
                }
                //_deleteFromHistogram(wilderness_chunk,false);
            }
        }

        void *block_ptr = sbrk(size_for_sbrk);
        if (*((int *)block_ptr) == SBRK_FAILURE)
        {
            DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
            return NULL;
        }

        MallocMetadata *new_block_metadata_ptr = wilderness_is_free ? wilderness_chunk : (MallocMetadata *)block_ptr;
        //wilderness_chunk = new_block_metadata_ptr;
        new_block_metadata_ptr->block_size = size;
        //new_block_metadata_ptr->real_size = size;
        new_block_metadata_ptr->is_free = false;
        //_insertToHistrogram(size, new_block_metadata_ptr);

        if (!block_head)
        {
            block_head = new_block_metadata_ptr;
        }
        if (wilderness_chunk && !wilderness_is_free)
        {
            // Wilderness chunk was last one and not free
            wilderness_chunk->next = new_block_metadata_ptr;
            new_block_metadata_ptr->prev = wilderness_chunk;
        }

        wilderness_chunk = new_block_metadata_ptr;
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return _metadataToPtr(new_block_metadata_ptr);
    }
    else
    {
        // Found a free block with sufficient size
        // Delete it from the free lists histogram:

        //free_block->real_size = size;
        free_block->is_free = false;

        _trySplitBlock(free_block, size);
        //num_free_blocks--;
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return _metadataToPtr(free_block);
    }
}
/*
??? Searches for a free block of up to ???num??? elements, each ???size??? bytes that are all set to 0
or allocates if none are found. In other words, find/allocate size * num bytes and set all
bytes to 0.
??? Return value:
    i. Success - returns pointer to the first byte in the allocated block.
    ii. Failure ???
        a. If size is 0 returns NULL.
        b. If ???size * num??? is more than 10^8 , return NULL.
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
    // If it fails, block_ptr will be NULL
    DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
    return block_ptr;
}

void _addToFreelist(MallocMetadata *freed_block)
{
    // Add to free list and change pointers in histogram accordingly
    size_t freed_block_size = freed_block->block_size;
    unsigned short bin_index = freed_block_size / HISTOGRAM_BIN_SIZE;

    MallocMetadata *block_it = bins_free[bin_index];
    MallocMetadata *prev = NULL;
    if (!block_it)
    {
        // First block in bin
        freed_block->prev_free = NULL;
        freed_block->next_free = NULL;
        bins_free[bin_index] = freed_block;
        return;
    }
    while (block_it && block_it->block_size <= freed_block_size)
    {
        prev = block_it;
        block_it = block_it->next_free;
    }

    if (block_it)
    {
        block_it->prev_free = freed_block;
        if (block_it == bins_free[bin_index])
        {
            bins_free[bin_index] = freed_block;
        }
    }
    if (prev)
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
??? Releases the usage of the block that starts with the pointer ???p???.
??? If ???p??? is NULL or already released, simply returns.
??? Presume that all pointers ???p??? truly points to the beginning of an allocated block.
*/
void sfree(void *p)
{
    MallocMetadata *freed_block;
    //size_t size = _voidPtrToMetadata(p)->block_size; This will cause SEG fault if P is NULL
    if (!p || (freed_block = _voidPtrToMetadata(p))->is_free)
    {
        // Here we print size 0 since !p does not exist, therfore no size can be extracted
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, 0););
        return;
    }
    if (freed_block->is_mmaped)
    {
        //removeNode(freed_block);
        //if (freed_block == mmaped_head)
        //{
        //    mmaped_head = freed_block->next;
        //}

        size_t size_of_block = freed_block->block_size;
        int err = munmap((void *)_voidPtrToMetadata(p), freed_block->block_size + _size_meta_data());
        if (err != 0)
        {
            // TODO : check this case
            //std::cout << "munmap failed!!" << std::endl;
        }
        mmaped_size -= size_of_block;
        mmaped_blocks--;
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, _voidPtrToMetadata(p)->block_size););
        return;
    }
    //freed_block->real_size = 0;
    freed_block->is_free = true;

    _addToFreelist(freed_block);
    _mergeAdjacentBlocks(freed_block);
    DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, _voidPtrToMetadata(p)->block_size););
    //num_free_blocks++;
}
/*
??? If ???size??? is smaller than the current block???s size, reuses the same block. Otherwise,
finds/allocates ???size??? bytes for a new space, copies content of oldp into the new
allocated space and frees the oldp.
??? Return value:
    i. Success ???
        a. Returns pointer to the first byte in the (newly) allocated space.
        b. If ???oldp??? is NULL, allocates space for ???size??? bytes and returns a pointer to it.
    ii. Failure ???
        a. If size is 0 returns NULL.
        b. If ???size??? if more than 10^8 , return NULL.
        c. If sbrk fails in allocating the needed space, return NULL.
        d. Do not free ???oldp??? if srealloc() fails.

*/
void *srealloc(void *oldp, size_t size)
{
    if (size == 0 || size > SMALLOC_MAX_SIZE)
    {
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return NULL;
    }
    if (!oldp)
    {
        //b. If ???oldp??? is NULL, allocates space for ???size??? bytes and returns a pointer to it.
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return smalloc(size);
    }

    MallocMetadata *block_metadata_ptr = _voidPtrToMetadata(oldp);
    void *new_block_ptr = oldp;
    bool was_mapped = block_metadata_ptr->is_mmaped;
    size_t size_to_copy = block_metadata_ptr->block_size > size ? size : block_metadata_ptr->block_size;
    if (size > MIN_MMAPED_SIZE)
    {
        // Realloc with size larger than sbrk, so always allocate new ptr for this
        new_block_ptr = smalloc_mmap(size);
    }
    else if (size <= block_metadata_ptr->block_size)
    {
        // Old block is large enough to contain new size
        // NUm of free blocks doess not change
        
        // a. try use same block
        _trySplitBlock(block_metadata_ptr, size);
        block_metadata_ptr->is_free = false;
        DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
        return oldp;
    }
    else
    {
        // We need to find a new block

        bool mallocd = false;        
        // Try merging left

        size_t left_merge_size = block_metadata_ptr->block_size;
        left_merge_size += (block_metadata_ptr->prev && block_metadata_ptr->prev->is_free) ? block_metadata_ptr->prev->block_size + _size_meta_data() : 0;

        size_t right_merge_size = block_metadata_ptr->block_size;
        right_merge_size += (block_metadata_ptr->next && block_metadata_ptr->next->is_free) ? block_metadata_ptr->next->block_size + _size_meta_data() : 0;

        size_t adjacent_merge = left_merge_size + right_merge_size - block_metadata_ptr->block_size;

        //  bool mallocd = false;
        if (left_merge_size >= size)
        {
            // b. merge lower address
            new_block_ptr = _metadataToPtr(block_metadata_ptr->prev);
            _mergeRightBlock(block_metadata_ptr->prev);
            _trySplitBlock(_voidPtrToMetadata(new_block_ptr), size);
        }
        else if (right_merge_size >= size)
        {
            // c. merge higher address
            _mergeRightBlock(block_metadata_ptr);
            _trySplitBlock(block_metadata_ptr, size);
        }
        else if (adjacent_merge >= size)
        {
            // d. merge adjacent
            new_block_ptr = _metadataToPtr(block_metadata_ptr->prev);
            _mergeAdjacentBlocks(block_metadata_ptr);
            _trySplitBlock(_voidPtrToMetadata(new_block_ptr), size);
        }
        else
        {

            
            if (block_metadata_ptr == wilderness_chunk)
            {
                // Try enlarging wilderness
                size_t size_for_sbrk = size-wilderness_chunk->block_size;
                void *block_ptr = sbrk(size_for_sbrk);
                if (*((int *)block_ptr) == SBRK_FAILURE)
                {
                    DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
                    return NULL;
                }
                // We keep new_block_ptr
                wilderness_chunk->block_size = size;
                wilderness_chunk->is_free = false;
                return new_block_ptr;
            }
            else
            {
                // e. allocate new block
                mallocd = true;
                new_block_ptr = smalloc(size);
            }            
        }
        if (!new_block_ptr)
        {
            return NULL;
        }
        if (mallocd)
        {
            sfree(oldp);
        }
        // Found new block, copy content
    }

    if (new_block_ptr != oldp)
    {
        memmove(new_block_ptr, oldp, size_to_copy);
        if (was_mapped || _voidPtrToMetadata(new_block_ptr)->is_mmaped)
        {
            sfree(oldp);
        }
    }

    MallocMetadata *new_metadata = _voidPtrToMetadata(new_block_ptr);
    //new_metadata->real_size=size;
    new_metadata->is_free = false;

    //num_free_blocks--;
    DO_IF_DEBUG(_printDebugInfo(__FUNCTION__, size););
    return new_block_ptr;
}
/*
??? Returns the number of allocated blocks in the heap that are currently free.
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
??? Returns the number of bytes in all allocated blocks in the heap that are currently free,
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
??? Returns the overall (free and used) number of allocated blocks in the heap.
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

    return count + mmaped_blocks;
}

/*
??? Returns the overall number (free and used) of allocated bytes in the heap, excluding
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

    return count + mmaped_size;
}
/*
??? Returns the overall number of meta-data bytes currently in the heap.
*/
size_t _num_meta_data_bytes()
{

    return _num_allocated_blocks() * _size_meta_data();
}
/*
??? Returns the number of bytes of a single meta-data structure in your system.
*/
size_t _size_meta_data()
{
    return sizeof(MallocMetadata);
}