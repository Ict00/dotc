#pragma once

#include <stdbool.h>

struct {
	char* content;
	int len;
} typedef string_t;


string_t str(const char* source);


char* src(const string_t* str);


int dc_strlen(const string_t* str);


string_t dc_strcat(string_t* first, const string_t* second);


bool dc_equal(const string_t* first, const string_t* second);


bool dc_endswith(const string_t* str, const string_t* str2);


bool dc_startswith(const string_t* str, const string_t* str2);


string_t dc_insert(string_t* src, string_t* str, int position);
