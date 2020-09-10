#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class List
{
	class Element
	{
		T data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr) :
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
		const T& operator*() const
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

	const Iterator begin() const;
	const Iterator end() const;

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) : Temp(Temp)
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
		const T& operator*() const
		{
			return Temp->data;
		}
		T& operator*()
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

	const ReverseIterator rbegin() const;
	ReverseIterator rbegin();
	const ReverseIterator rend() const;
	ReverseIterator rend();

	List();
	List(const List& other);
	List(List&& other);
	List(const std::initializer_list<T>& li);
	~List();
	//Overloaded operators
	List& operator=(const List& other);
	List& operator=(List&& other);
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
	void PushFront(T data);
	void PushBack(T data);
	void Insert(T data, int index);
	//Subtracting elements
	void PopFront();
	void PopBack();
	void Erase(int index);
	void print() const;
	void print_reverse() const;
};