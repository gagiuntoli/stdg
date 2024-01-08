#include "stdg.h"
#include <assert.h>

char *print_key(const Key *key) {
	return (char *)key->data;
}
char *print_value(const Value *value) {
	return (char *)value->data;
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

int main() {
	Map *map = map_create();

	insert(map, "person 1", "guido");
	insert(map, "person 2", "peter");
	insert(map, "p3", "Saul");
	insert(map, "A name", "A surname");

	//Value *res = map_get(map, key);
	//printf("key = %s val = %s\n", key->data, res->data);

	map_print(map, print_key, print_value);

	printf("TEST: Map Succeed!\n");
	return 0;
}
