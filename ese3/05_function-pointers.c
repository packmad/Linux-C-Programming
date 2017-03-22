#include <stdio.h>


// Passing the pointer to another function is basically the same
int add2to3(int (*fp)(int, int)) {
    return (*fp)(2, 3);
}


int addInt(int n, int m) {
    return n + m;
}


void someFunction(int arg)
{
    printf("This is someFunction being called and arg is: %d\n", arg);
}


int main(int argc, char* argv[])
{
    void (*funPoint1)(int);
    int (*funPoint2)(int, int);
    
    funPoint1 = &someFunction;
    funPoint2 = &addInt;
    
	printf("Call someFunction() using a pointer!\n");
    (funPoint1)(42);
    
    printf("Calling addInt(..) Result=%d\n", (*funPoint2)(40, 2));
    
	printf("Passing addInt(..) to add2to3(.) Result= %d\n", add2to3(funPoint2));
	
}
