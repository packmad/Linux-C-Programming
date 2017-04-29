#include <pthread.h>
#include <stdio.h>

void* print_rightarrow (void* unused) {
  while (1) {
    fputc ('-', stderr);
    fputc ('>', stderr);
    fputc ('\n', stderr);
  }
    return NULL;
}


int main () {
    pthread_t thread_id;
    /* Create a new thread.
     * The new thread will run the print_xs function. 
     */
    pthread_create(&thread_id, NULL, &print_rightarrow, NULL);

    while (1) {
      fputc ('<', stderr);
      fputc ('-', stderr);
      fputc ('\n', stderr);
    }
    return 0;
}
