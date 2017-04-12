#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/* 
 * This program contains a race condition and a memory leak.
 * Valgrind is your friend:
 * valgrind --tool=helgrind --read-var-info=yes ./06_valgrind
 * valgrind --tool=memcheck --leak-check=yes ./06_valgrind 
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
	int err;
    pthread_t child;
    
    err = pthread_create(&child, NULL, child_fn, NULL);
	if (err != 0) {
		printf("Can't create thread. Reason: '%s'", strerror(err));
		exit(EX_OSERR);
	}
    
    var++;
    printf("var=%d\n", var);
    
    pthread_join(child, NULL);   
    return 0;
}

