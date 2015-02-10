#include "Object.h"

//#include <new>

Heap * Object::m_heap = nullptr;

Object::Object()
{
	int test3 = 5;
}


Object::~Object()
{
}


void Object::Addobject()
{
	Heap* standardHeap = new Heap("Standard");

	Object* testObject = new Object();
	Object* testObject2 = new Object();

	delete testObject;
	delete testObject2;
	int test3 = 5;

}

void* Object::operator new(size_t size)
{
	if (m_heap == nullptr)
	{
		m_heap = new Heap("test");
	}
	return ::operator new (size, m_heap);
}
void Object::operator delete(void* p_memory)
{
	::operator delete(p_memory);
}