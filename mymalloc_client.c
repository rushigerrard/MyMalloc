#include<stdio.h>

int main(){
	int *p = (int *) mymalloc(100 * sizeof(int));
	char *q = (char *) mymalloc(250 * sizeof(char));
	int *r = (int *) mymalloc(200 * sizeof(int));
	myfree(q);
	char *s = (char *) mymalloc(200 * sizeof(char));
	return 0;
}
