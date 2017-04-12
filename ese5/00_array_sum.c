#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#define DIM 4
#define ARR_SIZE 40000
#define RANGE ARR_SIZE / DIM


pthread_t tid[DIM];
int array[ARR_SIZE];


int init_array() {
	int i, expected;
	srand(time(NULL)); 
	for(i=0, expected=0; i<ARR_SIZE; i++) {
		array[i] = rand() % 10; // avoid overflow in sum
		expected += array[i];
	}
	return expected;
}


void* calculate_sum(void *arg)
{
	int p = *((int*) arg);
	int from = p*RANGE;
	int to = from + RANGE;
	int sum, i;
	
	printf("Thread=%d, p=%d, from=%d, to=%d\n", (int)pthread_self(), p, from, to); 
	for(sum=0, i=from; i<to; i++)
		sum += array[i];

	return (void*)sum;
}


int main(void)
{
    int i, err, expected, result;
	int params[DIM], res[DIM];
	
	expected = init_array();
	
	for(i=0; i<DIM; i++) {
		params[i] = i; 
        err = pthread_create(&(tid[i]), NULL, &calculate_sum, (void*)&(params[i])); // (void *)params[i]);
        if (err != 0) {
            printf("Can't create thread. Reason: '%s'", strerror(err));
            exit(EX_OSERR);
		}
    }

	for(result=0, i=0; i<DIM; i++) {
		pthread_join(tid[i], (void*) &(res[i]));
		result += res[i];
	}
	
	assert(expected == result);
	printf("result=%d\n", result);
    return 0;
}
