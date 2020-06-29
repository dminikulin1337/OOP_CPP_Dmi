#pragma once
#include<iostream>
using namespace std;

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& other);
bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	const int get_integer() const;
	const int get_numerator() const;
	const int get_denominator() const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	Fraction();//default constructor
	explicit Fraction(int integer); //Single argument constructor
	explicit Fraction(double decimal);
	explicit Fraction(int numerator, int denominator);
	explicit Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(Fraction other);
	Fraction& operator-=(Fraction other);
	Fraction& operator*=(Fraction other);
	Fraction& operator/=(Fraction other);
	/*Fraction operator*(const Fraction& other) const;*/
	Fraction& operator++();//Prefix
	Fraction operator++(int);//Postfix 
	Fraction operator()(int integer, int numerator, int denominator);

	//Type-cast operators:
	explicit operator int()const;
	explicit operator double() const;

	void print() const;
	Fraction& toProper();
	Fraction& toImproper();
	Fraction& reduce();
};