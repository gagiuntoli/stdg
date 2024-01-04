#include "stdg.h"

Vector vector_create(unsigned int data_size) {
    void *data = malloc(data_size);

    Vector vector = {.data_size = data_size, .length = 0, .capacity = 1, .data = data};

    return vector;
}

void vector_push(Vector *vector, void *value) {
    void *data;
    if (vector->length == vector->capacity) {
        vector->capacity *= 2;
        data = malloc(vector->data_size * vector->capacity);
        memcpy(data, vector->data, vector->data_size * vector->length);
        free(vector->data);
        vector->data = data;
    }

    memcpy(vector->data + vector->data_size * vector->length, value, vector->data_size);
    vector->length++;
}

void vector_push_unique(Vector *vector, void *value, equal equal_) {
    if (!vector_contains(vector, value, equal_)) {
        vector_push(vector, value);
    }
}

void vector_pop(Vector *vector, void *value) {
    if (vector->length > 0) {
        vector->length--;
        memcpy(value, vector->data + vector->data_size * vector->length, vector->data_size);
    }
}

void vector_get(Vector *vector, void *value, size_t index) {
    if (index < vector->length) {
        memcpy(value, vector->data + vector->data_size * index, vector->data_size);
    }
}

bool vector_contains(Vector *vector, void *value, equal equal_) {
    for (int i = 0; i < vector->length; i++) {
        void *current = NULL;
        vector_get(vector, &current, i);
        if (current == NULL) {
            exit(1);
        }
        if (equal_(current, value)) {
            return true;
        }
    }
    return false;
}

void vector_clear(Vector *vector) {
    vector->capacity = 0;
    vector->length = 0;
    free(vector->data);
    vector->data = NULL;
}

char* str2str(void *value) {
	return value;
}

bool str_equal(const void *a, const void *b) {
	return strcmp(a, *(char**)b) == 0 ? true : false;
}

void vector_print(Vector *vector, char* void2str(void*)) {
    printf("[");
    for (int i = 0; i < vector->length; i++) {
        char *value;
        vector_get(vector, &value, i);
        printf("%s%s", void2str(value), i < (vector->length - 1) ? "," : "");
    }
    printf("]\n");
}
