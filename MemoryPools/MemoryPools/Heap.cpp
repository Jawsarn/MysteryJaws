#include "Heap.h"



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