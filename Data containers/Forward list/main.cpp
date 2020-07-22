#include<iostream>
#include<string>
using namespace std;

class Element 
{
	int data;
	Element* pNext;
public:
	Element(int data, Element* pNext = nullptr): data(data), pNext(pNext)
	{
		cout << "E_Constructor: " << this << endl;
	}
	~Element()
	{
		cout << "E_Destructor: " << this << endl;
	}
	friend class ForwardList;//ForwardList - мой друг, он меня и мои данные может видеть
};

class ForwardList
{
	Element* head;
public:
	ForwardList():head(nullptr)
	{
		cout << "L_Constructor: " << this << endl;
	}
	~ForwardList()
	{
		cout << "L_Destructor: " << this << endl;
	}

	void PushFront(int data)
	{
		Element* New = new Element(data);
		New->pNext = head;
		head = New;
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
	}
	void print() const
	{
		Element* Tempo = head; //Итератор
		while (Tempo!=nullptr)
		{
			cout << Tempo << " " << Tempo->data << " " << Tempo->pNext << endl;
			Tempo = Tempo->pNext; // Переход на следующий елемент
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	int size;
	cout << "Input list size: "; cin >> size;
	ForwardList list;
	for (int i = 0; i < size; i++)
	{
		list.PushBack(rand()%100);
	}
	//list.PopFront();
	list.print();
	return 0;
}