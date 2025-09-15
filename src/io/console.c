#include "dotc/io/console.h"
#include "dotc/mem.h"
#include "dotc/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string_t read_line() {
	string_t result = (string_t){ };
	char* content = NULL;
	char* readc = NULL;
	int c = 0;

	int read = getline(&readc, &c, stdin);
	
	if (read == -1) {
		exit(read); // More detailed logs later
	}
	content = dc_malloc(sizeof(char) * (read));

	strncpy(content, readc, read-1);
	free(readc);

	result.content = strdup(content);
	result.len = strlen(content);

	return result;
}
