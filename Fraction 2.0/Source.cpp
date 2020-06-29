#include"Fraction.h"

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