#include <stdio.h>

#include "stdg.h"

int main() {
    Vector vector = vector_create(sizeof(int));
    int value1 = 1;
    vector_push(&vector, &value1);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    int value2 = 2;
    vector_push(&vector, &value2);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    int value3 = 3;
    vector_push(&vector, &value3);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    int value4 = 4;
    vector_push(&vector, &value4);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    printf("value 1 = %d\n", ((int *) vector.data)[0]);
    printf("value 2 = %d\n", ((int *) vector.data)[1]);
    printf("value 3 = %d\n", ((int *) vector.data)[2]);
    printf("value 4 = %d\n", ((int *) vector.data)[3]);

    int value4_pop;
    vector_pop(&vector, &value4_pop);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    printf("value 4 (popped) = %d\n", value4_pop);

    int value3_pop;
    vector_pop(&vector, &value3_pop);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    printf("value 3 (popped) = %d\n", value3_pop);

    vector_clear(&vector);
    printf("length = %d capacity = %d\n", vector.length, vector.capacity);

    return 0;
}