#include<iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class String
{
	int size;
	char* str;
public:
	const int get_size() const { return size; }
	const char* get_str() const { return str; }

	void set_size(int size) { this->size = size; }
	void set_str(char* str) { this->str = str; }

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
	}
	String(const char str[])//constructor
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i<other.size; i++) 
		{
			this->str[i] = other.str[i];
		}
	}
	String operator=(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < other.size; i++)
		{
			this->str[i] = other.str[i];
		}
		return *this;
	}
	~String()
	{
		delete[] str;
	}

	//Methods:
	void print() const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& other)
{
	cout << "Size: " << other.get_size() << endl;
	cout << "Str: " << other.get_str() << endl;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
	String str;
	str.print();
	String str1 = "Hello";
	str1.print();
	String str2 = str1;
	cout << str2 << endl;
	str = str2;
	cout << str << endl;
}