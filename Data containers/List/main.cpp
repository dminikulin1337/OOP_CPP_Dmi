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
		friend class Iterator;
		friend class ReverseIterator;
	};
	Element* head;
	Element* tail;
	int size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			//cout << "it_Constructor " << this << endl;
		}
		~Iterator()
		{
			//cout << "it_Destructor " << this << endl;
		}
		Iterator operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		const int& operator*() const
		{
			return Temp->data;
		}
		bool operator!=(const Iterator& other) const
		{
			return this->Temp != other.Temp;
		}
		operator bool() const
		{
			return Temp;
		}
	};

	const Iterator begin() const
	{
		return head;
	}
	const Iterator end() const
	{
		return nullptr;
	}

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr): Temp(Temp)
		{
			cout << "revit_Constructor " << this << endl;
		}
		~ReverseIterator()
		{
			cout << "revit_Destructor " << this << endl;
		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		/*ReversedIterator operator++(int)
		{
			ReversedIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReversedIterator operator--(int)
		{
			ReversedIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}*/
		const int& operator*() const
		{
			return Temp->data;
		}
		int& operator*()
		{
			return Temp->data;
		}
		bool operator!=(const ReverseIterator& other) const
		{
			return this->Temp != other.Temp;
		}
		operator bool() const
		{
			return this->Temp;
		}
	};

	const ReverseIterator rbegin() const
	{
		return tail;
	}
	ReverseIterator rbegin()
	{
		return tail;
	}
	const ReverseIterator rend() const
	{
		return nullptr;
	}
	ReverseIterator rend()
	{
		return nullptr;
	}

	List()
	{
		head = tail = nullptr;
		size = 0;
		cout << "L_Constructor " << this << endl;
	}
	List(const List& other) :List()
	{
		/*this->size = other.size;*/
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
	List(const std::initializer_list<int>& li):List()
	{
		for (const int* it = li.begin(); it != li.end(); it++)
		{
			PushBack(*it);
		}
		cout << "IL_Constructor " << this << endl;
	}
	~List()
	{
		while (head) { PopFront(); }
		cout << "L_Destructor " << this << endl;
	}
	//Overloaded operators
	List& operator=(const List& other)
	{
		if (this == &other)return *this;
		this->~List();
		for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		return *this;
	}
	List& operator=(List&& other)
	{
		if (this == &other)return *this;
		this->~List();
		for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
		return *this;
	}
	/*List& operator+=(const List& other)
	{
		Element* Temp = this->head;
		while(Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp = other.head;
		Element* Ming = other.tail;
		while (Ming->pPrev)
		{
			Ming = Ming->pPrev;
		}
		Ming = this->tail;
		this->size += other.size;
		return *this;
	}*/
	
	//Adding elements
	void PushFront(int data)
	{
		if (head == nullptr && tail == nullptr)
		{
			head = tail = new Element(data);
		}
		else 
		{
			head = head->pPrev = new Element(data, head);
		}
		size++;
	}
	void PushBack(int data)
	{
		if (head == nullptr && tail == nullptr)
		{
			head = tail = new Element(data);
		}
		else
		{
			tail = tail->pNext = new Element(data, nullptr, tail);
		}
		size++;
	}
	void Insert(int data, int index)
	{
		Element* New = new Element(data);
		Element* Temp;
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
		if (!head && !tail) return;
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else 
		{
			head = head->pNext;
			delete head->pPrev;
			head->pPrev = nullptr;
		}
		size--;
	}	
	void PopBack()
	{
		if (!head && !tail) return;
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->pPrev;
			delete tail->pNext;
			tail->pNext = nullptr;
		}
		size--;
	}
	void Erase(int index)
	{
		Element* Temp;
		if (index == 0)
		{
			PopFront();
			return;
		} 
		if (index == size - 1)
		{
			PopBack();
			return;
		}
		if (index > size || index < 0) return;
		if (index < size / 2)
		{
			Temp = head;
			for (int i = 0; i < index; i++) { Temp = Temp->pNext; }
		}
		else
		{
			Temp = tail;
			for (int i = 0; i < size - index - 1; i++) { Temp = Temp->pPrev; }
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}
	void print() const	
	{
		for (Iterator it = head; it; it++)
		{
			cout << *it << "  ";
		}
		cout << "List size: " << size << endl;
		cout << endl;
	}
	void print_reverse() const
	{
		for (ReverseIterator it = rbegin(); it != rend(); ++it)
		{
			cout << *it << "  ";
		}
		cout << "List size: " << size << endl;
		cout << endl;
	}
};

//#define Fundamentals
//#define MAIN

int main()
{
#ifdef MAIN
	List list;
	int n;
	cout << "List size: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.PushBack(rand() % 100);
	}
	list.print();
#endif // MAIN

#ifdef Fundamentals
	list.Erase(-4);
	list.print();
	List list2;
	list2 = list;
	list2.print();
#endif // Fundamentals
	
	List leest = { 3,5,8,13,21 };
	for (int i : leest)
	{
		cout << i << "  ";
	}
	leest.print_reverse();

	for (List::ReverseIterator rit = leest.rbegin(); rit != leest.rend(); ++rit)
	{
		cout << *rit << "\t";
	}
	return 0;
}