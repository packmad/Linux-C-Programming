#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("The process ID of mine is %d.\n", (int)getpid());
    printf("The process ID of my parent is %d.\n", (int)getppid());

    return 0;
}
