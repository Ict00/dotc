#include "dotc/mem.h"
#include "dotc/string.h"
#include <stdio.h>

int main() {
	string_t a = str("Some");
	string_t b = str("Some");
	string_t c = dc_strcat(&a, &b);

	set3die(3, src(&a), src(&b), src(&c));

	printf("%d\n", dc_equal(&a, &b));
	
	die();	
}
