#include <stdio.h>
#include <stdlib.h>

/* Be careful:
 * https://en.wikipedia.org/wiki/Code_injection#Shell_injection
 */

int main()
{
    int retval = system("ls -al ~");

    return retval;
}
