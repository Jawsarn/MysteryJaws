#pragma once
#define NAMELENGHT = 1024
class Heap
{
public:
	Heap(const char * p_name);
	Heap();
	~Heap();
	const char* GetName();
private:
	char m_name[1024];
};

