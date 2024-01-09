#include <assert.h>
#include "stdg.h"

void print_value(const Value *value) {
    int val;
    memcpy(&val, value->data, sizeof(int));
    printf("%d", val);
}

int main() {
    Vector *vector = vector_create();
    assert(vector->length == 0);

    int val = 2;
    Value *value = malloc(sizeof(Value) + sizeof(int));
    value->size = sizeof(int);
    memcpy(value->data, &val, sizeof(int));

    vector_push(vector, value);
    assert(vector->length == 1);

    Value *value_get = vector_get(vector, 1);
    assert(value_get == NULL);

    value_get = vector_get(vector, 0);
    assert(value_get != NULL);
    memcpy(&val, value_get->data, sizeof(int));
    assert(val == 2);

    vector_print(vector, print_value);

    val = 1;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == false);
    val = 2;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == true);
    val = 3;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == false);

    Value *value_pop = vector_pop(vector);
    assert(value_pop != NULL);
    assert(vector->length == 0);
    memcpy(&val, value_pop->data, sizeof(int));
    assert(val== 2);

    for (val = 1; val <= 1000; val++) {
    	Value *value = malloc(sizeof(Value) + sizeof(int));
    	value->size = sizeof(int);
    	memcpy(value->data, &val, sizeof(int));

    	vector_push(vector, value);
    	assert(vector->length == val);
	free(value);
    }

    val = 0;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == false);
    val = 1;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == true);
    val = 500;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == true);
    val = 1000;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == true);
    val = 1001;
    memcpy(value->data, &val, sizeof(int));
    assert(vector_contains(vector, value) == false);

    int val1;
    for (val = 1000; val >= 1; val--) {
    	assert(vector->length == val);
	Value *value_pop = vector_pop(vector);
	assert(value_pop != NULL);
    	memcpy(&val1, value_pop->data, sizeof(int));

	assert(val1 == val);
	free(value_pop);
    }

    value_pop = vector_pop(vector);
    assert(value_pop == NULL);

    assert(vector->capacity == 1024);

    for (val = 1; val <= 1000; val++) {
	int val_a = val % 10;
    	Value *value = malloc(sizeof(Value) + sizeof(int));
    	value->size = sizeof(int);
    	memcpy(value->data, &val_a, sizeof(int));

    	vector_push_unique(vector, value);
	free(value);
    }

    assert(vector->length == 10);
    vector_print(vector, print_value);

    int res = vector_clear(vector);
    assert(res == 0);
    
    printf("TEST: Vector Succeed!\n");
    return 0;
}
