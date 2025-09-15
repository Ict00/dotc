#pragma once


#define foreach(el, iterable_list) for (void* el = next(&(iterable_list)); el != NULL; el = next(&(iterable_list)))
