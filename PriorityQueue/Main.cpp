#include <iostream>
#include "PQType.h"

using namespace std;

void ProcessInput(char chInput, PQType& PQ);
void EnqueueCase(PQType& PQ);
void DequeueCase(PQType& PQ);

int main()
{
	int nSize = 0;
	cout << "This program allows you to perform basic operations on a priority queue.\n";
	cout << "Enter the size of the queue.\n";
	cout << "Size: ";
	cin >> nSize;

	PQType PriorityQue(nSize);

	char chInput = '-1';
	do
	{
		cout << "Enter your selection from the choices below.\n\n";
		cout << "1 - Enqueue an item.\n";
		cout << "2 - Dequeue an item.\n";
		cout << "3 - Make the queue empty.\n";
		cout << "Q - Quit.\n";
		cout << "Enter your choice: ";
		cin >> chInput;

		system("cls");

		ProcessInput(chInput, PriorityQue);

	} while (toupper(chInput) != 'Q');

	cout << "Goodbye...\n";

	return 0;
}

void ProcessInput(char chInput, PQType& PQ)
{
	switch (toupper(chInput))
	{
	case '1':	EnqueueCase(PQ);
				break;

	case '2':	DequeueCase(PQ);
				break;

	case '3':	cout << "The queue has been made empty.\n";
				break;

	case 'Q':	break;

	default:	cout << "Unrecognized input - try again.\n";
				break;
	}
}

void EnqueueCase(PQType& PQ)
{
	int nNewItem;
	cout << "Enter the value you want to add to the queue.\n";
	cout << "Value: ";
	cin >> nNewItem;

	try
	{
		PQ.Enqueue(nNewItem);
		cout << nNewItem << " has been added to the queue.\n";
	} catch(FullQueue exception) {
		cerr << "Exception caught - the queue is currently full.\n";
	}
}

void DequeueCase(PQType& PQ)
{
	int nDequeuedItem;

	try
	{
		PQ.Dequeue(nDequeuedItem);
		cout << nDequeuedItem << " has been dequeued from the queue.\n";
	} catch (EmptyQueue exception) {
		cerr << "Exception caught - the queue is currently empty.\n";
	}
}