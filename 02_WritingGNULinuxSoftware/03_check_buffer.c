#include <stdio.h>
#include <unistd.h>

#define REP 5


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
