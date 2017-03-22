#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int spawn(char* program_name, char** arg_list)
{
    pid_t child_pid;

    child_pid = fork();

    if(child_pid != 0) {
        return child_pid;
    }
    else {
        execvp(program_name, arg_list);

        /* The execvp will never return unless error occurs. */
        fprintf(stderr, "an error occured when invoking execvp.\n");
        abort();
    }
}

int main()
{
    int child_status;

    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    spawn("ls", arg_list);
    
    wait(&child_status);

    if(WIFEXITED(child_status)) {
        printf("The child process exited normally with exit code %d.\n", WEXITSTATUS(child_status));
    }
    else {
        printf("The child process exited abnormally.\n");
    }

    printf("done with the main program.\n");

    return 0;
}
