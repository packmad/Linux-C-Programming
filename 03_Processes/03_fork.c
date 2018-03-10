#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * Listing 3.3 ( fork.c) Using fork to Duplicate a Program's Process
 */
 
int main() {

	int child_status;
    pid_t child_pid;

    printf("The main program has the PID %d.\n\n", getpid());
    
    child_pid = fork();
    /*
     * fork() creates a new process. 
     * The return value is 0 in the child and the pid of the child in the parent
     */
 
    if(child_pid != 0) {
        printf("This is the parent process with PID %d.\n", getpid());
        printf("The child process has the PID %d.\n", child_pid);
        wait(&child_status); // waits for the first child to die (any one!)
    }
    else {
        printf("This is the child process with PID %d.\n", getpid());
        printf("Its parent process is with PID %d.\n", getppid());
    }

	return 0;
}
