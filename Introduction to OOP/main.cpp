#include"Point.h"

//#define May_25
//#define DefaultConstructors
#define CopyConstructors

void main() 
{
#ifdef May_25
	Point A;
	A.set_x(0);
	A.set_y(0);

	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point C;
	C.set_x(4);
	C.set_y(3);
	cout <<"Distance from A to C: "<< A.distance(C) << endl;
	cout <<"Distance from C to C: " << C.distance(C) << endl;
	cout << "Distance from C to A: " << C.distance(A) << endl;

	cout << "Distance from A to C: " << distance(A, C) << endl;
#endif // May_25

	
	
#ifdef DefaultConstructors
	Point A;	//default constructor
	A.print();

	Point B = 2;	//Single argument constructor
	B.print();

	Point C(3);		//Another single argument constructor
	C.print();

	Point D(3, 3);		//just constructor
	D.print();
#endif // DefaultConstructors


#ifdef CopyConstructors
	Point A(2, 2);
	A.print();		//Copy constructor
	Point I = A;
	I.print();

	Point X;
	X = A;		//Operator= in work
	X.print();
#endif // CopyConstructors

}