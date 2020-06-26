#include<iostream>
#include<string>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;
	char* str;
public:
	int get_size() const { return this->size; }
	const char* get_str() const { return this->str; }
	char* get_str() { return this->str; }

	void set_size(int size) { this->size = size; }
	void set_str(char* str) { this->str = str; }

	explicit String(int size = 80) : size(size), str(new char[size] {})
	{
		
	}
	String(const char str[]) :String(strlen(str)+1)//constructor
	{
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
	}
	String(const String& other):String(other.str)//copy constructor
	{
		
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "Move constructor in work: " << this << endl;
	}
	~String()
	{
		delete[] str;
	}

	String& operator=(const String& other)
	{
		if (this == &other) { return *this; }
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "Move assignment in work: " << this << endl;
		return *this;	
	}
	String& operator+=(const String& other) 
	{
		return *this = *this + other;
		//return *this += other; - infinite recursion
	}
	const char& operator[](int i)const 
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//Methods:
	void print() const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
};

String operator+(const String& left, const String& right) 
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) 
	{
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		//cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
		cat[i+left.get_size()-1] = right[i];
	}
	return cat;
}


ostream& operator<<(ostream& os, const String& other)
{
	return os<<other.get_str();
}

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