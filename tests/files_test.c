#include "stdg.h"
#include <assert.h>

void print_value(const Value *value) {
	printf("%s", (char *)value->data);
}

int main() {
	Vector *vector = files_get_lines("./tests/inputa.dat");

	assert(vector->length == 12);
	vector_print(vector, print_value);

	printf("TEST: Files Succeed!\n");
	return 0;
}
