#include<iostream>
using namespace std;

class Fraction 
{
	int integer;
	int numerator;
	int denominator;
public:
	const int get_integer() const { return integer; }
	const int get_numerator() const { return numerator; }
	const int get_denominator() const { return denominator; }

	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) { 
		if (denominator == 0)  denominator = 1;
		this->denominator = denominator;
	}
	Fraction()//default constructor
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int integer) 
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int numerator, int denominator) 
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}
	Fraction(const Fraction& other) 
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction& operator=(const Fraction& other) 
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	~Fraction() 
	{

	}

	void print() const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			//if (integer) cout << "(";
			if (integer) cout << "+";
			cout << numerator << "/" << denominator;
			//if (integer) cout << ")";
		}
		else if (integer == 0)
		{
			cout << 0;
		}
		cout << endl;
	}
	void toProper(const Fraction&) 
	{
		if (numerator >= denominator)
		{
			integer += numerator / denominator;
			if (numerator == denominator) {
				numerator = 0;
				denominator = 0;
			}
			else 
			{
				numerator %= denominator;
			}
			print();
		}
		else return;
	}
	void toImproper(const Fraction&)
	{
		if (numerator < denominator && integer)
		{
			numerator += integer * denominator;
			integer = 0;
			print();
		}
		else return;
	}
	void reduce(const Fraction&) 
	{
		if (denominator % numerator == 0)
		{
			denominator /= numerator;
			numerator /= numerator;
			print();
		}
		else return;
	}
};

void main() 
{
	Fraction A=5;
	A.print();
	Fraction B(5,1,5);
	B.print();
	Fraction C(4, 8);
	C.print();
	Fraction D;
	D = C;
	D.print();
	Fraction E(B);
	E.print();
	Fraction X, Y, Z;
	X = Y = Z = A;
	cout << "---------------------------------------------------------------------" << endl;
	Fraction I(8, 5);
	I.print();
	I.toProper(I);
	cout << "---------------------------------------------------------------------" << endl;
	Fraction K(6, 2, 5);
	K.print();
	K.toImproper(K);
	cout << "---------------------------------------------------------------------" << endl;
	Fraction P(1,25,75);
	P.print();
	P.reduce(P);
}