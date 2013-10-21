#include "memory.h"

#define MEMORY_BLOCKS 128
#define MEMORY_SIZE 131072

static void* memory;
static void* current;
static mem_block blocks[MEMORY_BLOCKS];

static int find_block();

void mem_init(void) {
    int i;
    
    memory = malloc(MEMORY_SIZE);
    current = memory;
    
    for (i = 0; i < MEMORY_BLOCKS; i++) {
        blocks[i].crc = 0;
        blocks[i].length = 0;
        blocks[i].start = 0;
    }    
}

void* mem_alloc(unsigned int size) {
    int address = find_block();
    
    if (address != -1) {
        blocks[address].crc = 0;
        blocks[address].length = size;
        blocks[address].start = current;
        current += size;
    }
    
    return (void*) address;
}

void mem_free(void* ptr) {
    if ((int)ptr > 0) {
        blocks[(int)ptr].start = 0;
    }
}

void* mem_deref(void* ptr) {
    return blocks[(int)ptr].start;
}

static int find_block() {
    int i;
    for (i = 0; i < MEMORY_BLOCKS; i++) {
        if (!blocks[i].start) {
            return i;
        }
    }
    return -1;
}
