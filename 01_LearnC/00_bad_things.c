#include <stdio.h>

int main(int argc, char** argv)
{
    int i;
    for (i = 2048; i > 1024; i+=2*i) {
        printf("i=%d\n", i);
    }
    printf("\nReachable?\n");
    return 0;
}
