#include "PQType.h"

void Swap(int& num1, int& num2)
{
	int nTemp = num1;
	num1 = num2;
	num2 = nTemp;
}

void HeapType::ReheapDown(int nRoot, int nBottom)
{
	int nMaxChild;
	int nLeftChild = (nRoot * 2) + 1;
	int nRightChild = (nRoot * 2) + 2;

	if (nLeftChild <= nBottom)
	{
		if (nLeftChild == nBottom)
			nMaxChild = nLeftChild;
		else
		{
			if (pElements[nLeftChild] < pElements[nRightChild])
				nMaxChild = nRightChild;
			else
				nMaxChild = nLeftChild;
		}

		if (pElements[nRoot] < pElements[nMaxChild])
		{
			Swap(pElements[nRoot], pElements[nMaxChild]);
			ReheapDown(nMaxChild, nBottom);
		}
	}
}

void HeapType::ReheapUp(int nRoot, int nBottom)
{
	int nParent;
	if (nBottom > nRoot)
	{
		nParent = (nBottom - 1) / 2;
		if (pElements[nParent] < pElements[nBottom])
		{
			Swap(pElements[nParent], pElements[nBottom]);
			ReheapUp(nRoot, nParent);
		}
	}
}

PQType::PQType(int nSize)
{
	nMaxItems = nSize;
	items.pElements = new int[nSize];
	nLength = 0;
}

void PQType::MakeEmpty()
{
	nLength = 0;
}

bool PQType::IsFull() const
{
	return (nLength == nMaxItems);
}

bool PQType::IsEmpty() const
{
	return (nLength == 0);
}

void PQType::Enqueue(int nNewItem)
{
	if (IsFull())
		throw FullQueue();
	else
	{
		nLength++;
		items.pElements[nLength - 1] = nNewItem;
		items.ReheapUp(0, nLength - 1);
	}
}

void PQType::Dequeue(int& nDequeuedItem)
{
	if (IsEmpty())
		throw EmptyQueue();
	else
	{
		nDequeuedItem = items.pElements[0];
		items.pElements[0] = items.pElements[nLength - 1];
		nLength--;
		items.ReheapDown(0, nLength - 1);
	}
}

PQType::~PQType()
{
	delete[] items.pElements;
}