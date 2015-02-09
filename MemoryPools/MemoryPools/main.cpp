///HEJ MYSTERISK!
///HEJ JAWS!
//Memory Pool

#include "Heap.h"

static void* operator new(size_t p_size, Heap* p_heap);
static void operator delete(void* p_memory);
static void operator delete(void* p_memory, Heap* p_heap);

#include "Object.h"


void* operator new(size_t p_size, Heap* p_heap)
{
	size_t t_NeededBytes = p_size + sizeof(AllocHeader);
	char* t_memLocation = (char *)malloc(t_NeededBytes);
	AllocHeader* t_header = (AllocHeader*)t_memLocation;
	t_header->m_heap = p_heap;
	t_header->m_size = p_size;

	p_heap->AddAllocation(p_size);

	void* r_startBlock = t_memLocation + sizeof(AllocHeader);
	return r_startBlock;
}

void operator delete(void* p_memory)
{
	AllocHeader * t_header = (AllocHeader*)((char*)p_memory - sizeof(AllocHeader));
	t_header->m_heap->RemoveAllocation(t_header->m_size);
	free(t_header);
}

//test
void operator delete(void* p_memory, Heap* p_heap)
{
	AllocHeader * t_header = (AllocHeader*)((char*)p_memory - sizeof(AllocHeader));
	t_header->m_heap->RemoveAllocation(t_header->m_size);
	free(t_header);
}


void main()
{
	Heap* standardHeap = new Heap("Standard");

	Object* testObject = new Object();
	Object* testObject2 = new Object();

	delete testObject;

	int test3 = 5;

	return;
}