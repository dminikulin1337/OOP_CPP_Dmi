#include<iostream>
using namespace std;

class Point //Main class with encapsulation
{
	double x;
	double y;
	
	double disp;
	double dist;
public:
	double get_x() const { return x; }
	double get_y() const { return y; }
	
	double get_disp() const { return disp; }
	double get_dist() const { return dist; }
	
	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	
	void set_disp(double x, double y) 
	{
		double disp = sqrt(pow(x, 2) + pow(y, 2));
		this->disp = disp;
	}
	void set_dist(double x, double y, double x1, double y1) 
	{
		double k1 = x1 - x;
		double k2 = y1 - y;
		double dist = sqrt(pow(k1,2)+pow(k2,2));
		this->dist = dist;
	}
};

class Point3D :public Point //Inheritated class frae Point
{
	double z;
public:
	double get_z() const { return z; }
	void set_z(double z) { this->z = z; }
};

void main() 
{
	Point A;
	A.set_x(2);
	A.set_y(3);
	
	A.set_disp(100,100);
	A.set_dist(3,5,8,6);
	
	cout << A.get_x() << "\t" << A.get_y() << endl;
	
	cout << A.get_disp() << endl;
	cout << A.get_dist() << endl;

	Point3D B;
	B.set_x(2);
	B.set_y(3);
	B.set_z(4);
	
}