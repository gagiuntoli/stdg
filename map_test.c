#include "stdg.h"
#include <assert.h>

int main() {
	Map *map = map_create();

	// insert `const char*`
	Key *key = malloc(sizeof(Key) + 5);
	key->size = 5;
	strcpy(key->data, "name");

	Value *value = malloc(sizeof(Value) + 6);
	value->size = 6;
	strcpy(value->data, "guido");

	map_insert(map, key, value);

	Value *res = map_get(map, key);
	printf("key = %s val = %s\n", key->data, res->data);

	printf("TEST: Map Succeed!\n");
	return 0;
}
