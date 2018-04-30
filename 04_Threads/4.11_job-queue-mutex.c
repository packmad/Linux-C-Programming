#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#define D_SIZE 32
#define DIM 88

/**
 * Listing 4.11 ( job-queue2.c) Job Queue Thread Function, Protected by a Mutex
 */

typedef struct job {
	char desc[D_SIZE]; /* Description */
    struct job* next;  /* Link field for linked list. */
} job_t;

/* A linked list of pending jobs. */
job_t *job_queue = NULL;

/* A mutex protecting job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;


/* Print jobs in queue */
void print_jobs() {
	pthread_mutex_lock (&job_queue_mutex);
	printf("---Jobs queue---\n\n");
	job_t *head = job_queue;
	while(head != NULL) {
		printf("%s\n", head->desc);
		head = head->next; 
	}
	printf("----------------\n");
	pthread_mutex_unlock (&job_queue_mutex);
}


/* Create and enqueue a new job */
void enqueue_new_job (char *desc)
{
	job_t* new_job = (job_t *) malloc(sizeof(job_t));
	strncpy(new_job->desc, desc, D_SIZE);
	new_job->desc[D_SIZE-1] = '\0';
	
	pthread_mutex_lock (&job_queue_mutex);
	
	new_job->next = job_queue;
	job_queue = new_job;
	
	pthread_mutex_unlock (&job_queue_mutex);
}


/* Create and enqueue a new job */
void* thread_function(void* arg)
{
	int p = *((int*) arg);
	char desc[D_SIZE];
	snprintf(desc, D_SIZE, "This is thread n.%d\n", p);
	enqueue_new_job(desc);
    return NULL;
}


int main() {
	pthread_t threads[DIM];
	int params[DIM], err, i;
	
	for(i=0; i<DIM; i++) {
		params[i] = i;
		err = pthread_create(&(threads[i]), NULL, thread_function, (void*)&(params[i]));
		if (err != 0) {
		    fprintf(stderr, "Can't create thread. Reason: '%s'", strerror(err));
		    exit(EX_OSERR);
		}
    }
    for(i=0; i<DIM; i++) {
		pthread_join(threads[i], NULL);
    }
	print_jobs();
	return 0;
}
