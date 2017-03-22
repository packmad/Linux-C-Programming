#include <stdio.h>
#include <stdlib.h>
#define DIM 3



void alloc_good(int** p) {
   *p = (int*)malloc(sizeof(int));
   **p = 10;
}


void alloc_bad(int* p) {
   p = (int*)malloc(sizeof(int));
   *p = 10;
}


void alloc_example() {
	int *p1 = NULL, *p2 = NULL;
	
	alloc_good(&p1);
	printf("alloc_good %d ",*p1);
	free(p1);
	
	alloc_bad(p2);
	// printf("alloc_bad %d ",*p2); // SEGFAULT, why?
}


void pointers_and_array() {
	int nums[DIM] = {41, 42, 43};
	int i;
	
	for (i=0; i<DIM; i++) {
		printf("%d\n", nums[i]);
	}
	
	for (i=0; i<DIM; i++) {
		printf("%d\n", *(nums + i)); // array ~ pointers
	}
	
}


void by_value(int x) {
	x++;
}


void by_ref(int* x) { // important: no 'real' pass by reference in C
	(*x)++;
}

void by_value_by_ref() {
	int life = 42;
	by_value(life);
	printf("life = %d\n", life);
	by_ref(&life);
	printf("life = %d\n", life);
}

void basic() {
	char a = 'A'; 
	char *ap = &a;
	char **app = &ap;
	
	char x = *ap;
	char y = **app;
	
	printf("%c %c %c %c %c\n", a, *ap, **app, x, y);
}


int main(int argc, char *argv[]) {
	printf("basic()\n");
	basic();
	printf("\nby_value_by_ref()\n");
	by_value_by_ref();
	printf("\npointers_and_array()\n");
	pointers_and_array();
	printf("\nalloc_example()\n");
	alloc_example();
}
