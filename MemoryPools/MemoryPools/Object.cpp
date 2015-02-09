#include "Object.h"


Object::Object()
{
	Heap* m_heap = new Heap("test");
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

	int test3 = 5;

}

void* Object::operator new(size_t size)
{
	return ::operator new(size, m_heap);
}
void Object::operator delete(void*)
{

}