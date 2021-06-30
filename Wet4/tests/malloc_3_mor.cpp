//TODO - PIAZZA : IF WE SPLIT IN REALLOC, DO WE MERGE NEXT FREE @615

#include <unistd.h>
#include <cstring>
#include <stdlib.h>
// #include <assert.h>
#include <sys/mman.h>

#define TRESHHOLD (100000000)
#define MMAP_SIZE (128 * 1024)
#define LAST_BIN_INDEX (127)

typedef struct MallocMetadata
{
    size_t size;
    bool is_free;
    MallocMetadata *next;        // in the memory layout
    MallocMetadata *prev;        // in the memory layout
    MallocMetadata *next_in_bin; // in the histogram if free
    MallocMetadata *prev_in_bin; // in the histogram if free
} MallocMetadata;

//global counters
static size_t numFreeBlocks = 0;
static size_t numAllocatedBlocks = 0;
static size_t numFreeBytes = 0;
static size_t numAllocatedBytes = 0;
static size_t numMetadataBytes = 0;
static size_t sizeMetadata = sizeof(MallocMetadata);

// list info
MallocMetadata *head = nullptr;
MallocMetadata *tail = nullptr;

// bins list
MallocMetadata *bins[128] = {nullptr};

static size_t findMin(size_t x, size_t y)
{
    if (x <= y)
    {
        return x;
    }
    return y;
}


static void AddToBin(MallocMetadata *p_metaData)
{
    int index_of_bin = (p_metaData->size == MMAP_SIZE) ? LAST_BIN_INDEX : p_metaData->size / 1024;
    MallocMetadata *iterator = bins[index_of_bin];
    MallocMetadata *prev_iterator = nullptr;

    // first
    if (iterator == nullptr)
    {
        bins[index_of_bin] = p_metaData;
        return;
    }

    // find the right spot in the list of the bin
    while (iterator != nullptr && iterator->size <= p_metaData->size)
    {
        prev_iterator = iterator;
        iterator = iterator->next_in_bin;
    }

    //now iterator holds place after the right one, prev before
    //and we should insert in between

    // not last
    if (iterator != nullptr)
    {
        iterator->prev_in_bin = p_metaData;
        if (iterator == bins[index_of_bin]) // first
        {
            bins[index_of_bin] = p_metaData;
        }
    }

    // not first
    if (prev_iterator != nullptr)
    {
        prev_iterator->next_in_bin = p_metaData;
    }
    p_metaData->prev_in_bin = prev_iterator;
    p_metaData->next_in_bin = iterator;
}


static void RemoveFromBin(MallocMetadata *iterator)
{
    int index_iterator = (iterator->size == MMAP_SIZE) ? LAST_BIN_INDEX : iterator->size / 1024;
    // remove from bins:
    if (bins[index_iterator] == iterator)
    {
        // first
        bins[index_iterator] = iterator->next_in_bin;
    }
    if (iterator->prev_in_bin != nullptr)
    {
        // not first
        iterator->prev_in_bin->next_in_bin = iterator->next_in_bin;
    }
    if (iterator->next_in_bin != nullptr)
    {
        // not last
        iterator->next_in_bin->prev_in_bin = iterator->prev_in_bin;
    }
    iterator->next_in_bin = nullptr;
    iterator->prev_in_bin = nullptr;
}

static MallocMetadata *FindAndRemoveFromBin(size_t size)
{
    int index_iterator = (size == MMAP_SIZE) ? LAST_BIN_INDEX : size / 1024;
    MallocMetadata *iterator = nullptr;
    for (; index_iterator < 128; index_iterator++)
    {
        if (bins[index_iterator] != nullptr)
        {
            // need to find the first slot bigger then size if exist
            iterator = bins[index_iterator];
            while (iterator != nullptr)
            {
                if (iterator->size >= size)
                {
                    RemoveFromBin(iterator);
                    return iterator;
                }
                iterator = iterator->next_in_bin;
            }
        }
    }
    return nullptr; // didnt find slot
}

// recives block>size and the gap is>128 :
// create new metadata for the split, add it to the list, add it to the bin
// update the empty slot to be not free and its new size which is exactly size needed!
// stats info will be updated by the calling func
static void splitSlot(MallocMetadata *empty_slot, size_t size)
{
    MallocMetadata *split_metaData = (MallocMetadata *)((char *)empty_slot + sizeMetadata + size); // TODO CHECK CALC
    split_metaData->is_free = true;

    // change list
    split_metaData->next = empty_slot->next;
    split_metaData->prev = empty_slot;
    if (empty_slot->next != nullptr)
    {
        empty_slot->next->prev = split_metaData;
    }
    else
    {
        tail = split_metaData;
    }
    empty_slot->next = split_metaData;

    // change new slot info
    split_metaData->size = empty_slot->size - sizeMetadata - size;
    split_metaData->next_in_bin = nullptr;
    split_metaData->prev_in_bin = nullptr;

    // change empty slot info
    empty_slot->size = size;
    empty_slot->is_free = false;

    // add to free bin
    AddToBin(split_metaData); // TODO what if bigger than 128kb
}

static void *mmap_allocation(size_t size)
{
    void *status = nullptr;
    status = mmap(NULL, (size + sizeMetadata), PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (status == (void *)-1)
    { //mmap failed
        return nullptr;
    }
    MallocMetadata *mmapMetadata = (MallocMetadata *)status;
    mmapMetadata->is_free = false;
    mmapMetadata->size = size;
    // for safty
    mmapMetadata->next = nullptr;
    mmapMetadata->prev = nullptr;
    mmapMetadata->next_in_bin = nullptr;
    mmapMetadata->prev_in_bin = nullptr;

    //set counters
    numMetadataBytes += sizeMetadata;
    numAllocatedBlocks++;
    numAllocatedBytes += size;

    return (mmapMetadata + 1);
}
static void mmap_deallocation(MallocMetadata *toFree)
{
    //set counters
    numAllocatedBlocks--;
    numAllocatedBytes -= toFree->size;
    numMetadataBytes -= sizeMetadata;

    munmap(toFree, toFree->size + sizeMetadata);
    return;
}

void *smalloc(size_t size)
{
    void *status = nullptr;
    if (size == 0 || size > TRESHHOLD)
    {
        return nullptr;
    }
    //mmap above 128kb
    if (size > MMAP_SIZE)
    {
        status = mmap_allocation(size);
        MallocMetadata *new_metaData = (MallocMetadata *)status;
        new_metaData--;
        return status;
    }

    //check if sbrk or use free block
    MallocMetadata *empty_slot = FindAndRemoveFromBin(size);
    if (empty_slot != nullptr)
    { // good slot
        empty_slot->is_free = false;

        if ((((unsigned long)empty_slot->size >= (unsigned long)size + (unsigned long)sizeMetadata)) &&
            (empty_slot->size - (size + sizeMetadata) >= 128))
        { // can split
            splitSlot(empty_slot, size);

            // change stats
            numFreeBytes = numFreeBytes - size - sizeMetadata;
            numAllocatedBlocks++;              // we created another empty block
            numAllocatedBytes -= sizeMetadata; // wasted for new slot meta data
            numMetadataBytes += sizeMetadata;
        }
        else
        { // leave it as is, can't split
            numFreeBlocks--;
            numFreeBytes -= empty_slot->size;
        }
        return (empty_slot + 1); //empty_slot + sizeMetadata
    }

    // check if tail is free and use it
    if (tail != nullptr && tail->is_free)
    {
        // assert(tail->size < size); //arrived here only if couldn't find free block big enough
        size_t gap_size = size - tail->size;
        status = sbrk(gap_size);
        if (*((int *)status) == -1)
        {
            return nullptr;
        }

        // set counters
        numFreeBlocks--;
        numFreeBytes -= tail->size;
        numAllocatedBytes += gap_size;

        // tail holds the block requested
        RemoveFromBin(tail);
        tail->size += gap_size;
        tail->is_free = false;

        return (tail + 1); //tail + sizeMetadata
    }

    //didn't find free block big enough - allocates space for block and its metadata
    status = sbrk(size + sizeMetadata); // gets old program break or fail
    if (*((int *)status) == -1)
        return nullptr;

    // fix list
    MallocMetadata *new_metaData = (MallocMetadata *)status;
    new_metaData->is_free = false;
    new_metaData->next = nullptr;
    new_metaData->size = size;
    new_metaData->next_in_bin = nullptr;
    new_metaData->prev_in_bin = nullptr;

    if (head == nullptr) // and also tail == nullptr
    {
        head = new_metaData;
        new_metaData->prev = nullptr;
    }
    else // not the first
    {
        new_metaData->prev = tail;
        if (tail != nullptr)
        {
            tail->next = new_metaData;
        }
    }
    tail = new_metaData;

    // set counters
    numAllocatedBlocks++;
    numAllocatedBytes += size;
    numMetadataBytes += sizeMetadata;
    return (new_metaData + 1); //status + sizeMetadata
}

void *scalloc(size_t num, size_t size)
{
    void *status = smalloc(num * size);
    if (status == nullptr)
    {
        return nullptr;
    }
    // the block was found / set by smalloc -> memset to 0 :
    memset(status, 0, num * size);
    return status;
}

void sfree(void *p)
{
    if (p == nullptr)
    {
        return;
    }
    MallocMetadata *p_metaData = (MallocMetadata *)p;
    p_metaData--;
    if (p_metaData->is_free)
    {
        return;
    }
    if (p_metaData->size > MMAP_SIZE)
    {
        // assert(!(p_metaData->is_free)); //mmap is always not free
        mmap_deallocation(p_metaData);
        return;
    }

    numFreeBytes += p_metaData->size;
    p_metaData->is_free = true;
    numFreeBlocks++;

    // need to release
    // check for adjacent free slots
    // next:
    if (p_metaData->next != nullptr && p_metaData->next->is_free == true)
    {
        // merge p with next
        RemoveFromBin(p_metaData->next);
        p_metaData->size = p_metaData->size + p_metaData->next->size + sizeMetadata;

        // fix list
        p_metaData->next = p_metaData->next->next;
        if (p_metaData->next != nullptr)
        {
            p_metaData->next->prev = p_metaData;
        }
        else
        {
            tail = p_metaData;
        }

        // fix counters
        numFreeBlocks--;
        numFreeBytes += sizeMetadata;
        numAllocatedBlocks--;
        numAllocatedBytes += sizeMetadata;
        numMetadataBytes -= sizeMetadata;
    }

    // prev:
    if (p_metaData->prev != nullptr && p_metaData->prev->is_free == true)
    {
        // merge p with prev
        RemoveFromBin(p_metaData->prev);
        p_metaData = p_metaData->prev;
        p_metaData->size = p_metaData->size + p_metaData->next->size + sizeMetadata;

        // fix list
        p_metaData->next = p_metaData->next->next;
        if (p_metaData->next != nullptr)
        {
            p_metaData->next->prev = p_metaData;
        }
        else
        {
            tail = p_metaData;
        }

        // fix counters
        numFreeBlocks--;
        numFreeBytes += sizeMetadata;
        numAllocatedBlocks--;
        numAllocatedBytes += sizeMetadata;
        numMetadataBytes -= sizeMetadata;
    }

    AddToBin(p_metaData); // TODO what if bigger than 128kb
}

void *srealloc(void *oldp, size_t size)
{
    if (size == 0 || size > TRESHHOLD)
    {
        return nullptr;
    }
    if (oldp == nullptr)
    {
        return (smalloc(size));
    }
    MallocMetadata *oldp_metaData = (MallocMetadata *)oldp;
    oldp_metaData--;
    // assert(oldp_metaData->is_free == false);

    //mmap realloc
    if (size > MMAP_SIZE)
    {
        void *status = smalloc(size); //does mmap and updates stats
        if (status == nullptr)
        {
            return nullptr;
        }
        MallocMetadata *mmapMetadata = (MallocMetadata *)status;
        ++mmapMetadata;
        size_t size_to_move = findMin(oldp_metaData->size, size);
        memmove(mmapMetadata, oldp, size_to_move);
        sfree(oldp); //does munmmap and updates stats
        return mmapMetadata;
    }

    // enough space as is :)
    if (oldp_metaData->size >= size)
    {
        // if so -> try to split
        bool gap_check_pos = ((unsigned long)oldp_metaData->size >= (unsigned long)size + (unsigned long)sizeMetadata);
        int gap_size = oldp_metaData->size - (size + sizeMetadata);
        if ((gap_check_pos == true) && gap_size >= 128)
        { // can split
            splitSlot(oldp_metaData, size);

            // change stats
            numFreeBlocks++;
            numFreeBytes += gap_size;
            numAllocatedBlocks++;
            numAllocatedBytes -= sizeMetadata;
            numMetadataBytes += sizeMetadata;
        }
        return oldp;
    }

    // try join prev
    MallocMetadata *prev_slot = oldp_metaData->prev;
    if (prev_slot != nullptr && prev_slot->is_free == true)
    {
        size_t slot_with_prev = oldp_metaData->prev->size + sizeMetadata + oldp_metaData->size;
        if (slot_with_prev >= size)
        { // join prev(remove oldp) -> memcpy -> try to split now

            RemoveFromBin(prev_slot);

            // fix stats:
            numFreeBlocks--;
            numFreeBytes -= prev_slot->size;
            numAllocatedBlocks--;
            numAllocatedBytes += sizeMetadata;
            numMetadataBytes -= sizeMetadata;

            prev_slot->size = slot_with_prev;
            prev_slot->is_free = false;

            // update list:
            prev_slot->next = oldp_metaData->next;
            if (oldp_metaData->next != nullptr)
            {
                oldp_metaData->next->prev = prev_slot;
            }
            else
            {
                tail = prev_slot;
            }

            // now its safe to memmove
            void *dest = (void *)(prev_slot + 1);
            memmove(dest, oldp, oldp_metaData->size);

            bool gap_check_pos = ((unsigned long)prev_slot->size >= (unsigned long)size + (unsigned long)sizeMetadata);
            if ((gap_check_pos == true) && (prev_slot->size - (size + sizeMetadata)) >= 128)
            { // can split
                splitSlot(prev_slot, size);

                // change stats
                numFreeBlocks++;
                numFreeBytes += prev_slot->next->size;
                numAllocatedBlocks++;              // we created another empty block
                numAllocatedBytes -= sizeMetadata; // wasted for new slot meta data
                numMetadataBytes += sizeMetadata;
            }
            return (prev_slot + 1); //prev_slot + sizeMetadata
        }
    }

    // try join next
    MallocMetadata *next_slot = oldp_metaData->next;
    if (next_slot != nullptr && next_slot->is_free == true)
    {
        size_t slot_with_next = oldp_metaData->next->size + sizeMetadata + oldp_metaData->size;
        if (slot_with_next >= size)
        { // join next(remove oldp) -> try to split now

            RemoveFromBin(next_slot);

            // fix stats:
            numFreeBlocks--;
            numFreeBytes -= next_slot->size;
            numAllocatedBlocks--;
            numAllocatedBytes += sizeMetadata;
            numMetadataBytes -= sizeMetadata;

            oldp_metaData->size = slot_with_next;

            // update list:
            oldp_metaData->next = next_slot->next;
            if (next_slot->next != nullptr)
            {
                next_slot->next->prev = oldp_metaData;
            }
            else
            {
                tail = oldp_metaData;
            }

            bool gap_check_pos = ((unsigned long)oldp_metaData->size >= (unsigned long)size + (unsigned long)sizeMetadata);
            if ((gap_check_pos == true) && (oldp_metaData->size - (size + sizeMetadata)) >= 128)
            { // can split
                splitSlot(oldp_metaData, size);

                // change stats
                numFreeBlocks++;
                numFreeBytes += oldp_metaData->next->size;
                numAllocatedBlocks++;              // we created another empty block
                numAllocatedBytes -= sizeMetadata; // wasted for new slot meta data
                numMetadataBytes += sizeMetadata;
            }
            return oldp; // now its bigger though
        }
    }

    // try with prev&next, maybe now :(
    if (prev_slot != nullptr && next_slot != nullptr && prev_slot->is_free && next_slot->is_free)
    {
        size_t slot_with_next_and_prev = oldp_metaData->prev->size + oldp_metaData->next->size + 2 * sizeMetadata + oldp_metaData->size;
        if (slot_with_next_and_prev >= size)
        {
            RemoveFromBin(prev_slot);
            RemoveFromBin(next_slot);

            // fix stats
            numFreeBlocks -= 2;
            numFreeBytes = numFreeBytes - next_slot->size - prev_slot->size;
            numAllocatedBlocks -= 2;
            numAllocatedBytes += 2 * sizeMetadata;
            numMetadataBytes -= 2 * sizeMetadata;

            prev_slot->size = slot_with_next_and_prev;
            prev_slot->is_free = false;

            // update list:
            prev_slot->next = next_slot->next;
            if (prev_slot->next != nullptr)
            {
                prev_slot->next->prev = prev_slot;
            }
            else
            {
                tail = prev_slot;
            }

            // now its safe to memmov
            void *dest = (void *)(prev_slot + 1);
            memmove(dest, oldp, oldp_metaData->size);
            bool gap_check_pos = ((unsigned long)prev_slot->size >= (unsigned long)size + (unsigned long)sizeMetadata);
            if ((gap_check_pos == true) && (prev_slot->size - (size + sizeMetadata)) >= 128)
            { // can split
                splitSlot(prev_slot, size);

                // change stats
                numFreeBlocks++;
                numFreeBytes += prev_slot->next->size;
                numAllocatedBlocks++;              // we created another empty block
                numAllocatedBytes -= sizeMetadata; // wasted for new slot meta data
                numMetadataBytes += sizeMetadata;
            }
            return (prev_slot + 1); //prev_slot + sizeMetadata
        }
    }

    // find or allocate room for size
    if (tail == oldp_metaData)
    {
        // make yourself useble for wilderness
        tail->is_free = true;
    }
    size_t oldp_orig_size = oldp_metaData->size;
    void *dest = smalloc(size);
    if (dest == nullptr)
    {
        return nullptr;
    }
    if (dest == (tail + 1) && (tail == oldp_metaData)) // used the tail
    { // malloc used wilderness
        // set counters back
        numFreeBlocks++;
        numFreeBytes += oldp_orig_size;
        return oldp;
    }
    else if (dest != (tail + 1) && (tail == oldp_metaData)){ // didnt use the tail
        tail->is_free = false;
    }
    // copy old p data to new allocation
    memmove(dest, oldp, oldp_metaData->size);
    // release old oldp
    sfree(oldp);
    return dest;
}

size_t _num_free_blocks()
{
    return numFreeBlocks;
}

size_t _num_free_bytes()
{
    return numFreeBytes;
}

size_t _num_allocated_blocks()
{
    return numAllocatedBlocks;
}

size_t _num_allocated_bytes()
{
    return numAllocatedBytes;
}

size_t _num_meta_data_bytes()
{
    return numMetadataBytes;
}

size_t _size_meta_data()
{
    return sizeMetadata;
}
