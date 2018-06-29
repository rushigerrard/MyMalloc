#include<stdio.h>

int main(){
	int *p = (int *) mymalloc(100 * sizeof(int));
	char *q = (char *) mymalloc(250 * sizeof(char));
	return 0;
}
