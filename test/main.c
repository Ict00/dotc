#include "dotc/io/console.h"
#include "dotc/iter.h"
#include "dotc/string.h"
#include "dotc/syntax.h"
#include "dotc/mem.h"
#include <stdio.h>

int main() {
	scope(ctx, {
		int a = 0; int b = 1; int c = 2;
		
		iterable_t t = iterable2(&a, &b, &c, NULL);

		kadd(&ctx, t.storage); // Free this

		foreach (i, t) {
			printf("%d\n", *(int*)i);
		}

	});

	return 0;
}
