#include"Templated_list.h"

template<typename T>
typename const List<T>::Iterator List<T>::begin() const
{
	return head;
}
template<typename T>
typename const List<T>::Iterator List<T>::end() const
{
	return nullptr;
}
template<typename T>
typename const List<T>::ReverseIterator List<T>::rbegin() const
{
	return tail;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::rbegin()
{
	return tail;
}
template<typename T>
typename const List<T>::ReverseIterator List<T>::rend() const
{
	return nullptr;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template<typename T>
List<T>::List()
{
	head = tail = nullptr;
	size = 0;
	cout << "L_Constructor " << this << endl;
}
template<typename T>
List<T>::List(const List& other) :List()
{
	/*this->size = other.size;*/
	for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
	{
		PushBack(Temp->data);
	}
}
template<typename T>
List<T>::List(List&& other) :List()
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
template<typename T>
List<T>::List(const std::initializer_list<T>& li) :List()
{
	for (const T* it = li.begin(); it != li.end(); it++)
	{
		PushBack(*it);
	}
	cout << "IL_Constructor " << this << endl;
}
template<typename T>
List<T>::~List()
{
	while (head) { PopFront(); }
	cout << "L_Destructor " << this << endl;
}
//Overloaded operators
template<typename T>
List<T>& List<T>::operator=(const List& other)
{
	if (this == &other)return *this;
	this->~List();
	for (Element* Temp = other.head; Temp != nullptr; Temp = Temp->pNext)
	{
		PushBack(Temp->data);
	}
	return *this;
}
template<typename T>
List<T>& List<T>::operator=(List&& other)
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
template<typename T>
void List<T>::PushFront(T data)
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
template<typename T>
void List<T>::PushBack(T data)
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
template<typename T>
void List<T>::Insert(T data, int index)
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
template<typename T>
void List<T>::PopFront()
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
template<typename T>
void List<T>::PopBack()
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
template<typename T>
void List<T>::Erase(int index)
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
template<typename T>
void List<T>::print() const
{
	for (Iterator it = head; it; it++)
	{
		cout << *it << "  ";
	}
	cout << "List size: " << size << endl;
	cout << endl;
}
template<typename T>
void List<T>::print_reverse() const
{
	for (ReverseIterator it = rbegin(); it != rend(); ++it)
	{
		cout << *it << "  ";
	}
	cout << "List size: " << size << endl;
	cout << endl;
}