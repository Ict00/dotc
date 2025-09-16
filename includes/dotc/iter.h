#pragma once

struct {
	int count, current;
	void** storage;
} typedef iterable_t;

iterable_t iterable(void** storage, int count);
iterable_t iterable2(void* param1, ...);
void** dc_storage(int count, ...);
void* next(iterable_t* iter);
void* next2(iterable_t* iter);
