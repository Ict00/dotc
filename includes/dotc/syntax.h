#pragma once

#define object(name, stdef, ...)\
	struct { stdef } typedef name; \
	__VA_ARGS__
#define foreach(el, iterable_list) for (void* el = next(&(iterable_list)); el != NULL; el = next(&(iterable_list)))
