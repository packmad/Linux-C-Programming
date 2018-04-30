#include <stdio.h>
#include <unistd.h>

#define BUF 8
#define REP 4

/**
 * In computer programming, standard streams are preconnected input and output
 * communication channels between a computer program and its environment.
 * The three input/output (I/O) connections are called:
 * standard input (stdin), standard output (stdout) and standard error (stderr)
 */
 
void readString()
{
	char string[BUF];
	printf("Please enter a string: ");
	fgets (string, BUF, stdin);
	fprintf(stdout, "Your string: %s\n", string);
	fflush(stdout); /* Will now print everything in the stdout buffer */
}


int main(int argc, char* argv[])
{
    int i;
 		
    for(i = 0; i < REP; i++) {
        fprintf(stdout, ".");
        sleep(1);
    }

    for(i = 0; i < REP; i++) {
        fprintf(stderr, "x");
        sleep(1);
    }

    return 0;
}
