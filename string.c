#include "stdg.h"

/* Splits a string depending on the delimiter passed. Returns a vector with every part. */
Vector string_split(char *str, const char * delimiter) {
	Vector vector = vector_create(sizeof(char *));
	char* token = strtok(str, " ");

	while (token != NULL) {
		char *token_dup = strdup(token);
		string_trim_right(token_dup, '\n');
		vector_push(&vector, &token_dup);
		token = strtok(NULL, delimiter);
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
