#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#define DIM 3

/**
 * Listing 4.6 (critical-section.c) Protect a Bank Transaction with a Critical Section
 */

typedef struct trans_params_t
{
    int from;
	int to;
	float dollars;
} trans_params;


float* balances;


int process_transaction(int from, int to, float dollars)
{
    int old_cancle_state;

    if(balances[from] < dollars)
        return 1;

    /* Begin critical section */
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancle_state);

    balances[from] -= dollars;
    balances[to]   += dollars;

    /* End critical section */
    pthread_setcancelstate(old_cancle_state, NULL);

    return 0;
}


void* make_trans(void* params) {
	// sleep(5); // remove comment and try again!
	trans_params* p = (trans_params*) params;
	process_transaction(p->from, p->to, p->dollars);
	return NULL;
}


void print_balances() {
	int i;
	for (i=0; i<DIM; i++) {
		printf("balances[%d] == %.2f\n", i, balances[i]);
	}
	printf("\n");
}


int main() {
	balances = (float*) malloc(DIM * sizeof( float ));
	balances[0] = 1.1;
	balances[1] = 2.2;
	balances[2] = 3.3;
	print_balances();
	
	pthread_t t1;
	trans_params params;
	params.from = 1;
	params.to = 2;
	params.dollars = 1.1;
	
	int err;
	err = pthread_create(&t1, NULL, &make_trans, &params);
	if (err != 0) {
        fprintf(stderr, "Can't create thread. Reason: '%s'", strerror(err));
        exit(EX_OSERR);
	}
	
	err = pthread_cancel(t1);
	printf("pthread_cancel returns: '%s'\n\n", strerror(err));
	
	pthread_join(t1, NULL);
	print_balances();
	return 0;
}
