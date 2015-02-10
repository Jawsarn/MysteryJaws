#pragma once
#define KILO 1000

#include "heap.h"

extern void* operator new(size_t p_size, Heap* p_heap);
extern void operator delete(void* p_memory);
extern void operator delete(void* p_memory, Heap* p_heap);


class Object
{
private:
	
	int name[KILO*KILO];
	static Heap* m_heap;
public:
	Object();
	~Object();
	void* operator new(size_t size);
	void operator delete(void* p_memory);
	void Addobject();

};

