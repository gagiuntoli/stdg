#include "stdg.h"

Vector file_to_string_array(char *file_path) {
	FILE *fp = NULL;
	size_t len = 0;
	size_t read = 0;

	char *line = NULL;

	fp = fopen(file_path, "r");
	if (fp == NULL) {
		printf("[stdg] Error opening file: %s\n", file_path);
		exit(1);
	}

	Vector lines = vector_create(sizeof(char *));
	while ((read = getline(&line, &len, fp)) != -1) {
		vector_push(&lines, &line);
		line = NULL;
	}

	fclose(fp);

	return lines;
}
