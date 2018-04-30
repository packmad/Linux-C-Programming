#include <stdio.h>
#include <unistd.h>

/**
 * Listing 3.1 ( print-pid.c) Printing the Process ID
 */

int main(int argc, char* argv[])
{
	pid_t mine, parent;
	
	mine = getpid();
	parent = getppid();
	
    printf("The process ID of mine is %d.\n", mine);
    printf("The process ID of my parent is %d.\n", parent);

	sleep(42); // ps -aux

    return 0;
}
