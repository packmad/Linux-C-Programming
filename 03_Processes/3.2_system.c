#include <stdio.h>
#include <stdlib.h>

/**
 * Listing 3.2 (system.c) Using the system Call
 */

/* 
 * Be careful:
 * https://en.wikipedia.org/wiki/Code_injection#Shell_injection
 */

int main(int argc, char* argv[])
{
	
    int retval = system(argv[1]);

    return retval;
}
