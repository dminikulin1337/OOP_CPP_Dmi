#include"Templated_list.h"
#include"Templated_list.cpp"
using namespace std;

#define TAB "\t"

//#define Fundamentals
//#define MAIN
//#define Iterators

int main()
{
	setlocale(LC_ALL, "");
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
	
#ifdef Iterators
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
#endif // Iterators

	List<int> list1 = { 3,5,8,13,21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	for (List<int>::ReverseIterator it = list1.rbegin(); it != list1.rend(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
	///////////////////////////////////////////////////////////////////////////////
	List<double> list2 = { 2.5, 3.14, 8.2, 12.21 };
	for (double i : list2)
	{
		cout << i << "\t";
	}
	cout << endl;
	///////////////////////////////////////////////////////////////////////////////
	List<std::string> list3 = {"Хорошо", "живет", "на", "свете", "Винни-Пух"};
	list3.PushFront("Друзья!");
	list3.PushBack("Запомните!!!");
	for (std::string i : list3)
	{
		cout << i << "\t";
	}
	for (List<std::string>::ReverseIterator it = list3.rbegin(); it != list3.rend(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}