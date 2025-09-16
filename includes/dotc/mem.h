#pragma once
#include <stddef.h>
#include "dotc/syntax.h"

object(context_t,
	void** ptrs;
	int count;
,
	void kadd(context_t* THIS, void* ptr);
	void kaddv(context_t* THIS, int count, ...);
	void kaddv2(context_t* THIS, ...);
	void kdone(context_t* THIS);
	context_t create_mctx();
);
