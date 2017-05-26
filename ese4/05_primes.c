#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>


void* compute_prime(void* arg)
{
    int candidate = 2;
    int n = *((int*)arg);

    printf("Will compute for the %dth prime...\n", n);
    while(true) {
        int factor;
        int is_prime = true;

        for(factor = 2; factor * factor <= candidate; factor++) {
            if(candidate % factor == 0) {
                is_prime = 0;
                break;
            }
        }

        if(is_prime && --n == 0) {
			return (void*) candidate;
        }

        ++candidate;
    }

    return NULL;
}

int main()
{
    pthread_t thread;
    int which_prime = 12;
    int prime;

    pthread_create(&thread, NULL, &compute_prime, (void*)&which_prime);

    /* Do some other work here. */

    pthread_join(thread, (void*) &prime);
    printf("The %dth prime number is %d.\n", which_prime, prime);

    return 0;
}
