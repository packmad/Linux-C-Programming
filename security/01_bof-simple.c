#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int auth;
  char buffer[8];

  auth = 0;
  gets(buffer);

  if(auth != 0) {
      printf("You are authenticated\n");
  } else {
      printf("Unknown user\n");
  }
}
