#include <unistd.h>
#include <cstring>
#include <stdlib.h>

#define TRESHHOLD (100000000)

typedef struct MallocMetadata
{
    size_t size;
    bool is_free;
    MallocMetadata *next;
    MallocMetadata *prev;
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

void *smalloc(size_t size)
{
    void *status = nullptr;
    if (size == 0 || size > TRESHHOLD)
    {
        return nullptr;
    }

    //check if sbrk or use free block

    MallocMetadata *iterator = head;
    MallocMetadata *prev_iterator = nullptr;
    while (iterator != nullptr)
    { //run over all blocks, check if there is free one big enough
        if (iterator->is_free && iterator->size >= size)
        { // good slot
            iterator->is_free = false;
            numFreeBlocks--;
            numFreeBytes -= iterator->size;
            return ++iterator; //iterator + sizeMetadata
        }
        prev_iterator = iterator;
        iterator = iterator->next;
    }
    // prev holds now the last node of metadata
    //didn't find free block big enough - allocates space for block and its metadata
    status = sbrk(size + sizeMetadata); // gets old program break or fail
    if (*((int *)status) == -1)
        return nullptr;
    // fix list
    MallocMetadata *new_metaData = (MallocMetadata *)status;
    new_metaData->is_free = false;
    new_metaData->next = nullptr;
    new_metaData->size = size;

    if (head == nullptr)
    {
        head = new_metaData;
        head->prev = nullptr;
    }
    else
    {
        new_metaData->prev = prev_iterator;
        prev_iterator->next = new_metaData;
    }
    // set counters
    numAllocatedBlocks++;
    numAllocatedBytes += size;
    numMetadataBytes += sizeMetadata;
    return ++new_metaData; //status + sizeMetadata
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

    // need to release
    p_metaData->is_free = true;
    numFreeBlocks++;
    numFreeBytes += p_metaData->size;
}

void *srealloc(void *oldp, size_t size)
{
    if (size==0 || size > TRESHHOLD){
        return nullptr;
    }
    if(oldp==nullptr){
        return (smalloc(size));
    }
    MallocMetadata *oldp_metaData = (MallocMetadata *)oldp;
    oldp_metaData--;

    if (oldp_metaData->size >= size){
        return oldp;
    }

    // allocate room for size
    void *dest = smalloc(size);
    if (dest == nullptr)
    {
        return nullptr;
    }
    // copy old p data to new allocation
    memcpy(dest,oldp,oldp_metaData->size);
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
