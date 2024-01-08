#include "stdg.h"
#include <assert.h>

void print_key(const Key *key) {
	printf("%s", (char *)key->data);
}

void print_value(const Value *value) {
	printf("%s", (char *)value->data);
}

void insert(Map *map, const char *key_c, const char *value_c) {
	Key *key = malloc(sizeof(Key) + strlen(key_c) + 1);
	key->size = strlen(key_c) + 1;
	strcpy(key->data, key_c);

	Value *value = malloc(sizeof(Value) + strlen(value_c) + 1);
	value->size = strlen(value_c) + 1;
	strcpy(value->data, value_c);

	map_insert(map, key, value);
}

char *get(Map *map, const char *key_c) {
	Key *key = malloc(sizeof(Key) + strlen(key_c) + 1);
	key->size = strlen(key_c) + 1;
	strcpy(key->data, key_c);

	Value *value = map_get(map, key);
	if (value != NULL) {
		return (char *)value->data;
	}
	return NULL;
}

int main() {
	Map *map = map_create();

	insert(map, "person 1", "guido");
	insert(map, "person 2", "peter");
	insert(map, "p3", "Saul");
	insert(map, "A name", "A surname");

	assert(strcmp(get(map, "person 1"), "guido") == 0);
	assert(strcmp(get(map, "person 2"), "peter") == 0);
	assert(strcmp(get(map, "p3"), "Saul") == 0);
	assert(strcmp(get(map, "A name"), "A surname") == 0);

	map_print(map, print_key, print_value);

	printf("TEST: Map Succeed!\n");
	return 0;
}
