#include "Object.h"
#include "Heap.h"

Object::Object()
{

}


Object::~Object()
{
}


void Object::Addobject()
{
	Heap* standardHeap = new Heap("Standard");

	Object* testObject = new (standardHeap)Object();
	Object* testObject2 = new (standardHeap)Object();

	delete testObject;

	int test3 = 5;

}