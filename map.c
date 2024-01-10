#include "stdg.h"
#include <assert.h>

int hash(const Key *key) {
	int result = 0, i, c;
	for (i = 0; i < key->size; i++) {
		c = key->data[i];
		result += c;
		result *= 17;
		result %= 256;
	}
	printf("hash = %d\n", result);
	assert(result >= 0 && result < 256);
	return result;
}

Map *map_create() {
	Map *map = malloc(sizeof(Map));
	map->buckets = malloc(TOTAL_BUCKETS * sizeof(Bucket*));

	int i;
	for (i = 0; i < TOTAL_BUCKETS; i++) {
		map->buckets[i] = NULL;
	}
	return map;
}

Bucket *bucket_create(const Key *key, const Value *value) {
	Bucket *bucket = malloc(sizeof(Bucket));

	bucket->value = malloc(sizeof(Value) + value->size);
	bucket->value->size = value->size;
	memcpy(bucket->value->data, value->data, value->size);

	bucket->key = malloc(sizeof(Key) + key->size);
	bucket->key->size = key->size;
	memcpy(bucket->key->data, key->data, key->size);

	bucket->next = NULL;
	return bucket;
}

int map_insert(Map *map, const Key *key, const Value *value) {
	int index = hash(key);

	if (index >= TOTAL_BUCKETS) {
		return 1;
	}

	if (map->buckets[index] == NULL) {
		Bucket *new_bucket = bucket_create(key, value);
		map->buckets[index] = new_bucket;
		return 0;
	}

	Bucket *previous = map->buckets[index];
	Bucket *current = previous->next;

	while (current != NULL) {
		// check if a bucket with the same key already exists in the list 
		if (current->key->size == key->size && memcmp(current->key->data, key->data, key->size) == 0) {
			free(current->value);

			current->value = malloc(sizeof(Value) + value->size);
			current->value->size = value->size;
			memcpy(current->value->data, value->data, value->size);
			
			return 0;
		}
		previous = current;
		current = current->next;
	}

	// insert in the last position
	Bucket *new_bucket = bucket_create(key, value);
	previous->next = new_bucket;
	return 0;
}

Value *map_get(Map *map, const Key *key) {
	int index = hash(key);

	Bucket *current = map->buckets[index];

	while (current != NULL) {
		if (memcmp(current->key->data, key->data, key->size) == 0) {
			return current->value;
		}
		current = current->next;
	}
	return NULL;
}

bool map_exists(Map *map, const Key *key) {
 	int index = hash(key);

 	Bucket *current = map->buckets[index];

	while (current != NULL) {
		if (current->key->size == key->size && memcmp(current->key->data, key->data, key->size) == 0) {
			return true;
		}
		current = current->next;
	}
	return false;
}

void map_print(Map *map, void print_key(const Key *key), void print_value(const Value *value)) {
	int i;
	bool first_printed = false;
	printf("{");
	for (i = 0; i < TOTAL_BUCKETS; i++) {
		Bucket *current = map->buckets[i];
		while (current != NULL) {
			const char *separator = first_printed ? ", " : "";
			printf("%s[", separator); 
			print_key(current->key);
			printf("]: ");
			print_value(current->value);

			current = current->next;

			if (!first_printed)
				first_printed = true;
		}
	}
	printf("}\n");
}
