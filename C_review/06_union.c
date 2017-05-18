#include <stdio.h>
#include <string.h>

#define SIZE 20 

union data_u {
   int i;
   float f;
   char str[SIZE];
};


int main() {

   union data_u data;        

   // max size of type in union
   printf( "Memory size occupied by data : %d\n", sizeof(data));

   data.i = 42;
   printf("%d %f %s\n", data.i, data.f, data.str);
   data.f = 4.2;
   printf("%d %f %s\n", data.i, data.f, data.str);
   strcpy(data.str, "ciao");

   printf("%d %f %s\n", data.i, data.f, data.str);
}
