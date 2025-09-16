#pragma once

#include "dotc/string.h"

/*
 * Returns malloc'd string_t. Don't forget to free string_t->content
 */
string_t read_line();
