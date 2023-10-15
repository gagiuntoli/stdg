
#ifndef STDG_H
#define STDG_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int data_size; // size of each element in bytes
    unsigned int length;    // quantity of elements currently stored
    unsigned int capacity;  // available capacity
    void *data;
} Vector;

static inline Vector create_vector(unsigned int data_size) {
    Vector vector = {.data_size = data_size, .length = 0, .capacity = 0, .data = NULL};

    return vector;
}

static inline void push(Vector *vector, void *value) {
    void *data;
    if (vector->length == vector->capacity) {
        if (vector->capacity == 0) {
            vector->capacity = 1;
            data = malloc(vector->data_size * vector->capacity);
        } else {
            vector->capacity *= 2;
            data = malloc(vector->data_size * vector->capacity);
            memcpy(data, vector->data, vector->data_size * vector->length);
            free(vector->data);
        }
    }
    vector->data = data;

    memcpy(vector->data + vector->data_size * vector->length, value, vector->data_size);
    vector->length++;
}

#endif