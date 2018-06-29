#include<stdio.h>
#include<stddef.h>
#include"mymalloc.h"

void initialize(){
	printf("Memory initialized\n");
	printf("Total memory available is : %d\n",MAX_SIZE);
	printf("Starting address is  %d\n",free_list);
	free_list->size = MAX_SIZE - sizeof(struct block);
	free_list->free = 1;
	free_list->next = NULL;
}

void split(block *fitting_slot, size_t size){
	printf("Split the existing block\n");
	block *new = (void *)((void *)fitting_slot + size + sizeof(block));
	new->size = (fitting_slot->size) - size - sizeof(block);
	new->free = 1;
	new->next = fitting_slot->next;
	fitting_slot->size = size;
	fitting_slot->free = 0;
	fitting_slot->next = new;
	printf("Current block will have address : %d\n",fitting_slot);
	printf("Next block will have address : %d\n",new);
}

void *mymalloc(size_t no_of_bytes){
	printf("Block requested of size : %d\n",no_of_bytes);
	block *prev, *curr;
	void *result;
	if(!(free_list->size)){
		initialize();
	}
	curr = free_list;
	while(((curr->size < no_of_bytes) || (curr->free == 0)) && (curr->next != NULL)){
		printf("Block checked with address : %d\n",curr);
		prev = curr;
		curr = curr->next;
	}
	if(curr->size == no_of_bytes){
		curr->free = 0;
		result = (void *)(++curr);
		printf("Block allocated with address : %d\n",result);
		return result;
	}else if(curr->size > (no_of_bytes + sizeof(block))){
		split(curr, no_of_bytes);
		result = (void *)(++curr);
		printf("Block allocated with address : %d\n",result);
		return result;
	}else{
		result = NULL;
		return result;
	}
}

