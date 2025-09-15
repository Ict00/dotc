#pragma once

struct {
	int count, current;
	void** storage;
} typedef iterable_t;

iterable_t iterable(void** storage, int count);
void** dc_storage(int count, ...);
void* next(iterable_t* iter);
void* next2(iterable_t* iter);
