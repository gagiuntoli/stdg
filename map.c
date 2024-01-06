#include "stdg.h"

unsigned long hash(const char *str) {
	unsigned long result = 0;
	int c;
	while ((c = *str++) != 0) {
		result += c;
		result *= 17;
		result %= 256;
	}
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

int map_insert(Map *map, const char *key, const char *value) {
	unsigned long index = hash(key);
	size_t value_len = strlen(value);

	if (map->buckets[index] == NULL) {
		Bucket *new_bucket = malloc(sizeof(Bucket));
		new_bucket->key = strdup(key);
		new_bucket->value = strdup(value);
		new_bucket->next = NULL;
		map->buckets[index] = new_bucket;
	}

	Bucket *curr_bucket = map->buckets[index];

	while (curr_bucket->next != NULL) {
		// check if a bucket matches the key 
		if (strcmp(curr_bucket->key, key) == 0) {
			// check if the existing size is less that what is needed
			if (strlen(curr_bucket->value) < value_len) {
				if (realloc(curr_bucket->value, value_len + 1) == NULL) {
					return 1;
				}
			}

			strcpy(curr_bucket->value, value);
			return 0;
		}
		curr_bucket = curr_bucket->next;
	}
	// they key wasn't found so insert a new bucket
	Bucket *new_bucket = malloc(sizeof(Bucket));
	new_bucket->key = strdup(key);
	new_bucket->value = strdup(value);
	new_bucket->next = NULL;

	curr_bucket->next = new_bucket;
	return 0;
}

char *map_get(Map *map, const char *key) {
	unsigned long index = hash(key);

	Bucket *curr_bucket = map->buckets[index];

	while (curr_bucket != NULL) {
		// check if a bucket matches the key 
		if (strcmp(curr_bucket->key, key) == 0) {
			return curr_bucket->value;
		}
		curr_bucket = curr_bucket->next;
	}
	return NULL;
}
