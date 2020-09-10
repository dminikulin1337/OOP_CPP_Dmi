#pragma once
#include<iostream>
using namespace std;

class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr) :
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