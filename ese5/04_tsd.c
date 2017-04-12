#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>


#define LOG_SIZE 25
#define DIM 5


static pthread_key_t thread_log_key;


void write_to_thread_log(const char* message)
{
    FILE* thread_log = (FILE*)pthread_getspecific(thread_log_key);
    int tid = (int)pthread_self();
    fprintf(thread_log, "%d %s\n", tid, message);
}


void close_thread_log(void* thread_log)
{
	printf("Calling 'close_thread_log'\n");
    fclose((FILE*)thread_log);
}


void* thread_function(void* args)
{
    char thread_log_filename[LOG_SIZE];
    FILE* thread_log;

	/* Generate the filename for this thread’s log file. */
    sprintf(thread_log_filename, "thread_%d.log", (int)pthread_self());
	//TODO check sec
    thread_log = fopen(thread_log_filename, "w");

	/* Store the file pointer in thread-specific data under thread_log_key. */
    pthread_setspecific(thread_log_key, thread_log);

    printf("Variable thread_log_key for thread %d set to %s.\n", (int)pthread_self(), thread_log_filename);

    write_to_thread_log("starts...");

    /* Do the big thing here */

    return NULL;  // Calling 'close_thread_log'
}


int main()
{
    int i, err;
    pthread_t threads[DIM];
    
    /*
     * The first argument is a pointer to a pthread_key_t variable.
	 * The second argument to pthread_key_create is a cleanup function. 
	 * If you pass a function pointer here, 
	 * GNU/Linux automatically calls that function when each thread exits, 
	 * passing the thread-specific value corresponding to that key
     */
    pthread_key_create(&thread_log_key, close_thread_log);

    for(i=0; i<DIM; i++) {
		err = pthread_create(&(threads[i]), NULL, thread_function, NULL);
		if (err != 0) {
			printf("Can't create thread. Reason: '%s'", strerror(err));
			exit(EX_OSERR);
		}
    }

    for(i=0; i<DIM; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
