#include<iostream>
using namespace std;

//#define May_25
//#define DefaultConstructors
#define CopyConstructors

class Point {
	double x;
	double y;
public:
	double get_x() const { return x; }
	double get_y() const { return y; }
		
	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }

	//Point() //default constructor
	//{	
	//	x = y = double();
	//}
	//Point(double x) //Single argument constructor
	//{
	//	this->x = x;
	//	this->y = double();
	//}

	Point(double x=0, double y=0) //just constructor
	{
		this->x = x;
		this->y = y;
	}
	Point(const Point& other) 
	{
		this->x = other.x;
		this->y = other.y;
	}
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	~Point() 
	{
		
	}
	
	//Methods:
	double distance(Point other) 
	{
		double x_dist = this->x - other.x;
		double y_dist = this->y - other.y;
		double dist = sqrt(x_dist*x_dist+y_dist*y_dist);
		return dist;
	}
	void print() const 
	{
		cout << "X=" << x << ", Y=" << y << endl;
	}
};

double distance(Point A,	Point B) 
{
	double x_dist = B.get_x() - A.get_x();
	double y_dist = B.get_y() - A.get_y();
	double dist = sqrt(x_dist * x_dist + y_dist * y_dist);
	return dist;
}

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