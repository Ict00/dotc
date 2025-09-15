#include "dotc/iter.h"
#include "dotc/mem.h"
#include <stdarg.h>
#include <stdio.h>

iterable_t iterable(void** storage, int count) {
	return (iterable_t) { .storage = storage, .count = count, .current = 0 };
}

void** dc_storage(int count, ...) {
	va_list args;
	va_start(args, count);
	
	void** result = dc_malloc(sizeof(void**)*count);
	int c = 0;

	for (int i = 0; i < count; i++) {
		void* el = va_arg(args, void*);
		result[c] = el;
		c++;
	}

	va_end(args);

	return result;
}

void* next(iterable_t *iter) {
	if (iter->current == iter->count) return NULL;

	void* to_ret = iter->storage[iter->current];

	if (iter->current < iter->count)
		iter->current++;
	
	return to_ret;
}

void* next2(iterable_t *iter) {
	void* to_ret = iter->storage[iter->current];

	if (iter->current + 1 < iter->count)
		iter->current++;
	else
		iter->current = 0;
	
	return to_ret;
}
