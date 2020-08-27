#include<iostream>
using namespace std;

#define TAB "\t"

class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr):
			data(data),
			pNext(pNext),
			pPrev(pPrev)
		{
			cout << "E_Constructor " << this << endl;
		}
		~Element()
		{
			cout << "E_Destructor " << this << endl;
		}
		friend class List;
	};
	Element* head;
	Element* tail;
	int size;
public:
	List()
	{
		head = tail = nullptr;
		size = 0;
		cout << "L_Constructor " << this << endl;
	}
	~List()
	{
		cout << "L_Destructor " << this << endl;
	}
	//Adding elements
	void PushFront(int data)
	{
		if (head == nullptr && tail == nullptr)
		{
			head = tail = new Element(data);
		}
		head = head->pPrev = new Element(data, head);
		size++;
	}
	void PushBack(int data)
	{
		Element* New = new Element(data);
		size++;
		if (head == nullptr && tail == nullptr)
		{
			head = tail = New;
		}
		else
		{
			New->pPrev = tail;
			tail->pNext = New;
			tail = New;
		}
	}
	void PopFront()
	{
		Element* kill = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete kill;
		size--;
	}
	void PopBack()
	{
		Element* kill = tail;
		tail = tail->pPrev;
		tail->pNext = nullptr;
		delete kill;
		size--;
	}
	void print() const
	{
		for (Element* Temp = head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << TAB << Temp << TAB << Temp->data << TAB << Temp->pNext << endl;
		}
		cout << "List size: " << size << endl;
		cout << endl;
	}
	void print_reverse() const
	{
		for (Element* Temp = tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pPrev << TAB << Temp << TAB << Temp->data << TAB << Temp->pNext << endl;
		}
		cout << endl;
		cout << "List size: " << size << endl;
	}
};

int main()
{
	List list;
	int n;
	cout << "List size: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.PushBack(rand() % 100);
	}
	list.print_reverse();
	/*list.PopBack();
	list.print_reverse();*/
	return 0;
}