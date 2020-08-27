#include<iostream>
using namespace std;

class Element
{
	int data;
	Element* pNext;
	Element* pPrev;
public:
	Element(int data, Element* pNext = nullptr): data(data), pNext(pNext), pPrev(pPrev)
	{
		cout << "E_Construtor: " << this << endl;
	}
	~Element()
	{
		cout << "E_Destructor: " << this << endl;
	}
	friend class DoubleList;
};

class DoubleList
{
	Element* head;
	Element* tail;
	int size;
public:
	DoubleList() :head(nullptr), tail(nullptr)
	{
		cout << "L_Constructor: " << this << endl;
	}
	~DoubleList()
	{
		cout << "L_Destructor: " << this << endl;
	}
	void print() const
	{
		for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
		{
			cout << Temp << "\t" << Temp->data << "\t" << Temp->pNext << endl;
		}
		cout << "List size: " << size << endl;
	}
};

int main()
{
	DoubleList list;
	return 0;
}