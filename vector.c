#include "stdg.h"

Vector *vector_create() {
    Vector *vector = malloc(sizeof(Vector));

    vector->capacity = 1;
    vector->values = malloc(vector->capacity * sizeof(Value *));
    vector->length = 0;

    return vector;
}

int vector_push(Vector *vector, const Value *value) {
    if (vector->length == vector->capacity) {
        vector->capacity *= 2;
        vector->values = realloc(vector->values, vector->capacity * sizeof(Value *));
    }

    vector->values[vector->length] = malloc(sizeof(Value) + value->size);
    memcpy(vector->values[vector->length], value, sizeof(Value) + value->size);
    vector->length++;

    return 0;
}

/* pushes a value to the vector if it doesn't exist and returns 0.
 * If the value already exists, nothing happens and the function returns 1.
 */
int vector_push_unique(Vector *vector, const Value *value) {
    if (!vector_contains(vector, value)) {
        vector_push(vector, value);
        return 0;
    }
    return 1;
}

Value *vector_pop(Vector *vector) {
    if (vector->length > 0) {
        vector->length--;

        Value *last = vector->values[vector->length];
        Value *result = malloc(sizeof(Value) + last->size);
        memcpy(result, last, sizeof(Value) + last->size);

        free(last);

        return result;
    }
    return NULL;
}

Value *vector_get(Vector *vector, size_t index) {
    if (index < vector->length) {
        Value *value = malloc(sizeof(Value) + vector->values[index]->size);
        memcpy(value, vector->values[index], sizeof(Value) + vector->values[index]->size);
        return value;
    }
    return NULL;
}

int vector_get_index(Vector *vector, const Value *value) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->values[i]->size == value->size && memcmp(vector->values[i]->data, value->data, value->size) == 0) {
            return i;
        }
    }
    return -1;
}

bool vector_contains(Vector *vector, const Value *value) {
    for (int i = 0; i < vector->length; i++) {
        Value *current = vector->values[i];
        if (current == NULL) {
            exit(1);
        }
        if (current->size == value->size && memcmp(current->data, value->data, value->size) == 0) {
            return true;
        }
    }
    return false;
}

int vector_clear(Vector *vector) {
    vector->capacity = 0;
    for (int i = 0; i < vector->length; i++) {
        free(vector->values[i]);
    }
    free(vector->values);
    return 0;
}

void vector_print(Vector *vector, void print_value(const Value *value)) {
    printf("[");
    for (int i = 0; i < vector->length; i++) {
        Value *value = vector_get(vector, i);
        const char *separator = (i != vector->length-1) ? ", " : "";
        print_value(value);
        printf("%s",separator);
    }
    printf("]\n");
}
