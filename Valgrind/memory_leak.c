#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>

/* 
 * This program contains several memory management misuse!
 * valgrind --tool=memcheck --trace-children=yes --leak-check=full --track-origins=yes --show-leak-kinds=all ./memory_leak 
 */

void uninitialized_value()
{
    char *p;
    char c = *p;
    printf("[%c]\n",c); 
}

void r_w_after_free()
{
    char *p = malloc(1);
    *p = 'a';
    char c = *p;
    printf("[%c]\n",c);
    free(p);
    c = *p;
}

void r_w_end_of_block()
{
    char *p = malloc(1);
    *p = 'a'; 
    char c = *(p+1); 
    printf("[%c]\n",c); 
    free(p);
}

void mem_leak()
{
    char *p = malloc(1);
    *p = 'a'; 
    char c = *p; 
    printf("[%c]\n",c); 
}

void double_free()
{
    char *p = (char*)malloc(1);
    *p = 'a'; 
    char c = *p;
    printf("[%c]\n",c);
    free(p);
    free(p);
}

int main()
{
    uninitialized_value();
    r_w_after_free();
    r_w_end_of_block();
    mem_leak();
    double_free();
}
