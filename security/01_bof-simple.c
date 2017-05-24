#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
  int auth;
  char buffer[8];
  
  auth = 0;
  gets(buffer);

  if(auth != 0) {
      system(argv[1]);
  } else {
      printf("Unknown user\n");
  }
}
