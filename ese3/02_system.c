#include <stdio.h>
#include <stdlib.h>

/* Be careful:
 * https://en.wikipedia.org/wiki/Code_injection#Shell_injection
 */

int main(int argc, char* argv[])
{
	
    int retval = system(argv[1]);

    return retval;
}
