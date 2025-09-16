#pragma once

struct {
	int count, current;
	void** storage;
} typedef iterable_t;

iterable_t iterable(void** storage, int count);
/* 
 * Returns new iterable; Example of usage:
 * iterable2(&a, &b, &c, NULL);
 * NULL must be at the end of param list
 *
 *
 * DON'T FORGET TO FREE iterable_t->storage, it's malloc'd
 */
iterable_t iterable2(void* param1, ...);

/*
 * Makes void**; DON'T FORGET TO FREE IT, IT'S MALLOC'D
 */
void** dc_storage(int count, ...);

/*
 * Returns next element of iterable or NULL if it's end
 */
void* next(iterable_t* iter);

/*
 * Returns next element of iterable; If it's the end of list, then resets current to the start
 */
void* next2(iterable_t* iter);
