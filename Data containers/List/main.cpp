#include"Functions.h"
#include"Functions.cpp"

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