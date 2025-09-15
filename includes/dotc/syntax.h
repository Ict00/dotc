#pragma once

#define object(name, stdef, ...)\
	struct { stdef } typedef name; \
	__VA_ARGS__
#define fndef(name, returntype, param1, ...) typedef returntype (* name)(param1 __VA_OPT__(,)__VA_ARGS__)
#define range(i, start, end) for (int i = start; i < end; i++)
#define scope(x, y) context_t x = create_mctx(); y; kdone(&x);
#define foreach(el, iterable_list) for (void* el = next(&(iterable_list)); el != NULL; el = next(&(iterable_list)))
