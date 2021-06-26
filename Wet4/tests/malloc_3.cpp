

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

static const size_t MAX_SIZE = 100000000;
static const size_t _1KB = 1024;
static const size_t Threshold = 128;

struct MallocMetadata {
    size_t size;
    bool is_free;
    bool is_mmaped;
    MallocMetadata* next;
    MallocMetadata* prev;
    MallocMetadata* free_next;
    MallocMetadata* free_prev;
};

MallocMetadata * head_of_list = nullptr;
MallocMetadata * tail_of_list = nullptr;
MallocMetadata * tail_of_mmap_list = nullptr;

struct Statistics {
    size_t num_of_allocated_blocks;
    size_t num_of_free_blocks;
    size_t num_free_bytes;
    size_t num_allocated_bytes;
    size_t num_metadata_bytes;
    size_t size_of_metadata;
};

Statistics stats = {0, 0, 0, 0, 0, (unsigned int) sizeof(MallocMetadata)};


MallocMetadata * histogram[128] = {0}; // todo

void histogramRemove(MallocMetadata * node);
void histogramInsert(MallocMetadata * node);
void unFree(MallocMetadata * ptr);
MallocMetadata * MetadataInitialize(MallocMetadata * ptr, size_t size_plus_meta, MallocMetadata * next, MallocMetadata * prev);

size_t min(size_t size1, size_t size2) {
    return size1 <= size2 ? size1 : size2;
}

// Check if block allocated with mmap
bool isMmap(MallocMetadata * node) {
    return node->is_mmaped;
}

MallocMetadata * combine(MallocMetadata * first, MallocMetadata * second) {
    // Combine size to first block
    first->size += (second->size + stats.size_of_metadata);
    // Combined block's prev from first block and next from second block 
    first->next = second->next;
    if (second->next) {
        second->next->prev = first;
    }
    if (tail_of_list == second) {
        tail_of_list = first;
    }
    return first;
}

MallocMetadata * combineFreeStatistics(MallocMetadata * first, MallocMetadata * second) {
    // Combining 2 blocks means one less free block and one less allocated block
    stats.num_of_free_blocks--;
    stats.num_of_allocated_blocks--;     
    // We convert one of the metadata blocks into free bytes
    stats.num_metadata_bytes -= stats.size_of_metadata;
    stats.num_free_bytes += stats.size_of_metadata;
    stats.num_allocated_bytes += stats.size_of_metadata;
    return combine(first, second);
}

MallocMetadata * expandCombine(MallocMetadata * first, MallocMetadata * second) {
    stats.num_of_free_blocks--;
    stats.num_of_allocated_blocks--;
    stats.num_metadata_bytes -= stats.size_of_metadata;
    stats.num_allocated_bytes += stats.size_of_metadata;
    if (first->is_free) {
        stats.num_free_bytes -= first->size;
    } else {
        stats.num_free_bytes -= second->size;

    }
    MallocMetadata * node = combine(first, second);
    node->is_free = false;
    return node;
}

void combineFreeBlocks(MallocMetadata * node) {
    MallocMetadata * prev_node = node->prev;
    MallocMetadata * next_node = node->next;
    // If previous block exists and free (use of lazy evaluation)
    if (prev_node && prev_node->is_free) {
        unFree(prev_node);
        node = combineFreeStatistics(prev_node, node);
    }
    // If next block exists and free (use of lazy evaluation)
    if (next_node && next_node->is_free) {
        unFree(next_node);
        node = combineFreeStatistics(node, next_node);
    }
    node->is_free = true;
    histogramInsert(node);
}

int getBin(size_t size) {
    int bin = size / _1KB; //
    return bin > 127 ? 127 : bin;
}

void histogramInsert(MallocMetadata * node) {
    int bin = getBin(node->size);
    MallocMetadata *cur_node = histogram[bin];
    if (cur_node == nullptr) {
        histogram[bin] = node;
        return;
    } else if (node->size < cur_node->size) {
        histogram[bin] = node;
        node->free_next = cur_node;
        cur_node->free_prev = node;
        return;
    }
    while ((cur_node->size <= node->size) && (cur_node->free_next != nullptr)) {
        cur_node = cur_node->free_next;
    }
    if (cur_node->free_next || node->size < cur_node->size) {
        node->free_prev = cur_node->free_prev;
        node->free_next = cur_node;
        cur_node->free_prev->free_next = node;
        cur_node->free_prev = node;
    } else {
        node->free_prev = cur_node;
        node->free_next = nullptr;
        cur_node->free_next = node;
    }
}

void histogramRemove(MallocMetadata * node) {
    int bin = getBin(node->size);
    if (histogram[bin] == node) {
        MallocMetadata * next_node = node->free_next;
        histogram[bin] = next_node;
        if (next_node != nullptr) {
            next_node->free_prev = nullptr;
        }
    } else {
        MallocMetadata * next_node = node->free_next;
        MallocMetadata * prev_node = node->free_prev;
        prev_node->free_next = next_node;
        if (next_node != nullptr) {
            next_node->free_prev = prev_node;
        }
    }
    node->free_next = nullptr;
    node->free_prev = nullptr;
}

void unFree(MallocMetadata * ptr) {
    ptr->is_free = false;
    histogramRemove(ptr);
}

void * mmapAllocate(size_t size) {
    if (size > MAX_SIZE + stats.size_of_metadata) {
        return NULL;
    }
    void * allocated_memory = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (allocated_memory == MAP_FAILED) {
        return NULL;
    }
    return allocated_memory;
}

void* allocate(size_t size) {
    if ((size == 0) || (size > MAX_SIZE)) {
        return NULL;
    }
    void * start_of_mem = sbrk(size);
    if (start_of_mem == (void *)-1) {
        return NULL;
    }
    return start_of_mem;
}

void mallocStatsUpdate(size_t size) {
    // Number of blocks up by one
    stats.num_of_allocated_blocks++;
    // Number of allocated bytes up by (size)
    stats.num_allocated_bytes += size;
    // Number of metadata bytes up by (size of metadata)
    stats.num_metadata_bytes += stats.size_of_metadata;
}

void * useMmap(size_t size) {

    size_t size_plus_meta = size + stats.size_of_metadata;
    MallocMetadata * allocated_memory = (MallocMetadata*)mmapAllocate(size_plus_meta);
    if (allocated_memory == NULL) {
        return NULL;
    }

    MetadataInitialize(allocated_memory, size, nullptr, tail_of_mmap_list);
    allocated_memory->is_mmaped = true;
    // insert newly allocated node to mmap list
    if (tail_of_mmap_list) {
        // mmap list is not empty
        tail_of_mmap_list->next = allocated_memory;
        tail_of_mmap_list = allocated_memory;
    } 
    tail_of_mmap_list = allocated_memory;
    mallocStatsUpdate(size);
    return (void *) (allocated_memory + 1);
}

void mmap_free(MallocMetadata * node) {
    if (node == tail_of_mmap_list) {
        // Allocation is head of list
        tail_of_mmap_list = node->prev;
    }
    else {
        // Allocation not head of list
        node->next->next = node->prev;
    }

    // Update statistics
    stats.num_of_allocated_blocks--;
    stats.num_allocated_bytes -= node->size;
    stats.num_metadata_bytes -= stats.size_of_metadata;

    // Free mapping
    munmap(node - 1, 1);
}

MallocMetadata * MetadataInitialize(MallocMetadata * ptr, size_t size, MallocMetadata * next, MallocMetadata * prev) {
    ptr->size = size;
    ptr->is_free = false;
    ptr->prev = prev;
    ptr->next = next;
    ptr->free_next = nullptr;
    ptr->free_prev = nullptr;
    ptr->is_mmaped = false;
    return ptr;
}

MallocMetadata * setAndSplit(MallocMetadata *cur_node, size_t size) {
    bool is_cur_free = cur_node->is_free;
    cur_node->is_free = false;
    size_t remaining_bytes = cur_node->size - size;
    if (remaining_bytes < Threshold + stats.size_of_metadata) { // todo assuming size of metadata is excluded from the 128
        if (is_cur_free) {
            stats.num_of_free_blocks--;
            stats.num_free_bytes -= cur_node->size;
        }
        return cur_node;
    }
    cur_node->size = size;
    MallocMetadata * new_node = (MallocMetadata *)((char*)cur_node + size + stats.size_of_metadata);
    MetadataInitialize(new_node, remaining_bytes - stats.size_of_metadata, cur_node->next, cur_node);
    new_node->is_free = true;
    if (cur_node->next) {
        cur_node->next->prev = new_node;
    }
    cur_node->next = new_node;
    histogramInsert(new_node);
    stats.num_of_allocated_blocks++;
    stats.num_metadata_bytes += stats.size_of_metadata;
    stats.num_allocated_bytes -= stats.size_of_metadata;
    if (is_cur_free) {
        stats.num_free_bytes -= size + stats.size_of_metadata;
    } else {
        stats.num_of_free_blocks++;
        stats.num_free_bytes += (remaining_bytes - stats.size_of_metadata);
    }
    if (tail_of_list == cur_node) {
        tail_of_list = new_node;
    }
    return cur_node;
}

MallocMetadata * wildernessExpand(size_t size) {
    // Complete allocation request using Wilderness
    size_t bytes_to_allocate = (size - tail_of_list->size);
    MallocMetadata* ptr = (MallocMetadata*)allocate(bytes_to_allocate);
    if (ptr == NULL) {
        return NULL;
    }
    // tag Wilderness as not free and reflect in free statistics
    unFree(tail_of_list);
    stats.num_free_bytes -= tail_of_list->size;
    stats.num_of_free_blocks--;
    // We enlarge Wilderness block to requested size
    tail_of_list->size += bytes_to_allocate;
    // Number of allocated bytes up by (bytes to allocate)
    stats.num_allocated_bytes += bytes_to_allocate;
    return (tail_of_list + 1);
}

void* smalloc(size_t size) {
    if ((size == 0) || (size > MAX_SIZE)) {
        return NULL;
    }
    size_t size_plus_meta = size + stats.size_of_metadata;
    if (size >= Threshold * _1KB) {
        return useMmap(size);
    }
    int bin = getBin(size);; // todo to include metadata size?
    MallocMetadata * cur_node = histogram[bin];
    // search list for a free node of sufficient size if (cur_node != nullptr) {
    while ((bin < Threshold) && (!cur_node || cur_node->size < size)) {
        if (cur_node && cur_node->free_next) {
            cur_node = cur_node->free_next;
        } else {
            bin++;
            cur_node = histogram[bin];
        }
    }
    if ((bin < Threshold) && cur_node && (cur_node->size >= size)) {
        histogramRemove(cur_node);
        setAndSplit(cur_node, size);
        return (void *) (cur_node + 1);
    }
    // Check if Wilderness chunk is free
    if (tail_of_list && tail_of_list->is_free) {
        return (void*) wildernessExpand(size);
    }
    // Allocate brand new block
    MallocMetadata* ptr = (MallocMetadata*)allocate(size_plus_meta);
    if (ptr == NULL) {
        return NULL;
    }
    MetadataInitialize(ptr, size, nullptr, tail_of_list);
    // insert newly allocated node to list
    if (!head_of_list) {
        head_of_list = ptr;
        tail_of_list = ptr;
    } else {
        tail_of_list->next = ptr;
        ptr->prev = tail_of_list;
        tail_of_list = ptr;
    }
    mallocStatsUpdate(size);

    return (void *) (ptr + 1);
}

void* scalloc(size_t num, size_t size) {
    void* allocated_memory = smalloc(size * num);
    if (allocated_memory == NULL) {
        return NULL;
    }
    memset(allocated_memory, 0, num * size);
    return allocated_memory;
}

void sfree(void* p) {
    MallocMetadata * ptr = (MallocMetadata*) p;
    if ((ptr == NULL) || ((ptr - 1)->is_free)) {
        return;
    }
    if (isMmap(ptr - 1)) {
        mmap_free(ptr - 1);
        return;
    }
    (ptr - 1)->is_free = true;
    stats.num_of_free_blocks++;
    stats.num_free_bytes += (ptr - 1)->size;
    combineFreeBlocks(ptr - 1);
}

void* srealloc(void* oldp, size_t size) {
    // todo update this function
    if ((size == 0) || (size > MAX_SIZE)) {
        return NULL;
    }
    if (oldp == NULL) {
        return smalloc(size); // todo check if should take free block
    }
    MallocMetadata * ptr = ((MallocMetadata*) oldp - 1);
    if (ptr->size == size) {
        return oldp;
    }
    if (ptr->is_mmaped) {
        MallocMetadata * new_ptr = (MallocMetadata*) smalloc(size);
        memmove((void *)new_ptr, oldp, min(ptr->size, (new_ptr - 1)->size));
        sfree(oldp);
        return (void *)new_ptr;
    }
    if (ptr->size > size) {
        setAndSplit(ptr, size);
        return oldp;
    }
    MallocMetadata * combined;
    // try before
    if (ptr->prev && (ptr->prev->is_free) && (ptr->prev->size + ptr->size + stats.size_of_metadata >= size)) {
        histogramRemove(ptr->prev);
        return (void *) (setAndSplit(expandCombine(ptr->prev, ptr), size) + 1);
        // try after
    } else if (ptr->next && (ptr->next->is_free) && (ptr->next->size + ptr->size + stats.size_of_metadata >= size)) {
        histogramRemove(ptr->next);
        return (void *) (setAndSplit(expandCombine(ptr, ptr->next), size) + 1);
        // try both
    } else if (ptr->prev && ptr->next && (ptr->prev->is_free) && (ptr->next->is_free) &&
        (ptr->prev->size + ptr->next->size + ptr->size + (2 * stats.size_of_metadata) >= size)) {
        histogramRemove(ptr->prev);
        histogramRemove(ptr->next);
        return (void *) (setAndSplit(expandCombine(ptr->prev, expandCombine(ptr, ptr->next)), size) + 1);
    }
    if (ptr == tail_of_list) { // might use wilderness
        ptr->is_free = true;
        histogramInsert(ptr);
        stats.num_of_free_blocks++;
        stats.num_free_bytes += ptr->size;
    }
    MallocMetadata * new_ptr = (MallocMetadata*) smalloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }
    memmove((void *)new_ptr, oldp, ptr->size);
    if (ptr == tail_of_list && ptr != (new_ptr - 1)) {
        unFree(ptr);
        stats.num_of_free_blocks--;
        stats.num_free_bytes -= ptr->size;
    }
    if (ptr != (new_ptr - 1)) {
        sfree(oldp);
    }
    return (void *)new_ptr;
}

size_t _num_free_blocks() {
    return stats.num_of_free_blocks;
}

size_t _num_free_bytes() {
    return stats.num_free_bytes;
}

size_t _num_allocated_blocks() {
    return stats.num_of_allocated_blocks;
}

size_t _num_allocated_bytes() {
    return stats.num_allocated_bytes;
}

size_t _num_meta_data_bytes() {
    return stats.num_metadata_bytes;
}

size_t _size_meta_data() {
    return stats.size_of_metadata;
}


