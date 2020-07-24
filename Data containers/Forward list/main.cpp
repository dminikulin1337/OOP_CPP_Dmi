#include<iostream>
#include<exception>
#include<string>
using namespace std;

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
};

int Element::count = 0;

class ForwardList
{
	Element* head;
	int size;
public:
	ForwardList() :head(nullptr)
	{
		size = 0;
		//cout << "L_Constructor: " << this << endl;
	}
	~ForwardList()
	{
		size--;
		//cout << "L_Destructor: " << this << endl;
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
	/*void Erase(int index)
	{
		Element* Tempo = head;
		for (int i = 0; i < index - 1; i++)
		{

		}
	}*/
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
		for (Element* Temp = head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << " " << Temp->data << " " << Temp->pNext << endl;
		}
		cout << "List size: " << size << endl;
	}
};

//#define CHECK

int main()
{
	setlocale(LC_ALL, "");

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
#endif // CHE

	ForwardList list1;
	list1.PushBack(3);
	list1.PushBack(3);
	list1.PushBack(3);
	list1.PushBack(3);
	list1.PushBack(3);
	list1.print();

	cout << delimeter << endl;

	ForwardList list2;
	list2.PushFront(13); 
	list2.PushFront(26); 
	list2.PushFront(39);
	list2.print();

	return 0;
}