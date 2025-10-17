#include "dotc/iter.h"
#include "dotc/string.h"
#include "dotc/syntax.h"
#include "dotc/mem.h"
#include "dotc/io/fs.h"

#include <stdio.h>

void free_str(context_t* ctx, void* str) {
	kadd(ctx, cast(str, string_t*)->content);
}

int main() {
	scope(ctx, {
		string_t a = str("Wow it:actually works");

		iterable_t iter = dc_split_iter(&a, ':');
		
		kaddc2(&ctx, &iter, free_str);
		
		foreach(item, iter) {
			printf("%s\n", src(cast(item, string_t*)));
		} iter_reset(&iter);


		printf("CONTENT:\n%s\n", src2(read_file("Project")));
	});

	return 0;
}
