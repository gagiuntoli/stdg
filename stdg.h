#ifndef STDG_H
#define STDG_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Key_ {
	size_t size;
	char data[];
} Key;

typedef struct Value_ {
	size_t size;
	char data[];
} Value;

//
// Vector 
//
typedef struct Vector_ {
    Value **values;
    size_t capacity;
    size_t length;
} Vector;

Vector *vector_create();
int vector_push(Vector *vector, const Value *value);
int vector_push_unique(Vector *vector, const Value *value);
Value *vector_pop(Vector *vector);
Value *vector_get(Vector *vector, size_t index);
int vector_clear(Vector *vector);
void vector_print(Vector *vector, void print_value(const Value *value));
bool vector_contains(Vector *vector, const Value *value);

//
// Files
//
Vector *files_get_lines(const char *file_path);

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
	struct Bucket_ *next;
        Key *key;
        Value *value;
} Bucket;

typedef struct {
	Bucket **buckets;
} Map;

int hash(const Key *key);
Map *map_create();
int map_insert(Map *map, const Key *key, const Value *value);
Value *map_get(Map *map, const Key *key);
void map_print(Map *map, void print_key(const Key *key), void print_value(const Value *value));

#endif
