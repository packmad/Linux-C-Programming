#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <unistd.h>

/**
 * Listing 3.4 ( fork-exec.c) Using fork and exec Together
 */
 
int spawn(char* program_name, char** arg_list)
{
    pid_t child_pid;

    child_pid = fork();

    if(child_pid != 0) {
        return child_pid; // if I am the parent, return the child pid
    }
    else {
        execvp(program_name, arg_list);
        /* The execvp will never return unless error occurs */
        fprintf(stderr, "An error occured when invoking execvp.\n");
        exit(EX_OSERR);
    }
}


int main()
{
    int child_status, child_pid;

    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    child_pid = spawn(arg_list[0], arg_list);
    
    waitpid(child_pid, &child_status, 0); // wait for the child whose PID is equal to child_pid

    /*
     * if you have only one child you can use:
     * wait (&child_status);
     */

    if(WIFEXITED(child_status)) {
        printf("The child process exited normally with exit code %d.\n", WEXITSTATUS(child_status));
    }
    else {
        printf("The child process exited abnormally.\n");
    }

    printf("Done with the main program.\n");

    return 0;
}
