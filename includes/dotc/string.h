#pragma once

#include <stdbool.h>

struct {
	char* content;
	int len;
} typedef string_t;

/*
 * Source is strdup'ed, so don't forget to free string_t->content
*/
string_t str(const char* source);

/*
 * Those use realloc!!!!!
 */
void dc_strappend(string_t* dest, const string_t* str);
void dc_cappend(string_t* dest, char c);

/*
 * Equal to str->content
*/
char* src(const string_t* str);

/*
 * Equal to str->len
*/
int dc_strlen(const string_t* str);

/*
 * Returns new string_t (first + second); Don't forget to free string_t->content
*/

string_t dc_strcat(const string_t* first, const string_t* second);

/* Obvious */
bool dc_equal(const string_t* first, const string_t* second);


/* Obvious */
bool dc_endswith(const string_t* str, const string_t* str2);


/* Obvious */
bool dc_startswith(const string_t* str, const string_t* str2);

/*
 * Returns new string_t; Don't forget to free string_t->content!!
*/
string_t dc_insert(string_t* src, string_t* str, int position);

/*
 * Returns total count of strings
 * NOTE: if dest is a pointer to pointer which is NULL, then it'll be malloc'd; if not - realloc'd;
 * EACH STRING SHOULD BE FREE'D; IT'S MALLOC'D, TOO!
 */
int dc_split(const string_t* src, string_t** dest, char separator);
