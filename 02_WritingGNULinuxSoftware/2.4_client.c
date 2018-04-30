#include <stdio.h>
#include <stdlib.h>

/**
 * Listing 2.4 (client.c) Part of a Network Client Program
 */
 
int main ()
{
	/* You can set an environment variable with:
	   $ export SERVER_NAME=server.example.com
	 */
    char* server_name = getenv ("SERVER_NAME");
    
    if (server_name == NULL)
        /* The SERVER_NAME environment variable was not set, use default. */
        server_name = "server.my-company.com";
    printf ("accessing server %s\n", server_name);
    /* Access the server here... */
    return 0;
}
