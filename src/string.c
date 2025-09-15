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

bool dc_endswith(const string_t *str, const string_t *str2) {
	int i = str->len-1, b = str2->len-1;
	
	for (; i != 0 && b != 0;) {
		if (str->content[i] != str2->content[b]) return false;
		i--; b--;
	}

	return true;
}

bool dc_startswith(const string_t *str, const string_t *str2) {
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
	char* new_content = dc_malloc(sizeof(char) * (nl + 1));
	
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
