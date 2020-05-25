#include<iostream>
using namespace std;

class Point //Main class with encapsulation
{
	double x;
	double y;
public:
	double get_x() const { return x; }
	double get_y() const { return y; }
		
	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }

	//Constructor
	Point()
	{	
			
	}
	//Destructor
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
};

double distance(Point A, Point B) 
{
	double x_dist = B.get_x() - A.get_x();
	double y_dist = B.get_y() - A.get_y();
	double dist = sqrt(x_dist * x_dist + y_dist * y_dist);
	return dist;
}

void main() 
{
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
}