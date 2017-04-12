#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

/* 
 * This program contains a race condition and a memory leak.
 * Valgrind is your friend:
 * valgrind --tool=helgrind --read-var-info=yes ./06_helgrind
 * valgrind --tool=memcheck --leak-check=yes ./06_helgrind 
 */

int var = 42;

void* child_fn(void* arg) {
	int* stuff = (int*) malloc(var * sizeof(int));
	if (var == 42)
    	var++;
    stuff[var-1] = 0;
    return NULL;
}

int main (void) {
    pthread_t child;
    pthread_create(&child, NULL, child_fn, NULL);
    
    var++;
    printf("var=%d\n", var);
    
    pthread_join(child, NULL);   
    return 0;
}

