#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#define D_SIZE 16
#define DIM 4

typedef struct job {
	char desc[D_SIZE];
    struct job* next;
} job_t;

job_t *job_queue;

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;


void print_jobs() {
	pthread_mutex_lock (&job_queue_mutex);
	job_t *head = job_queue;
	while(head != NULL) {
		printf("%s\n", head->desc);
		head = head->next; 
	}
	pthread_mutex_unlock (&job_queue_mutex);
}


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


void* thread_function(void* arg)
{
	int p = *((int*) arg);
	char desc[D_SIZE];
	snprintf(desc, D_SIZE, "Hi, I'm %i\n", p);
	
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
			printf("Can't create thread. Reason: '%s'", strerror(err));
			exit(EX_OSERR);
		}
    }
    for(i=0; i<DIM; i++) {
        pthread_join(threads[i], NULL);
    }
	print_jobs();
}
