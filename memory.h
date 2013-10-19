typedef struct
{
    int crc;
    int length;
    void* start;
} mem_block;

void memory_init(void);
void* mem_alloc(unsigned int size);
void mem_free(void* ptr);
void* mem_deref(void* ptr);
