#include "stdg.h"

/* Splits a string depending on the delimiter passed. Returns a vector with every part. */
Vector string_split(char *str, const char * delimiter) {
	Vector vector = vector_create(sizeof(char *));
	char* token = strtok(str, " ");

	while (token != NULL) {
		char *token_dup = strdup(token);
		vector_push(&vector, &token_dup);
		token = strtok(NULL, delimiter);
	}
	return vector;
}
