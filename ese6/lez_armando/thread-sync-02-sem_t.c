#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t s;

void* print_rightarrow (void* unused) {
  while (1) {
    sem_wait(&s);
    fputc ('-', stderr);
    fputc ('>', stderr);
    fputc ('\n', stderr);
    sem_post(&s);
  }
    return NULL;
}


int main () {
    pthread_t thread_id;
    sem_init(&s,0,1);
    
    /* Create a new thread.
     * The new thread will run the print_xs function. 
     */
    pthread_create(&thread_id, NULL, &print_rightarrow, NULL);

    while (1) {
      sem_wait(&s);
      fputc ('<', stderr);
      fputc ('-', stderr);
      fputc ('\n', stderr);
      sem_post(&s);
    }
    return 0;
}
