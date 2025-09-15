#include "dotc/io/console.h"
#include "dotc/iter.h"
#include "dotc/mem.h"
#include "dotc/string.h"
#include "dotc/syntax.h"
#include <stdio.h>

object(human,
	string_t name;,
	void say_hello(human* THIS) {
		printf("Hello, %s!\n", src(&THIS->name));
	}
);

int main() {
	human u = (human){ .name =str("Ict") };
	say_hello(&u);

	return 0;
}
