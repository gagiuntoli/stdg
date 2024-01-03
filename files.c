#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** file_to_string_array(char *file_path) {
	FILE *fp = NULL;
	size_t len = 0;
	size_t read = 0;

	char **lines = NULL;
	char *line = NULL;

	fp = fopen(file_path, "r");
	if (fp == NULL) {
		printf("[stdg] Error opening file: %s\n", file_path);
		return NULL;
	}

	size_t count = 0;
	while ((read = getline(&line, &read, fp)) != -1) {
		count++;
	}

	lines = malloc(count * sizeof(char*));

	rewind(fp);

	size_t i = 0;
	while ((read = getline(&line, &read, fp)) != -1) {
		lines[i] = malloc(read * sizeof(char));
		strcpy(lines[i++], line);
	}

	fclose(fp);

	return lines;
}
