#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/**
 * Listing 4.15 (thread-pid) Print Process IDs for Threads
 */

/*
 * On GNU/Linux, threads are implemented as processes.
 * Whenever you call pthread_create to create a new thread, 
 * Linux creates a new process that runs that thread. 
 * However, this process is not the same as a process you would create with fork 
 * it shares the same address space and resources as the original process rather 
 * than receiving copies.
*/

void* thread_function (void* arg)
{
    fprintf (stderr, "child thread pid is %d\n", (int) getpid ());
    /* Spin forever. */
    while (1);
    return NULL;
}

int main ()
{
    pthread_t thread;
    fprintf (stderr, "main thread pid is %d\n", (int) getpid ());
    pthread_create (&thread, NULL, &thread_function, NULL);
    /* Spin forever. */
    while (1);
    return 0;
}
