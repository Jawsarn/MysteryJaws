#pragma once
#define NAMELENGHT 1024

class Heap
{

public:
	Heap(const char * p_name);
	Heap();
	~Heap();
	const char* GetName();

	void AddAllocation(size_t p_size);
	void RemoveAllocation(size_t p_size);
	struct AllocHeader
	{
		Heap* m_heap;
		int m_size;
	};
private:
	char m_name[NAMELENGHT];
	size_t m_currSize;

};

