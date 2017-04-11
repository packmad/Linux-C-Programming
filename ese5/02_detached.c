#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


void* thread_function (void* thread_arg)
{
	/* Do work here... */
	return NULL;
}


int main()
{
	pthread_t t1, t2;
	
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	
	pthread_create (&t2, &attr, &thread_function, NULL);
	pthread_attr_destroy (&attr);
	
	pthread_create (&t1, NULL, &thread_function, NULL);
	
	/* Do work here... */
	sleep(4);
	
	pthread_join(t1, NULL);
	/* No need to join the second thread. */
	
	return 0;
}
