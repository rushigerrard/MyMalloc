#include<stdio.h>
#include<stddef.h>

#define MAX_SIZE 10000

char memory[MAX_SIZE];

struct block{
	size_t size;
	int free;
	struct block *next;
};

typedef struct block block;
block *free_list = (void *) memory;

void initialize();
void split(block *fitting_slot, size_t size);
void *mymalloc(size_t no_of_bytes);
void merge();
void myfree(void* ptr);

