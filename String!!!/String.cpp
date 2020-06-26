#include"String.h"

int String::get_size() const { return this->size; }
const char* String::get_str() const { return this->str; }
char* String::get_str() { return this->str; }

void String::set_size(int size) { this->size = size; }
void String::set_str(char* str) { this->str = str; }

String::String(int size)
{
	this->size = size;
	this->str = new char[size] {};
}
String::String(const char str[])//constructor
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
}
String::String(const String& other)//copy constructor
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "Move constructor in work: " << this << endl;
}
String::~String()
{
	delete[] str;
}

String& String::operator=(const String& other)
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
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "Move assignment in work: " << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
	//return *this += other; - infinite recursion
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//Methods:
void String::print() const
{
	cout << "Size: " << size << endl;
	cout << "Str: " << str << endl;
}

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
		cat[i + left.get_size() - 1] = right[i];
	}
	return cat;
}


ostream& operator<<(ostream& os, const String& other)
{
	return os << other.get_str();
}