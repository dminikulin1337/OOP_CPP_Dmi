#pragma once
#include<iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& other);

class String
{
	int size;
	char* str;
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();

	void set_size(int size);
	void set_str(char* str);

	explicit String(int size = 80);
	String(const char str[]);//constructor
	String(const String& other);//copy constructor
	String(String&& other);
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);
	//Methods:
	void print() const;
};