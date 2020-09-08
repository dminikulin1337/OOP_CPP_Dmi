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
		Iterator(Element* Temp = nullptr);
		~Iterator();
		Iterator operator++();
		Iterator& operator--();
		Iterator operator++(int);
		Iterator operator--(int);
		const int& operator*() const;
		bool operator!=(const Iterator& other) const;
		operator bool() const;
	};

	
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr);
		~ReverseIterator();
		ReverseIterator& operator++();
		ReverseIterator& operator--();
		ReverseIterator operator++(int);
		ReverseIterator operator--(int);
		const int& operator*() const;
		int& operator*();
		bool operator!=(const ReverseIterator& other) const;
		operator bool() const;
	};

	const Iterator begin() const;
	const Iterator end() const;
	const ReverseIterator rbegin() const;
	ReverseIterator rbegin();
	const ReverseIterator rend() const;
	ReverseIterator rend();

	List();
	List(const List& other);
	List(List&& other);
	List(const std::initializer_list<int>& li);
	~List();
	//Overloaded operators
	List& operator=(const List& other);
	List& operator=(List&& other);
	
	//Adding elements
	void PushFront(int data);
	void PushBack(int data);
	void Insert(int data, int index);
	//Subtracting elements
	void PopFront();
	void PopBack();
	void Erase(int index);
	void print() const;
	void print_reverse() const;
};

//////////////////////////////////////////////////	ITERATOR	//////////////////////////////////////////////////

List::Iterator::Iterator(Element* Temp) :Temp(Temp)
{
	//cout << "it_Constructor " << this << endl;
}
List::Iterator::~Iterator()
{
	//cout << "it_Destructor " << this << endl;
}
List::Iterator List::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
List::Iterator& List::Iterator::operator--()
{
	Temp = Temp->pPrev;
	return *this;
}
List::Iterator List::Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
List::Iterator List::Iterator::operator--(int)
{
	Iterator old = *this;
	Temp = Temp->pPrev;
	return old;
}
const int& List::Iterator::operator*() const
{
	return Temp->data;
}
bool List::Iterator::operator!=(const Iterator& other) const
{
	return this->Temp != other.Temp;
}
List::Iterator::operator bool() const
{
	return Temp;
}

//////////////////////////////////////////////////	ITERATOR	//////////////////////////////////////////////////

//////////////////////////////////////////////////	REVERSE ITERATOR	//////////////////////////////////////////////////

List::ReverseIterator::ReverseIterator(Element* Temp) : Temp(Temp)
{
	cout << "revit_Constructor " << this << endl;
}
List::ReverseIterator::~ReverseIterator()
{
	cout << "revit_Destructor " << this << endl;
}
List::ReverseIterator& List::ReverseIterator::operator++()
{
	Temp = Temp->pPrev;
	return *this;
}
List::ReverseIterator& List::ReverseIterator::operator--()
{
	Temp = Temp->pNext;
	return *this;
}
List::ReverseIterator List::ReverseIterator::operator++(int)
{
	ReverseIterator old = *this;
	Temp = Temp->pPrev;
	return old;
}
List::ReverseIterator List::ReverseIterator::operator--(int)
{
	ReverseIterator old = *this;
	Temp = Temp->pNext;
	return old;
}
const int& List::ReverseIterator::operator*() const
{
	return Temp->data;
}
int& List::ReverseIterator::operator*()
{
	return Temp->data;
}
bool List::ReverseIterator::operator!=(const ReverseIterator& other) const
{
	return this->Temp != other.Temp;
}
List::ReverseIterator::operator bool() const
{
	return this->Temp;
}

//////////////////////////////////////////////////	REVERSE ITERATOR	//////////////////////////////////////////////////

//////////////////////////////////////////////////	LIST	//////////////////////////////////////////////////

const List::Iterator List::begin() const
{
	return head;
}
const List::Iterator List::end() const
{
	return nullptr;
}

const List::ReverseIterator List::rbegin() const
{
	return tail;
}
List::ReverseIterator List::rbegin()
{
	return tail;
}
const List::ReverseIterator List::rend() const
{
	return nullptr;
}
List::ReverseIterator List::rend()
{
	return nullptr;
}
List::List()
{
	head = tail = nullptr;
	size = 0;
	cout << "L_Constructor " << this << endl;
}
List::List(const List& other) :List()
{
	/*this->size = other.size;*/
	for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
	{
		PushBack(Temp->data);
	}
}
List::List(List&& other) :List()
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
List::List(const std::initializer_list<int>& li) :List()
{
	for (const int* it = li.begin(); it != li.end(); it++)
	{
		PushBack(*it);
	}
	cout << "IL_Constructor " << this << endl;
}
List::~List()
{
	while (head) { PopFront(); }
	cout << "L_Destructor " << this << endl;
}
//Overloaded operators
List& List::operator=(const List& other)
{
	if (this == &other)return *this;
	this->~List();
	for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
	{
		PushBack(Temp->data);
	}
	return *this;
}
List& List::operator=(List&& other)
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

//Adding elements
void List::PushFront(int data)
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
void List::PushBack(int data)
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
void List::Insert(int data, int index)
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
void List::PopFront()
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
void List::PopBack()
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
void List::Erase(int index)
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
void List::print() const
{
	for (Iterator it = head; it; it++)
	{
		cout << *it << "  ";
	}
	cout << "List size: " << size << endl;
	cout << endl;
}
void List::print_reverse() const
{
	for (ReverseIterator it = rbegin(); it != rend(); ++it)
	{
		cout << *it << "  ";
	}
	cout << "List size: " << size << endl;
	cout << endl;
}

//////////////////////////////////////////////////	LIST	//////////////////////////////////////////////////

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