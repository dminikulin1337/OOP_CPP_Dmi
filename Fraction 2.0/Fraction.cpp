#include"Fraction.h"

const int Fraction::get_integer() const { return integer; }
const int Fraction::get_numerator() const { return numerator; }
const int Fraction::get_denominator() const { return denominator; }

void Fraction::set_integer(int integer) { this->integer = integer; }
void Fraction::set_numerator(int numerator) { this->numerator = numerator; }
void Fraction::set_denominator(int denominator) {
	if (denominator == 0)  denominator = 1;
	this->denominator = denominator;
}

Fraction::Fraction()//default constructor
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
}
Fraction::Fraction(int integer) //Single argument constructor
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
}
Fraction::Fraction(double decimal)
{
	integer = decimal;
	decimal -= integer;
	decimal *= 100000000;
	numerator = decimal;
	denominator = 100000000;
	reduce();
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}
Fraction::~Fraction()
{

}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}
Fraction& Fraction::operator+=(Fraction other)
{
	this->reduce().toImproper();
	other.reduce().toImproper();
	this->numerator = (this->numerator * other.denominator) + (this->denominator * other.numerator);
	this->denominator *= other.denominator;
	return this->reduce().toProper();
}
Fraction& Fraction::operator-=(Fraction other)
{
	this->reduce().toImproper();
	other.reduce().toImproper();
	this->numerator = (this->numerator * other.denominator) - (this->denominator * other.numerator);
	this->denominator *= other.denominator;
	return this->reduce().toProper();
}
Fraction& Fraction::operator*=(Fraction other)
{
	this->reduce().toImproper();
	other.reduce().toImproper();
	this->numerator *= other.numerator;
	this->denominator *= other.denominator;
	return this->reduce().toProper();
}
Fraction& Fraction::operator/=(Fraction other)
{
	this->reduce().toImproper();
	other.reduce().toImproper();
	this->numerator *= other.denominator;
	this->denominator *= other.numerator;
	return this->reduce().toProper();
}
/*Fraction Fraction::operator*(const Fraction& other) const
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
Fraction& Fraction::operator++()//Prefix
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)//Postfix 
{
	Fraction inc = *this;
	integer++;
	return inc;
}
Fraction Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
//Type-cast operators:
Fraction::operator int()const { return integer; }

Fraction::operator double() const
{
	return integer + (double)numerator / denominator;
	//1. double/int=double
	//2. int+double=double
	//it's revolution, Johnny...
}


void Fraction::print() const {
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
Fraction& Fraction::toProper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::toImproper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::reduce()
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
	return Fraction(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator()).reduce().toProper();
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