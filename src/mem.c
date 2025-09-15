#include "dotc/mem.h"
#include "dotc/syntax.h"
#include <stdarg.h>
#include <stdlib.h>

void kadd(context_t *THIS, void *ptr) {
	int current = THIS->count;

	THIS->ptrs = realloc(THIS->ptrs, sizeof(void*) * (current+1));
	
	THIS->ptrs[THIS->count] = ptr;
	THIS->count++;
}

void kdone(context_t *THIS) {
	range(i, 0, THIS->count) {
		if (THIS->ptrs[i] != NULL)
			free(THIS->ptrs[i]);
	}

	free(THIS->ptrs);
}

void kaddv(context_t *THIS, int count, ...) {
	va_list args;
	
	va_start(args, count);

	range(i, 0, count) {
		void* arg = va_arg(args, void*);
		kadd(THIS, arg);
	}

	va_end(args);
}

context_t create_mctx() {
	return (context_t) { .ptrs = malloc(sizeof(void*)*1), .count=0 };
}
