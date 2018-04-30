#include <stdio.h>


/**
 * Listing 2.3 (getopt_long.c) Using getopt_long
 */


extern char** environ; /* The ENVIRON variable contains the environment. */

int main ()
{
	char** var;
	for (var = environ; *var != NULL; ++var) {
		printf ("%s\n", *var);
	}
	return 0;
}
