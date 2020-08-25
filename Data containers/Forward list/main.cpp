#include<iostream>
#include<exception>
#include<string>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::exception;

#define delimeter "\n<================================================================>\n"

class Element 
{
	int data;
	Element* pNext;
	static int count; //number of elements
public:
	Element(int data, Element* pNext = nullptr): data(data), pNext(pNext)
	{
		count++;
		//cout << "E_Constructor: " << this << endl;
	}
	~Element()
	{
		count--;
		//cout << "E_Destructor: " << this << endl;
	}
	friend class ForwardList;//ForwardList - мой друг, он меня и мои данные может видеть
	friend class Iterator;
};

int Element::count = 0;

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr)
	{
		this->Temp = Temp;
		//cout << "ItConstructor: " << this << endl;
	}
	~Iterator()
	{
		//cout << "ItDestructor: " << this << endl;
	}
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}//WTF definition
	int& operator*()
	{
		return Temp->data;
	}
	bool operator!=(Element* other_el) const
	{
		return this->Temp != other_el; 
	}
	operator bool()const
	{
		return Temp;
	}
};

class ForwardList
{
	Element* head;
	int size;
public:
	Element* get_head() const { return head; }
	int get_size() const { return this->size; }

	Iterator begin()const
	{
		return head;
	}
	Iterator end()const
	{
		return nullptr;
	}

	ForwardList() :head(nullptr)
	{
		size = 0;
		//cout << "L_Constructor: " << this << endl;
	}

	ForwardList(int nullz) :ForwardList()
	{
		if (nullz < 0) { throw exception("Negative size inputed."); }
		//if (nullz > 1000) { throw exception("Too high size. Max. acceptable size is 1000 elements."); }
		while (nullz--) { PushFront(0); }
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		for (Element* Temp = other.head; Temp; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		//cout << "L_copyConstructor: " << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il)
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			PushBack(*it);
		}
	}
	ForwardList& operator=(const ForwardList& other)
	{
		this->head = nullptr;
		this->size = 0;
		for (Element* Temp = other.head; Temp; Temp = Temp->pNext)
		{
			PushBack(Temp->data);
		}
		return *this;
	}
	~ForwardList()
	{
		while (head != nullptr) PopFront();
		//cout << "L_Destructor: " << this << endl;
	}

	//Operators
	int& operator[](int index)
	{
		if (index >= this->size) { throw exception("\nError: Out of range."); }
		Element* Temp = head;
		for (int i = 0; i < index; i++)
		{
			Temp = Temp->pNext;
		}
		return Temp->data;
	}

	//adding elements
	void PushFront(int data)
	{
		/*Element* New = new Element(data);
		New->pNext = head;
		head = New;*/
		head = new Element(data, head);
		size++;
	}
	void PushBack(int data)
	{
		if (head == nullptr)
		{
			PushFront(data);
			return;
		}
		Element* New = new Element(data);
		Element* Tempo = head;
		while (Tempo->pNext)
		{
			Tempo = Tempo->pNext;
		}
		Tempo->pNext = New;
		size++;
	}
	void Insert(int data, int index)
	{
		if (index > size)return;
		if (index == 0)
		{
			PushFront(data);
			return;
		}
		Element* New = new Element(data);
		Element* Tempo = head;
		for (int i = 0; i < index - 1; i++)
		{
			Tempo = Tempo->pNext;
		}
		New->pNext = Tempo->pNext;
		Tempo->pNext = New;
		size++;
	}
	//deleting elements
	void PopFront()
	{
		Element* kill = head; //remember the address of killable element
		head = head->pNext;	//removing element from list
		delete kill; //delete previous head element
		size--;
	}
	void PopBack()
	{
		Element* Tempo = head;
		while (Tempo->pNext->pNext)
		{
			Tempo = Tempo->pNext;
		}
		delete Tempo->pNext;
		Tempo->pNext = nullptr;
		size--;
	}
	void Erase(int index)
	{
		Element* Tempo = head;
		for (int i = 0; i < index - 1; i++)
		{
			Tempo = Tempo->pNext;
		}
		Tempo->pNext = Tempo->pNext->pNext;
	}
	//other methods
	void print() const
	{
#ifdef AULD
		Element* Tempo = head; //Итератор
		while (Tempo != nullptr)
		{
			cout << Tempo << " " << Tempo->data << " " << Tempo->pNext << endl;
			Tempo = Tempo->pNext; // Переход на следующий елемент
		}
#endif // AULD
		for (Iterator Temp = begin(); Temp != end(); Temp++)
		{
			//cout << Temp << " " << Temp->data << " " << Temp->pNext << endl;
			cout << *Temp << endl;
		}
		cout << "List size: " << size << endl;
	}
};

//#define CHECK
//#define Check2
//#define Cointreau

int main()
{

	/*int n;
	cout << "Enter size of list: "; cin >> n;*/
#ifdef CHECK
	int size;
	cout << "Input list size: "; cin >> size;
	cout << delimeter << endl;
	ForwardList list;
	for (int i = 0; i < size; i++)
	{
		list.PushBack(rand() % 100);
	}
	list.print();
	cout << delimeter << endl;
	int index, value;
	cout << "Enter index: "; cin >> index;
	cout << "Enter value: "; cin >> value;
	list.Insert(value, index);
	cout << delimeter << endl;
	list.print();
#endif // CHECK

#ifdef Check2
	ForwardList list1;
	list1.PushBack(3);
	list1.PushBack(3);
	list1.PushBack(0);
	list1.PushBack(3);
	list1.PushBack(3);
	list1.print();

	cout << delimeter << endl;

	/*ForwardList list2;
	list2.PushFront(13);
	list2.PushFront(26);
	list2.PushFront(39);
	list2.print();

	cout << delimeter << endl;

	list1 = list2;
	list1.print();

	cout << delimeter << endl;*/

	ForwardList list3 = list1;
	list3.print();

	/*cout << delimeter << endl;
	list3.Erase(1);
	list3.print();*/
#endif // Check2

#ifdef Cointreau
	try {
		ForwardList list(n);
		//list.print();

		for (int i = 0; i < list.get_size(); i++)
		{
			list[i] = rand() % 100;
		}
		cout << "List loaded" << endl;
		for (int i = 0; i < list.get_size(); i++)
		{
			cout << list[i] << "\t";
		}
		cout << "List printed" << endl;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
#endif // UniqueConstreau

	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;
	
	return 0;
}