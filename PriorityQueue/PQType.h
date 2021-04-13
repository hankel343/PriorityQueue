#ifndef PQTYPE_H
#define PQTYPE_H

class FullQueue {};
class EmptyQueue {};
void Swap(int& num1, int& num2);

struct HeapType
{
	void ReheapDown(int nRoot, int nBottom);
	void ReheapUp(int nRoot, int nBottom);
	int* pElements;
};

class PQType
{
private:
	HeapType items;
	int nLength;
	int nMaxItems;

public:
	PQType(int nSize);
	~PQType();

	void MakeEmpty();
	bool IsFull() const;
	bool IsEmpty() const;
	void Enqueue(int nNewItem);
	void Dequeue(int& nDequeuedItem);
};

#endif PQTYPE_H