#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void authentication()
{
    int auth;
    char buffer[8];

    auth = 0;
    printf("Username: ");
    fgets(buffer, 16, stdin);

    if (auth != 0) {
        printf("Authenticated!\n\n");
    }
    else {
        printf("Unknown user\n\n");
    }
}


void counter()
{
    int i;
    for (i = 2048; i > 1024; i += 2*i) {
        printf("i=%d\n", i);
    }
    printf("\nReachable?\n");
}


int main(int argc, char **argv)
{
    authentication();
    counter();
    return 0;
}
