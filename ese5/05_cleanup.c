#include<malloc.h>
#include<pthread.h>
#include<stdio.h>


void* allocate_buffer(size_t size)
{
	printf("Inside 'allocate_buffer'...\n");
    return malloc(size);
}


void deallocate_buffer(void* buffer)
{
	printf("Inside 'deallocate_buffer'...\n");
    free(buffer);
}

void* do_some_work(void* params)
{
    void* tmp_buffer = allocate_buffer(1024);

    pthread_cleanup_push(deallocate_buffer, tmp_buffer);

    /* 
     * do some work here that might call pthread_exit
     * or might be cancelled
     */
    // pthread_exit(0); // uncomment: what does it change?
    
    printf("'do_some_work' is near the end!\n");

    pthread_cleanup_pop(1);
    return NULL;
}


int main (void) {
    pthread_t thread;
    pthread_create(&thread, NULL, &do_some_work, NULL);
    pthread_join(thread, NULL);
    return 0;
}
