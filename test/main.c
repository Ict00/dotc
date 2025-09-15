#include "dotc/io/console.h"
#include "dotc/iter.h"
#include "dotc/string.h"
#include "dotc/syntax.h"
#include "dotc/mem.h"
#include <stdio.h>

int main() {
	scope(ctx, {
		printf("> "); string_t a = read_line();
		printf("> "); string_t b = read_line();
		printf("> "); string_t c = read_line();
		
		void** strg = dc_storage(3, &a, &b, &c);
		
		// Free those after exiting the scope
		kaddv(&ctx, 4, src(&a), src(&b), src(&c), strg);
		
		iterable_t t = iterable(strg, 3);

		foreach (i, t) {
			printf("%s\n", src(i));
		}

	});

	return 0;
}
