#include "dotc/io/console.h"
#include "dotc/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string_t read_line() {
	string_t result = (string_t){ };
	char* readc = NULL;
	unsigned long int c = 0;

	int read = getline(&readc, &c, stdin);

	if (read == -1) {
		exit(read); // More detailed logs later
	}

	result.content = strdup(readc);
	result.len = strlen(readc);

	return result;
}
