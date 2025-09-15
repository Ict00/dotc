#include "dotc/io/console.h"
#include "dotc/mem.h"
#include "dotc/string.h"
#include <stdio.h>

int main() {
	printf("> ");
	string_t a = read_line();

	set3die(1, src(&a));

	printf("%s\n", src(&a));
	
	die();	
}
