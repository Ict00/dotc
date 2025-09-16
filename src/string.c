#include "dotc/string.h"
#include <string.h>
#include <stdlib.h>

string_t str(const char *source) {
	int ln = strlen(source);
	string_t result = (string_t){.len = ln};
	char* new_content = strdup(source);

	result.content = new_content;

	return result;
}

void dc_strappend(string_t *dest, const string_t *str) {
	int nl = dest->len + str->len;
	dest->content = realloc(dest->content, nl+1);
	strcpy((dest->content)+dest->len, str->content);
	dest->len = nl;
}

void dc_cappend(string_t *dest, char c) {
	dest->content = realloc(dest->content, dest->len+2);
	dest->content[dest->len] = c;
	dest->content[dest->len+1] = 0;
	dest->len = dest->len + 1;
}

char* src(const string_t* str) {
	return str->content;
}

int dc_strlen(const string_t *str) {
	return str->len;
}

string_t dc_strcat(const string_t *first, const string_t *second) {
	int nl = first->len + second->len;
	char* new_content = malloc(sizeof(char) * (nl+1));

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

bool dc_endswith(const string_t *str, const string_t *str2) {
	if (str2->len > str->len) return false;

	int i = str->len-1, b = str2->len-1;
	
	for (; i != 0 && b != 0;) {
		if (str->content[i] != str2->content[b]) return false;
		i--; b--;
	}

	return true;
}

bool dc_startswith(const string_t *str, const string_t *str2) {
	if (str2->len > str->len) return false;
	
	int i = 0, b = 0;

	for (; i < str->len && b < str2->len;) {
		if (str->content[i] != str2->content[b]) return false;
		i++; b++;
	}

	return true;
}

string_t dc_insert(string_t *src, string_t *str, int position) {
	if (position > src->len || position < 0) {
		return (string_t) {
			.content = strdup(src->content),
			.len = src->len
		};
	}
	
	string_t result = (string_t) { };

	int nl = src->len + str->len;
	char* new_content = malloc(sizeof(char) * (nl + 1));
	
	int i = 0;
	int b = 0;

	for (; i <= src->len; i++) {
		if (position == i) {
			for (int t = 0; t <= str->len; t++) {
				new_content[b] = str->content[t];
				b++;
			}
		}

		new_content[b] = src->content[i];
		b++;
	}
	new_content[b] = 0;

	result.len = nl;
	result.content = new_content;

	return result;
}

int dc_split(const string_t *src, string_t **dest, char separator) {
	int current = 0;
	size_t last_size = 32;

	if ((*dest) == NULL)
		(*dest) = malloc(sizeof(string_t)*last_size);
	(*dest) = realloc((*dest), sizeof(string_t)*last_size);
	
	for (int i = 0; src->content[i] != 0; i++) {
		if (src->content[i] == separator) {
			if (current >= last_size) {
				last_size *= 2;
				(*dest) = realloc((*dest), sizeof(string_t)*last_size);
			}
			
			current++;
			continue;
		}

		dc_cappend(&((*dest)[current]), src->content[i]);
	}
	current++;
	

	return current;
}
