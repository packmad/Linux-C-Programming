#include <stdio.h>
#include <stdlib.h>

int main()
{
    int retval = system("ls -al ~");

    return retval;
}
