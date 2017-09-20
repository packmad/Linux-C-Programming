#include <stdio.h>
#include <stdlib.h>
#define DIM 5


typedef struct record
{
    int i;
    float PI;
    char A;
} record_t;


void malloc_struct() {
    record_t *ptr_one;

    ptr_one = (record_t *) malloc (sizeof(record_t));
    if (ptr_one == NULL)
        return;
    (*ptr_one).i = 10;
    (*ptr_one).PI = 3.14;
    ptr_one->A = 'a'; // x->field is a shorthand for (*x).field

    printf("First value: %d\n",(*ptr_one).i);
    printf("Second value: %f\n", (*ptr_one).PI);
    printf("Third value: %c\n", (*ptr_one).A);

    free(ptr_one);

}


void malloc_array_struct() {
    int i;
    record_t *records[DIM];
    record_t *another_way = (record_t *) malloc (DIM * sizeof(record_t));
    if (another_way == NULL)
        return;

    for(i=0; i<DIM; i++) {
        records[i] = (record_t *) malloc (sizeof(record_t));
        if (records[i] == NULL)
            return;
        records[i]->i = 0;
        records[i]->PI = 0.1;
        records[i]->A = 'X';

        another_way[i].i = 42;
        another_way[i].PI = 0.2;
        another_way[i].A = 'Y';
    }
    
    for(i=0; i<DIM; i++) {
        printf("%d %f %c\n", records[i]->i, records[i]->PI, records[i]->A);
        printf("%d %f %c\n", another_way[i].i, another_way[i].PI, another_way[i].A);
        free(records[i]);
    }
    free(another_way);
}


void malloc_simplest() {
    int *ptr_one;

    ptr_one = (int *)malloc(sizeof(int));

    if (ptr_one == NULL)
    {
        printf("ERROR: Out of memory\n");
        return;
    }

    *ptr_one = 25;
    printf("%d\n", *ptr_one);

    free(ptr_one);
}


int main(int argc, char* argv[])
{
    malloc_simplest();
    malloc_struct();
    malloc_array_struct();
    return 0;
}
