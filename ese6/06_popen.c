#include <stdio.h>
#include <unistd.h>

int main()
{

	/* The first argument to popen is executed as a shell command 
	 * in a subprocess running /bin/sh
	 */
	
    FILE* stream = popen("sort", "w");

    fprintf(stream, "B\n");
    fprintf(stream, "A\n");
    fprintf(stream, "C\n");

    pclose(stream);

    return 0;
}
