#include "dotc/string.h"
#include "dotc/mem.h"
#include <string.h>

string_t str(const char *source) {
	int ln = strlen(source);
	string_t result = (string_t){.len = ln};
	char* new_content = dc_malloc(sizeof(char)*(ln+1));
	int i = 0;

	for (; i < ln; i++) {
		new_content[i] = source[i];
	}

	new_content[i] = 0;
	result.content = new_content;

	return result;
}

char* src(const string_t* str) {
	return str->content;
}

int dc_strlen(const string_t *str) {
	return str->len;
}

string_t dc_strcat(string_t *first, const string_t *second) {
	int nl = first->len + second->len;
	char* new_content = dc_malloc(sizeof(char) * (nl+1));

	strcpy(new_content, first->content);
	int b = 0;
	int i = first->len;
	for (; second->content[b] != 0; b++) {
		new_content[i] = second->content[b];
		i++;
	}
	new_content[i] = 0;
	
	return (string_t) {.content = new_content, .len = nl};
}


bool dc_equal(const string_t* first, const string_t* second) {
	if (first->len != second->len) return false;
	
	for (int i = 0; first->content[i] != 0; i++) {
		if (first->content[i] != second->content[i]) return false;
	}

	return true;
}
