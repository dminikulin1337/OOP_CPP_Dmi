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
	explicit Fraction(int integer) //Single argument constructor
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	explicit Fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		decimal *= 100000000;
		numerator = decimal;
		denominator = 100000000;
		reduce();
	}
	explicit Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}
	explicit Fraction(int integer, int numerator, int denominator)
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
	~Fraction() 
	{

	}
	Fraction& operator=(const Fraction& other) 
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	Fraction& operator+=(Fraction other) 
	{
		this->reduce().toImproper();
		other.reduce().toImproper();
		this->numerator = (this->numerator * other.denominator) + (this->denominator * other.numerator);
		this->denominator *= other.denominator;
		return this->reduce().toProper();
	}
	Fraction& operator-=(Fraction other)
	{
		this->reduce().toImproper();
		other.reduce().toImproper();
		this->numerator = (this->numerator * other.denominator) - (this->denominator * other.numerator);
		this->denominator *= other.denominator;
		return this->reduce().toProper();
	}
	Fraction& operator*=(Fraction other) 
	{
		this->reduce().toImproper();
		other.reduce().toImproper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->reduce().toProper();
	}
	Fraction& operator/=(Fraction other) 
	{
		this->reduce().toImproper();
		other.reduce().toImproper();
		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		return this->reduce().toProper();
	}
	/*Fraction operator*(const Fraction& other) const
	{
		Fraction res;
		Fraction left = this->toImproper();
		Fraction right = other.toImproper();
		res.numerator = left.numerator * right.numerator;
		res.denominator = left.denominator * right.denominator;
		res.reduce();
		res.toProper();
		return res;
	}*/
	Fraction& operator++()//Prefix
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix 
	{
		Fraction inc = *this;
		integer++;
		return inc;
	}
	Fraction operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	//Type-cast operators:
	explicit operator int()const { return integer; }
	
	explicit operator double() const
	{
		return integer + (double)numerator / denominator;
		//1. double/int=double
		//2. int+double=double
		//it's revolution, Johny...
	}

	
	void print() const{
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
	Fraction& toProper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& toImproper() 
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduce() 
	{
		if (numerator == 0) { 
			denominator = 1;
			return *this; 
		}
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
		return *this;
	}
};

Fraction operator+(Fraction left, Fraction right) 
{
	return Fraction(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).reduce().toProper();
}

Fraction operator-(Fraction left, Fraction right) 
{
	return Fraction(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).reduce().toProper();
}

Fraction operator*(Fraction left, Fraction right) 
{
	left.toImproper();
	right.toProper();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).reduce().toProper();
}

Fraction operator/(Fraction left, Fraction right) 
{
	left.toImproper();
	right.toImproper();
	return Fraction(left.get_numerator()*right.get_denominator(), left.get_denominator()*right.get_numerator()).reduce().toProper();
}

ostream& operator<<(ostream& os, const Fraction& other) 
{
	if (other.get_integer()) cout << other.get_integer();
	if (other.get_numerator())
	{
		//if (integer) cout << "(";
		if (other.get_integer()) cout << "+";
		cout << other.get_numerator() << "/" << other.get_denominator();
		//if (integer) cout << ")";
	}
	else if (other.get_integer() == 0)
	{
		cout << 0;
	}
	return os;
}

bool operator==(Fraction left, Fraction right)
{
	left.toImproper();
	right.toImproper();
	long double frac1 = (double)left.get_numerator() / (double)left.get_denominator();
	long double frac2 = (double)right.get_numerator() / (double)right.get_denominator();
	return(frac1 == frac2) ? true : false;
}
bool operator!=(Fraction left, Fraction right) 
{
	left.toImproper();
	right.toImproper();
	long double frac1 = (double)left.get_numerator() / (double)left.get_denominator();
	long double frac2 = (double)right.get_numerator() / (double)right.get_denominator();
	return(frac1 != frac2) ? true : false;
}
bool operator>(Fraction left, Fraction right) 
{
	left.toImproper();
	right.toImproper();
	long double frac1 = (double)left.get_numerator() / (double)left.get_denominator();
	long double frac2 = (double)right.get_numerator() / (double)right.get_denominator();
	return(frac1 > frac2) ? true : false;
}
bool operator<(Fraction left, Fraction right) 
{
	left.toImproper();
	right.toImproper();
	long double frac1 = (double)left.get_numerator() / (double)left.get_denominator();
	long double frac2 = (double)right.get_numerator() / (double)right.get_denominator();
	return(frac1 < frac2) ? true : false;
}
bool operator>=(Fraction left, Fraction right)
{
	left.toImproper();
	right.toImproper();
	long double frac1 = (double)left.get_numerator() / (double)left.get_denominator();
	long double frac2 = (double)right.get_numerator() / (double)right.get_denominator();
	return(frac1 >= frac2) ? true : false;
}
bool operator<=(Fraction left, Fraction right)
{
	left.toImproper();
	right.toImproper();
	long double frac1 = (double)left.get_numerator() / (double)left.get_denominator();
	long double frac2 = (double)right.get_numerator() / (double)right.get_denominator();
	return(frac1 <= frac2) ? true : false;
}

//#define Testing_constructors
//#define Testing_methods
//#define Plus_overloading
//#define Minus_overloading
//#define Multiply_overloading
//#define Division_overloading
//#define Comparison_overloading
//#define Inc_dec_overloading
#define Type_change

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
	Fraction A(7, 12);
	A.print();
	Fraction B(2, 1, 4);
	B.print();
	Fraction C = A + B;
	C.print();
	(A += B).print();
#endif // Plus_overloading

#ifdef Minus_overloading
	Fraction A(2, 7, 13);
	A.print();
	Fraction B(1, 4);
	B.print();
	Fraction C = A - B;
	C.print();
	(A -= B).print();
#endif // Minus_overloading

#ifdef Multiply_overloading
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(5, 7, 8);
	B.print();
	Fraction C = A * B;
	C.print();
	(A *= B).print();
#endif // Multiply_overloading

#ifdef Division_overloading
	Fraction A(2, 1, 2);
	A.print();
	Fraction B(2, 1, 4);
	B.print();
	Fraction C = A / B;
	C.print();
	(A /= B).print();
#endif // Division_overloading

#ifdef Comparison_overloading
	Fraction A(2, 2, 4);
	A.print();
	Fraction B(2, 1, 4);
	B.print();
	if (A != B) { Fraction C = A + B; C.print(); }
#endif // Comparison_overloading

#ifdef Inc_dec_overloading
	Fraction A(1, 5, 8);
	Fraction B = A++;
	B.print();
	cout << A << endl;
	cout << A + B << endl;
#endif // Inc_dec_overloading

#ifdef Type_change
	double weight = 3.25;
	//Explicit change:
	cout << (int)weight << endl;//C-like cast notation
	cout << int(weight) << endl;//Functional notation

	int a = 2;
	cout << a + weight << endl; //Implicit change

	double pi = 3.14;
	int ci = pi;//conversion from double to int - data loss!!!!!!(no fraction part here)
	cout << ci << endl;

	double c = 5;
	int d = c;//From double to int without data loss - Thanks, God!
	double e = d;//From int to double - no data loss guaranteed!!!

	Fraction A = (Fraction)5;	//Single argument constructor in work
	cout << A << endl;

	Fraction B(2, 1, 2);
	double b = (double)B;
	cout << b << endl;
	int f = (int)B;
	cout << f << endl;

	Fraction C(3.14);//Explicit constructor has to be used like this
	cout << C << endl;
	C(2, 7, 8);//instead of using set_() methods
	cout << C << endl;
#endif // Type_change

}