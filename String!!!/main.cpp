#include"String.h"

//#define CopyMethodsCheck

void main()
{
	setlocale(LC_ALL, "");

#ifdef CopyMethodsCheck
	String str;
	str.print();
	String str1 = "Hello";
	str1.print();
	String str2 = str1;
	cout << str2 << endl;
	str = str1;
	cout << str << endl;
	str = str;
	cout << str << endl;
#endif // CopyMethodsCheck

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2; //operator+
	cout << str3 << endl;
	str1 += str2; //operator+=
	cout << str1 << endl;

	String str4(); //str4 function, no parameters, returns String value
	String str5{}; //explicit call of default constructor
	String str6{"Single argument constructor"}; //explicit call of single argument constructor
}