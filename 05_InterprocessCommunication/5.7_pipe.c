#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * Listing 5.7 (pipe.c) Using a Pipe to Communicate with a Child Process
 */


/* Write COUNT copies of MESSAGE to STREAM, pausing for a second between each. */
void writer(const char* message, int count, FILE* stream)
{
    for(; count > 0; --count) {
        fprintf(stream, "%s\n", message);
        fflush(stream);
        sleep(1);
    }
}


/* Read random strings from the stream as long as possible. */
void reader(FILE* stream)
{
    char buffer[BUF_SIZE];
    while(!feof(stream) && !ferror(stream) 
    					&& fgets(buffer, sizeof(buffer), stream) != NULL) {
        fputs(buffer, stdout);
    }
}


int main()
{
    int fds[2];
    pid_t pid;

	/* Create a pipe. 
	 * File descriptors for the two ends of the pipe are placed in fds
	 */
    pipe(fds);

    pid = fork();

    if(pid == (pid_t)0) {
        FILE* stream;
        /* This is the child process. 
         * Close our copy of the write end of the file descriptor. */
        close(fds[1]);

		/* Convert the read file descriptor to a FILE and read from it. */
        stream = fdopen(fds[0], "r");
        reader(stream);

        close(fds[0]);
    }
    else {
        FILE* stream;
        close(fds[0]);

		/* Convert the write file descriptor to a FILE and write to it. */
        stream = fdopen(fds[1], "w");
        writer("Hello pipe.", 5, stream);

        close(fds[1]);
    }

    return 0;
}
