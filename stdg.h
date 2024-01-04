#ifndef STDG_H
#define STDG_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t data_size; // size of each element in bytes
    size_t length;    // quantity of elements currently stored
    size_t capacity;  // available capacity
    char *data;
} Vector;

Vector vector_create(unsigned int data_size);

void vector_push(Vector *vector, void *value);

void vector_pop(Vector *vector, void *value);

void vector_get(Vector *vector, void *value, size_t index);

void vector_clear(Vector *vector);

Vector file_to_string_array(char *file_path);

#endif
