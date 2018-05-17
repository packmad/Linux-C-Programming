#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/* 
 * This program contains a race condition!
 * valgrind --tool=helgrind --trace-children=yes --read-var-info=yes ./race_condition
 */

int var = 42;

void* child_fn(void* arg) 
{
	if (var == 42)
    	var++;
    return NULL;
}


int main (void)
{
	int err;
    pthread_t child;
    
    err = pthread_create(&child, NULL, child_fn, NULL);
	if (err != 0) {
        fprintf(stderr, "Can't create thread. Reason: '%s'", strerror(err));
        exit(EX_OSERR);
	}
    
    var++;
    printf("var=%d\n", var);
    
    pthread_join(child, NULL);   
    return 0;
}

