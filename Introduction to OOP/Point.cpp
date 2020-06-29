#include"Point.h"

double Point::get_x() const { return this->x; }
double Point::get_y() const { return this->y; }

void Point::set_x(double x) { this->x = x; }
void Point::set_y(double y) { this->y = y; }

Point::Point(double x, double y) //just constructor
{
	this->x = x;
	this->y = y;
}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
}
Point::~Point()
{

}

void Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
}

//Methods:
double Point::distance(Point other)
{
	double x_dist = this->x - other.x;
	double y_dist = this->y - other.y;
	double dist = sqrt(x_dist * x_dist + y_dist * y_dist);
	return dist;
}
void Point::print() const
{
	cout << "X=" << x << ", Y=" << y << endl;
}

double distance(Point A,	Point B) 
{
	double x_dist = B.get_x() - A.get_x();
	double y_dist = B.get_y() - A.get_y();
	double dist = sqrt(x_dist * x_dist + y_dist * y_dist);
	return dist;
}