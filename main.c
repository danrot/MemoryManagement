#include <stdio.h>
#include "memory.h"

int main(int argc, char **argv) {
    int *values, i;
    mem_init();
    
    values = (int*) mem_alloc(sizeof(int) * 32);
    
    for (i = 0; i < 32; i++) {
        ((int*)mem_deref(values))[i] = i;
    }
    
    for (i = 0; i < 32; i++) {
        printf("%d\n", ((int*)mem_deref(values))[i]);
    }
    
    mem_free(values);
    
    return 0;
}
