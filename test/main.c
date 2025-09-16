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
		
		// Free those after exiting the scope
		kaddv2(&ctx, src(&a), src(&b), src(&c), NULL);
		
		iterable_t t = iterable2(&a, &b, &c, NULL);

		kadd(&ctx, t.storage); // Free this too

		foreach (i, t) {
			printf("%s\n", src(i));
		}

	});

	return 0;
}
