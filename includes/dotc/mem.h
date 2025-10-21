#pragma once
#include <stddef.h>
#include "dotc/syntax.h"

object(context_t,
	void** ptrs;
	int count;
,
	/*
	 * All of those add pointers that should be free'd to list
	 * NOTE: kaddv2 requires NULL as the last argument
	 * NOTE x2: Use create_mctx to create context_t Or (which is recommended)
	 * use scope(ctx, { ... })
	 */

	void* kaddpass(context_t* THIS, void* ptr);
	void kadd(context_t* THIS, void* ptr);
	void kaddv(context_t* THIS, int count, ...);
	void kaddv2(context_t* THIS, ...);
	void kdone(context_t* THIS);
	context_t create_mctx();
);
