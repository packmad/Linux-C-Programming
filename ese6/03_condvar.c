/**
 * Example code for using Pthreads condition variables.  
 * The main thread creates 3 threads.
 * Two of those threads increment a "count" variable,
 * while the third thread watches the value of "count". 
 * When "count" reaches a predefined limit, 
 * the waiting thread is signaled by one of the incrementing threads.
 * The waiting thread "awakens" and then modifies count.
 * The program continues until the incrementing threads reach TCOUNT.
 * The main program prints the final value of count.
 */

#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#define THREADS  3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;


void* inc_count(void *arg) 
{
    int i;
    int my_id = *((int*) arg);

    for (i=0; i<TCOUNT; i++) {
        pthread_mutex_lock(&count_mutex);
        count++;

        if (count == COUNT_LIMIT) {
            /* Note that this occurs while mutex is locked. */
            printf("inc_count(): thread %d, count = %d  Threshold reached. ",
                    my_id, count);
            pthread_cond_signal(&count_threshold_cv);
            printf("Just sent signal.\n");
        }
        printf("inc_count(): thread %d, count = %d, unlocking mutex\n", 
                my_id, count);
        pthread_mutex_unlock(&count_mutex);

        sleep(1); /* Do some work so threads can alternate on mutex lock */
    }
    return NULL;
}


void* watch_count(void *arg) 
{
    int my_id = *((int*) arg);

    printf("Starting watch_count(): thread %d\n", my_id);

    /*
       Lock mutex and wait for signal.  Note that the pthread_cond_wait routine
       will automatically and atomically unlock mutex while it waits. 
       Also, note that if COUNT_LIMIT is reached before this routine is run by
       the waiting thread, the loop will be skipped to prevent pthread_cond_wait
       from never returning.
       */
    pthread_mutex_lock(&count_mutex);
    while (count < COUNT_LIMIT) {
        printf("watch_count(): thread %d Count= %d. Going into wait...\n", my_id,count);
        pthread_cond_wait(&count_threshold_cv, &count_mutex);
        printf("watch_count(): thread %d Condition signal received. Count= %d\n", my_id,count);
    }
    printf("watch_count(): thread %d Updating the value of count...\n", my_id);
    count += 125;
    printf("watch_count(): thread %d count now = %d.\n", my_id, count);
    printf("watch_count(): thread %d Unlocking mutex.\n", my_id);
    pthread_mutex_unlock(&count_mutex);
    return NULL;
}


int main(int argc, char *argv[])
{
    int i, err; 
    int params[THREADS];
    pthread_t threads[THREADS];
    pthread_attr_t attr;

    /* Initialize mutex and condition variable objects */
    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init (&count_threshold_cv, NULL);

    /* For portability, explicitly create threads in a joinable state */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i=0; i<THREADS; i++) {
    	params[i] = i;
        if (i==0) {
            err = pthread_create(&threads[i], &attr, watch_count, (void*)&(params[i]));
        }
        else {
            err = pthread_create(&threads[i], &attr, inc_count, (void*)&(params[i]));
        }
		if (err != 0) {
		    fprintf(stderr, "Can't create thread. Reason: '%s'", strerror(err));
		    exit(EX_OSERR);
		}
    }

    /* Wait for all threads to complete */
    for (i=0; i<THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Main(): Waited and joined with %d threads. Final value of count = %d. Done.\n", 
            THREADS, count);

    /* Clean up and exit */
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threshold_cv);
    return 0;

}

