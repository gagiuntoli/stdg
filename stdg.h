#ifndef STDG_H
#define STDG_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int data_size; // size of each element in bytes
    unsigned int length;    // quantity of elements currently stored
    unsigned int capacity;  // available capacity
    char *data;
} Vector;

Vector vector_create(unsigned int data_size);

void vector_push(Vector *vector, void *value);

void vector_pop(Vector *vector, void *value);

void vector_clear(Vector *vector);

char** file_to_string_array(char *file_path);

#endif
