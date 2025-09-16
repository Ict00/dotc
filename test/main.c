#include "dotc/string.h"
#include "dotc/syntax.h"
#include "dotc/mem.h"
#include <stdio.h>

int main() {
	scope(ctx, {
		string_t a = str("Wow it:actually works");
	
		string_t* b = NULL;

		int count = dc_split(&a, &b, ':');

		// Free all of those after exiting 'scope'
		
		kaddv2(&ctx, b[0].content, b[1].content, b[2].content, b, NULL);

		range(i, 0, count) {
			printf("%d -- %s\n", b[i].len, b[i].content);
		}
	});

	return 0;
}
