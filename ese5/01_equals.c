#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define DIM 2

pthread_t tid[DIM];

void* doSomeThing(void *arg)
{
    pthread_t id = pthread_self();

    if(pthread_equal(id, tid[0])) {
        printf("First thread processing\n");
    }
    else {
        printf("Second thread processing\n");
    }
	return NULL;
}


int main(void)
{
    int i;
	int err[DIM];

	for(i=0; i<DIM; i++) {
        err[i] = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

        if (err[i] != 0)
            printf("Can't create thread. Reason: '%s'", strerror(err[i]));
        else
            printf("Thread created successfully\n");
    }

	for(i=0; i<DIM; i++) {
		if (err[i] == 0) {
			 pthread_join(tid[i], NULL);
		}
	}

    return 0;
}
