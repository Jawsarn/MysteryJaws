#pragma once
#define KILO 1000
#include "Heap.h"

class Object
{
private:
	static Heap* m_heap;
	int name[KILO*KILO];
public:
	Object();
	~Object();
	static void* operator new(size_t size);
	static void operator delete(void* mem);
	void Addobject();

};

