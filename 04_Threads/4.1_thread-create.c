#include <pthread.h>
#include <stdio.h>

/**
 * Listing 4.1 (thread-create.c) Create a Thread
 */

void* print_xs (void* unused)
{
    while (1)
        fputc ('x', stderr);
    return NULL;
}


int main ()
{
    pthread_t thread_id;

    /**
     * pthread_create() Create a new thread.
     * The new thread will run the print_xs function. 
     */
    pthread_create(&thread_id, NULL, &print_xs, NULL);

    while (1)
        fputc ('.', stderr);
    return 0;
}
