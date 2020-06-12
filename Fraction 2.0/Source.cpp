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

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

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
	void toProper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void toImproper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce() 
	{
		//¬ дроби в любом случае что-то больше. „ислитель может юыть больше знаменател€ или наоборот.
		int more, less, reminder = 0;
		//More - большее значение 
		//Less - меньшее значение
		//Reminder - остаток от делени€
		if (numerator > denominator) 
		{
			more = numerator;
			less = denominator;
		}
		else 
		{
			more = denominator;
			less = numerator;
		}
		do 
		{
			reminder = more % less;
			more = less; //Ѕольшее число становитс€ на место делимого 
			less = reminder; //ћеньшее число становитс€ на место делител€
		} while (reminder);
		int GCD = more; //Greatest Common Divider - наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
	}
};

Fraction Fraction::operator+(const Fraction& other) 
{
	this->numerator = numerator * other.denominator + other.numerator * denominator;
	this->denominator = denominator * other.denominator;
	this->integer = integer + other.integer;
	return *this;
}
Fraction Fraction::operator-(const Fraction& other) 
{
	int temp_1num = numerator * other.denominator;
	int temp_2num = other.numerator * denominator;
	this->numerator = temp_1num - temp_2num;
	this->denominator = denominator * other.denominator;
	this->integer = integer - other.integer;
	return *this;
}
Fraction Fraction::operator*(const Fraction& other) 
{
	int temp_num1 = integer * denominator + numerator;
	int temp_num2 = other.integer * other.denominator + other.numerator;
	integer = 0;
	this->numerator = temp_num1*temp_num2;
	this->denominator = denominator * other.denominator;
	toProper();
	return *this;
}
Fraction Fraction::operator/(const Fraction& other) 
{
	int temp_num1 = integer * denominator + numerator;
	int temp_num2 = other.denominator;
	int temp_den2 = other.integer * other.denominator + other.numerator;
	integer = 0;
	this->numerator = temp_num1 * temp_num2;
	this->denominator = denominator * temp_den2;
	toProper();
	return *this;
}

//#define Testing_constructors
//#define Testing_methods
//#define Plus_overloading
//#define Minus_overloading
//#define Multiply_overloading
//#define Division_overloading

void main() 
{
#ifdef Testing_constructors
	Fraction A = 5;
	A.print();
	Fraction B(5, 1, 5);
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
#endif // Testing_constructors

#ifdef Testing_methods
	Fraction B(35, 15);
	B.print();
	B.toProper();
	B.print();
	B.toImproper();
	B.print();
	B.reduce();
	B.print();
	cout << "------------------------------------------------------------" << endl;
	Fraction C(251, 934);
	C.print();
	C.reduce();
	C.print();
#endif // Testing_methods

#ifdef Plus_overloading
	Fraction A(7, 13);
	A.print();
	Fraction B(2, 1, 4);
	B.print();
	Fraction C = A + B;
	C.print();
#endif // Plus_overloading

#ifdef Minus_overloading
	Fraction A(2, 7, 13);
	A.print();
	Fraction B(1, 4);
	B.print();
	Fraction C = A - B;
	C.print();
#endif // Minus_overloading

#ifdef Multiply_overloading
	Fraction A(2, 1, 2);
	A.print();
	Fraction B(2, 1, 4);
	B.print();
	Fraction C = A * B;
	C.print();
#endif // Multiply_overloading

#ifdef Division_overloading
	Fraction A(2, 1, 2);
	A.print();
	Fraction B(2, 1, 4);
	B.print();
	Fraction C = A / B;
	C.print();
#endif // Division_overloading


}