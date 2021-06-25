
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static const size_t MAX_SIZE = 100000000;

struct MallocMetadata {
    size_t size;
    bool is_free;
    MallocMetadata* next;
    MallocMetadata* prev;
};

MallocMetadata * head_of_list;

struct Statistics {
    size_t num_of_allocated_blocks;
    size_t num_of_free_blocks;
    size_t num_free_bytes;
    size_t num_allocated_bytes;
    size_t num_metadata_bytes;
    size_t size_of_metadata;
};

Statistics stats = {0, 0, 0, 0, 0, (unsigned int) sizeof(MallocMetadata)};

void* allocate(size_t size) {
    if ((size == 0) || (size > MAX_SIZE + stats.size_of_metadata)) {
        return NULL;
    }
    void * start_of_mem = sbrk(size);
    if (start_of_mem == (void *)-1) {
        return NULL;
    }
    return start_of_mem;
}

void* smalloc(size_t size) {
    if ((size == 0) || (size > MAX_SIZE)) {
        return NULL;
    }
    MallocMetadata * cur_node = head_of_list;
    size_t size_plus_meta = size + stats.size_of_metadata;
    if (cur_node != nullptr) {
        while ((!(cur_node->is_free) || (cur_node->size < size)) && (cur_node->next != nullptr)) {
            cur_node = cur_node->next;
        }
        if ((cur_node->is_free) && (cur_node->size >= size)) {
            cur_node->is_free = false;
            // Number of free blocks down by one 
            stats.num_of_free_blocks--;
            // Number of free bytes down by size of free block found (without metadata)
            stats.num_free_bytes -= cur_node->size;
            return (void *) (cur_node + 1);
        }
    }
    MallocMetadata* ptr = (MallocMetadata*)allocate(size_plus_meta);
    if (ptr == NULL) {
        return NULL;
    }
    ptr->size = size;
    ptr->is_free = false;
    ptr->prev = cur_node;
    ptr->next = nullptr;
    if (cur_node != nullptr) {
        cur_node->next = ptr;
    } else {
        head_of_list = ptr;
    }
    // Number of blocks up by one
    stats.num_of_allocated_blocks++;
    // Number of allocated bytes up by (size) 
    stats.num_allocated_bytes += size;
    // Number of metadata bytes up by (size of metadata)
    stats.num_metadata_bytes += stats.size_of_metadata;
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
    (ptr - 1)->is_free = true;
    stats.num_of_free_blocks++;
    stats.num_free_bytes += (ptr - 1)->size;
}

void* srealloc(void* oldp, size_t size) {
    if ((size == 0) || (size > MAX_SIZE)) {
        return NULL;
    }
    if (oldp == NULL) {
        return smalloc(size); // todo check if should take free block
    }
    MallocMetadata * ptr = ((MallocMetadata*) oldp - 1);
    size_t size_plus_meta = size + stats.size_of_metadata;
    if (ptr->size >= size) {
        return oldp;
    }
    MallocMetadata * new_ptr = (MallocMetadata*) smalloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }
    memcpy((void *)new_ptr, oldp, ptr->size);
    sfree(oldp);
    return (void *) new_ptr;
}

size_t _num_free_blocks() {
    return stats.num_of_free_blocks;
}

size_t _num_free_bytes() {
    return stats.num_free_bytes;
}

size_t _num_allocated_blocks(){
    return stats.num_of_allocated_blocks;
}

size_t _num_allocated_bytes(){
    return stats.num_allocated_bytes;
}

size_t _num_meta_data_bytes(){
    return stats.num_metadata_bytes;
}

size_t _size_meta_data(){
    return stats.size_of_metadata;
}
