#include "stdg.h"

Vector *file_to_string_array(char *file_path) {
	FILE *fp = NULL;
	size_t len = 0;
	size_t read = 0;

	char *line = NULL;

	fp = fopen(file_path, "r");
	if (fp == NULL) {
		printf("[stdg] Error opening file: %s\n", file_path);
		exit(1);
	}

	Vector *vector = vector_create();
	while ((read = getline(&line, &len, fp)) != -1) {
		Value *value = malloc(sizeof(Value) + strlen(line) + 1);
		value->size = strlen(line) + 1;
		memcpy(value->data, line, value->size);
		vector_push(vector, value);
		line = NULL;
	}

	fclose(fp);

	return vector;
}
