#include "dotc/mem.h"
#include "dotc/string.h"
#include <stdio.h>

int main() {
	string_t a = str("Some");
	string_t b = str("TEST");
	string_t ins = dc_insert(&a, &b, 4);

	set3die(3, src(&a), src(&b), src(&ins));

	printf("%s\n", src(&ins));
	
	die();	
}
