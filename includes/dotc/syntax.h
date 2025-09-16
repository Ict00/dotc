#pragma once

/*
 * Example usage of object(...) macro:
 * object(obj,
 * 	int a;
 * 	int b;
 * 	int c;
 * ,
 * 	void smth(obj* THIS) {
 *		THIS->a = THIS->b + THIS->c;
 * 	})
 */
#define object(name, stdef, ...)\
	struct { stdef } typedef name; \
	__VA_ARGS__
/*
 * Usage of fndef(...) macro:
 * fndef(NAME_OF_FUNCTION_TYPE, RETURN TYPE, PARAM1, PARAM2..., PARAM_N);
 */
#define fndef(name, returntype, param1, ...) typedef returntype (* name)(param1 __VA_OPT__(,)__VA_ARGS__)

/* range(a, b, c) macro is equal to:
 * for (int a = b; a < c; a++)
 */
#define range(i, start, end) for (int i = start; i < end; i++)

/* Example usage of scope(...) macro:
 * scope(ctx, {
 * 	int* some_ptr = malloc(sizeof(int));
 *	kadd(&ctx, &some_ptr);
 *
 *	...
 * });
 * 
 * After exiting scope, some_ptr will be free'd
 */

#define scope(x, y) context_t x = create_mctx(); y; kdone(&x);

/*
 * foreach(...) macro is used like this:
 *
 * int a = 0; int b = 1; int c = 2;
 * iterable_t list = iterable2(&a, &b, &c, 0);
 *
 * foreach(element, list) {
 *	printf("%d\n", *(int*)element);
 * }
 * 
 * free(list.storage);
 */


#define foreach(el, iterable_list) for (void* el = next(&(iterable_list)); el != NULL; el = next(&(iterable_list)))
