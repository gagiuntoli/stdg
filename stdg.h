#ifndef STDG_H
#define STDG_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    size_t data_size; // size of each element in bytes
    size_t length;    // quantity of elements currently stored
    size_t capacity;  // available capacity
    char *data;
} Vector;

Vector vector_create(unsigned int data_size);

typedef bool (*equal)(const void *a, const void *b);
typedef char* (*void_to_str)(void *value);

void vector_push(Vector *vector, void *value);
void vector_push_unique(Vector *vector, void *value, equal);

void vector_pop(Vector *vector, void *value);

void vector_get(Vector *vector, void *value, size_t index);

void vector_clear(Vector *vector);

void vector_print(Vector *vector, void_to_str);
char* str2str(void *a);

bool vector_contains(Vector *vector, void *value, equal);
bool str_equal(const void *a, const void *b);

Vector file_to_string_array(char *file_path);

Vector string_split(char *str, const char * delimiter);

void string_trim_right(char *str, const char delimiter);

#endif
