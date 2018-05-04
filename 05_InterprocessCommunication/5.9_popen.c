#include <stdio.h>
#include <unistd.h>

/**
 * Listing 5.9 (popen.c) Example Using popen
 */


int main()
{
	/*
	 * The first argument to popen is executed as a shell command 
	 * in a subprocess running /bin/sh
	 */
	FILE* stream = popen("sort", "w");

	fprintf(stream, "B\n");
	fprintf(stream, "D\n");
	fprintf(stream, "A\n");
	fprintf(stream, "C\n");

	pclose(stream);

	return 0;
}
