#include "dotc/io/console.h"
#include "dotc/mem.h"
#include "dotc/string.h"
#include <stdio.h>
#include <string.h>

string_t read_line() {
	string_t result = (string_t){ };
	char* content = dc_malloc(sizeof(char)*1);
	content[0] = 0;

	scanf("%s", content);

	result.content = content;
	result.len = strlen(content);

	return result;
}
