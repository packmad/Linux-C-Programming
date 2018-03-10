#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

extern int errno;

int main () {
	FILE * fp;
	fp = fopen ("filedoesnotexist.txt", "rb");
	if (fp == NULL) {
		fprintf(stderr, "Value of errno: %d\n", errno);
		fprintf(stderr, "Error opening the file: %s\n", strerror(errno));
		perror("Error printed by perror");
		exit(EX_OSFILE); // https://goo.gl/Y40V0r
	} else {
		fclose (fp);
	}
	return 0;
}
