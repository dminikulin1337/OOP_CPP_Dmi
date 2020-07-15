#include<iostream>
#include<exception>
#include<Windows.h>
using namespace std;

//#define DIVISION_BY_ZERO
//#define FACTORIAL

unsigned int factorial(unsigned int n)
{
	if (n > 12) { throw exception("Too large number"); }
	unsigned int f = 1;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "!=";
		f *= i;
		cout << f << endl;
	}
	return f;
}

int main() 
{
	setlocale(LC_ALL, "");

#ifdef DIVISION_BY_ZERO
	int a = 2;
	int b = 0;
	try
	{
		//throw exception("Cannot divide by zero");
		cout << a / b << endl;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		//cerr << "Cannot divide by zero" << endl;
		::MessageBox(NULL, "Cannot divide by zero.", "Exceptions.exe", MB_OK | MB_ICONERROR);
	}
#endif // DIVISION_BY_ZERO

#ifdef FACTORIAL
	int n;
	cout << "Enter number: "; cin >> n;
	try
	{
		cout << factorial(n) << endl;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
#endif // FACTORIAL

	int n;
	cout << "Enter array size: "; cin >> n;
	//int* arr = nullptr;
	try
	{
		int* arr = new int[n];
		delete[] arr;
	}
	catch (const std::exception&)
	{
		::MessageBox(NULL, "Size of array is huge.", "Exceptions.exe", MB_OK | MB_ICONERROR);
	}

	return 0;
}