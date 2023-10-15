#include <stdio.h>

#include "stdg.h"

int main() {
    Vector vector = create_vector(sizeof(int));
    int value1 = 1;
    push(&vector, &value1);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    int value2 = 2;
    push(&vector, &value2);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    int value3 = 3;
    push(&vector, &value3);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    int value4 = 4;
    push(&vector, &value4);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    printf("value 1 = %d\n", ((int *) vector.data)[0]);
    printf("value 2 = %d\n", ((int *) vector.data)[1]);
    printf("value 3 = %d\n", ((int *) vector.data)[2]);
    printf("value 4 = %d\n", ((int *) vector.data)[3]);



    return 0;
}