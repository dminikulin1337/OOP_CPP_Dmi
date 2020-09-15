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
		Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
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
		Iterator& operator++();
		Iterator& operator--();
		Iterator operator++(int);
		Iterator operator--(int);
		const T& operator*() const;
		bool operator!=(const Iterator& other) const;
		operator bool() const;
	};

	const Iterator begin() const;
	const Iterator end() const;

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr);
		~ReverseIterator();
		ReverseIterator& operator++();
		ReverseIterator& operator--();
		const T& operator*() const;
		T& operator*();
		bool operator!=(const ReverseIterator& other) const;
		operator bool() const;
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

