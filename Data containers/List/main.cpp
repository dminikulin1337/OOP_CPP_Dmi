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
			//cout << "E_Constructor " << this << endl;
		}
		~Element()
		{
			//cout << "E_Destructor " << this << endl;
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
	List(const List& other) :List()
	{
		this->size = other.size;
		for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
	}
	List(List&& other) :List()
	{
		this->size = other.size;
		for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
	}
	~List()
	{
		cout << "L_Destructor " << this << endl;
	}
	//Overloaded operators
	List& operator=(const List& other)
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
		for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		return *this;
	}
	List& operator=(List&& other)
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
		for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
		return *this;
	}
	/*List& operator+=(List& other)
	{
		Element* Temp1 = this->head;
		Element* Temp2 = other.tail;
		for (int i = 0; i < this->size; i++)
		{
			Temp1 = Temp1->pNext;
		}
		for (int i = 0; i < other.size; i++)
		{
			Temp2 = Temp2->pPrev;
		}
		Temp1 = other.head;
		Temp2 = this->tail;
		return *this;
	}*/
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
	void Insert(int data, int index)
	{
		Element* New = new Element(data);
		Element* Temp = head;
		if (index > size) return;
		if (index == 0) {
			PushFront(data);
			return;
		}
		size++;
		for (int i = 0; i < index - 1; i++) 
		{
			Temp = Temp->pNext;
		}
		if (head == nullptr && tail == nullptr)
		{
			head = tail = New;
		}
		else
		{
			New->pNext = Temp->pNext;
			New->pPrev = Temp;
			Temp->pNext = New;
			Temp = New;
		}
	}
	//Subtracting elements
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
	void Erase(int index)
	{
		Element* Temp = head;
		if (index >= size) return;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = Temp->pNext->pNext;
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
		cout << "List size: " << size << endl;
		cout << endl;
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
	list.print();
	list.Erase(5);
	list.print();
	List list2;
	list2 = list;
	list2.print();
	return 0;
}