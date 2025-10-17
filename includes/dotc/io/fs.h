#pragma once

#include "dotc/iter.h"
#include "dotc/string.h"
#include <stdbool.h>

bool is_file(const char* path);
bool is_dir(const char* path);
bool exists(const char* path);

string_t read_file(const char* path);
iterable_t read_dir(const char* path);
