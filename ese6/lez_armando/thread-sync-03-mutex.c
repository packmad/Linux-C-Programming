#include <pthread.h>
#include <stdio.h>

pthread_mutex_t m;

void* print_rightarrow (void* unused) {
  while (1) {
    pthread_mutex_lock(&m);
    fputc ('-', stderr);
    fputc ('>', stderr);
    fputc ('\n', stderr);
    pthread_mutex_unlock(&m);
  }
    return NULL;
}


int main () {
    pthread_t thread_id;
    pthread_mutex_init(&m,NULL);
    
    /* Create a new thread.
     * The new thread will run the print_xs function. 
     */
    pthread_create(&thread_id, NULL, &print_rightarrow, NULL);

    while (1) {
      pthread_mutex_lock(&m);
      fputc ('<', stderr);
      fputc ('-', stderr);
      fputc ('\n', stderr);
      pthread_mutex_unlock(&m);
    }
    return 0;
}
