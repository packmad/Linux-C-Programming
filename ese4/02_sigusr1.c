#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * If you use a global variable to flag a signal from a signal-handler function, 
 * it should be of the special type sig_atomic_t
 * Linux guarantees that assignments to variables of this type are performed 
 * in a single instruction and therefore cannot be interrupted midway
 */
sig_atomic_t sigusr1_count = 0;


void sigusr1_handler(int signal_number)
{
    ++sigusr1_count;
}


int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &sigusr1_handler;
    sigaction(SIGUSR1, &sa, NULL);

    /** Main stuff here **/
    pid_t pid = getpid();
    printf("pid=%d\n", (int) pid);
    sleep(120); // do something	

    printf("The SIGUSR1 signal was raised for %d times.\n", sigusr1_count);

    return 0;
}
