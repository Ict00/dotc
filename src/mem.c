#include "dotc/mem.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static void* DIE_BUFFER[4096*4];
static int current = 0;
static int cap = 4096*4;

void set2die(void *ptr) {
	if (current + 1 < cap) {
		DIE_BUFFER[current] = ptr;
		current++;
	}
}

void set3die(int count, ...) {
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		void* ptr = va_arg(args, void*);
		set2die(ptr);
	}

	va_end(args);
}

void die() {
	for (int i = 0; i < current; i++) {
		if (DIE_BUFFER[i] != NULL) {
			free(DIE_BUFFER[i]);
		}
	}
	current = 0;
}

void* dc_malloc(size_t size) {
	return malloc(size);
}


void* dc_realloc(void* ptr, size_t new_size) {
	for (int i = 0; i < current; i++) {
		if (ptr == DIE_BUFFER[i]) {
			DIE_BUFFER[i] = realloc(ptr, new_size);
			return DIE_BUFFER[i];
		}
	}

	return realloc(ptr, new_size);
}


void dc_free(void* ptr) {
	for (int i = 0; i < current; i++) {
		if (ptr == DIE_BUFFER[i]) {
			DIE_BUFFER[i] = NULL;
			break;
		}
	}

	free(ptr);
}
