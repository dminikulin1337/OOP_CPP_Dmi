#include<iostream>
using namespace std;

class Element
{
	int data;
	Element* pNext;
public:
	Element(int data, Element* pNext = nullptr): data(data), pNext(pNext)
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
		while (head != nullptr) { PopFront(); }
		cout << "L_Destructor: " << this << endl;
	}

	void PushFront(int data)
	{
		head = new Element(data, head);
		size++;
	}
	void PopFront()
	{
		Element* kill = head;
		head = head->pNext;
		delete kill;
		size--;
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
	//list.print();
	list.PushFront(6);
	list.print();
	return 0;
}