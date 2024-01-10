#include "stdg.h"

/* Splits a string depending on the delimiter passed. Returns a vector with every part. */
Vector *string_split(char *str, const char *delimiter) {
	Vector *vector = vector_create();
	char* token = strtok(str, " ");

	while (token != NULL) {
		char *token_dup = strdup(token);
		string_trim_right(token_dup, '\n');

		Value *value = malloc(sizeof(Value) + strlen(token_dup) + 1);
		value->size = strlen(token_dup) + 1;
		memcpy(value->data, token_dup, value->size);
		vector_push(vector, value);

		token = strtok(NULL, delimiter);
		free(token_dup);
		free(value);
	}
	return vector;
}

void string_trim_right(char *str, const char delimiter) {
	size_t len = strlen(str);
	int i = len-1;

	for (; i >= 0; i--) {
		if (str[i] != delimiter) {
			break;
		}
	}

	str[i+1] = '\0';
}
