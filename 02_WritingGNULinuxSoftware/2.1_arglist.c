#include <stdio.h>

/**
 * Listing 2.1 (arglist.c) Using argc and argv
 */

int main(int argc, char* argv[])
{
    printf("The program's name is %s.\n", argv[0]);
    printf("The program's been invoked with %d parameters.\n", argc - 1);
	
    if(argc > 1) {
        int i;
        for (i = 1; i < argc; i++) {
            printf("The %dth parameter is %s.\n", i, argv[i]);
        }
    }

    return 0;
}
