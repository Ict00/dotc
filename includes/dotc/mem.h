#pragma once
#include <stddef.h>

void set2die(void* ptr);


void set3die(int count, ...);


void die();


void* dc_malloc(size_t size);


void* dc_realloc(void* ptr, size_t new_size);


void dc_free(void* ptr);
