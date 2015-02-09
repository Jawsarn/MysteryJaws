#include "Heap.h"
#include <Windows.h>
void* operator new(size_t p_size, Heap* p_heap)
{
	size_t t_NeededBytes = p_size + sizeof(Heap::AllocHeader);
	char* t_memLocation = (char *)malloc(t_NeededBytes);
	Heap::AllocHeader* t_header = (Heap::AllocHeader*) t_memLocation;
	t_header->m_heap = p_heap;
	t_header->m_size = p_size;

	p_heap->AddAllocation(p_size);

	void* r_startBlock = t_memLocation + sizeof(Heap::AllocHeader);
	return r_startBlock;
}

void operator delete(void* p_memory)
{
	Heap::AllocHeader * t_header = (Heap::AllocHeader*)((char*)p_memory - sizeof(Heap::AllocHeader));
	t_header->m_heap->RemoveAllocation(t_header->m_size);
	free(t_header);
}

Heap::Heap(const char * p_name)
{
	m_currSize = 0;
	memcpy(m_name, p_name, sizeof(char)* NAMELENGHT);
}

Heap::Heap()
{
	m_currSize = 0;
}


Heap::~Heap()
{
}

void Heap::AddAllocation(size_t p_size)
{
	m_currSize += p_size;
}

void Heap::RemoveAllocation(size_t p_size)
{
	m_currSize -= p_size;
}