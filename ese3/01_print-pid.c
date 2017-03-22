#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	pid_t mine, parent;
	
	mine = getpid();
	parent = getppid();
	
    printf("The process ID of mine is %d.\n", mine);
    printf("The process ID of my parent is %d.\n", parent);

    return 0;
}
