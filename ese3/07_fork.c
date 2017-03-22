#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;

    printf("The main program has the PID %d.\n", (int)getpid());
    child_pid = fork();

    if(child_pid !=0) {
        printf("This is the parent process with PID %d.\n", (int)getpid());
        printf("The child process has the PID %d.\n", child_pid);
    }
    else {
        printf("This is the child process with PID %d.\n", (int)getpid());
        printf("Its parent process is with PID %d.\n", (int)getppid());
    }

    return 0;
}
