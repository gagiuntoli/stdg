#ifndef STDG_H
#define STDG_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
// Vector 
//
typedef struct {
    size_t data_size; // size of each element in bytes
    size_t length;    // quantity of elements currently stored
    size_t capacity;  // available capacity
    char *data;
} Vector;

typedef bool (*equal)(const void *a, const void *b);
typedef char* (*void_to_str)(void *value);

Vector *vector_create(size_t data_size);
void vector_push(Vector *vector, void *value);
void vector_push_unique(Vector *vector, void *value, equal);
void vector_pop(Vector *vector, void *value);
void vector_get(Vector *vector, void *value, size_t index);
void vector_clear(Vector *vector);
void vector_print(Vector *vector, void_to_str);
char* str2str(void *a);

bool vector_contains(Vector *vector, void *value, equal);
bool str_equal(const void *a, const void *b);

//
// Files
//
Vector *file_to_string_array(char *file_path);

//
// String
//
Vector *string_split(char *str, const char *delimiter);
void string_trim_right(char *str, const char delimiter);


//
// Map 
//
#define TOTAL_BUCKETS 256

typedef struct Bucket_ {
	char *key;
	char *value;
	struct Bucket_ *next;
} Bucket;

typedef struct {
	Bucket **buckets;
} Map;

unsigned long hash(const char *str);
Map *map_create();
int map_insert(Map *map, const char *key, const char *value);
char *map_get(Map *map, const char *key);

#endif
