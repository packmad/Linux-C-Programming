#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
  int auth;
  char buffer[8];
  
  auth = 0;
  printf("Username: ");
  fgets(buffer, 16, stdin);

  if(auth != 0) {
      printf("Authenticated\n");
  } else {
      printf("Unknown user\n");
  }
}
