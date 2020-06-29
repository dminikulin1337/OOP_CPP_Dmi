#pragma once
#include<iostream>
using namespace std;

class Point {
	double x;
	double y;
public:
	double get_x() const;
	double get_y() const;

	void set_x(double x);
	void set_y(double y);

	Point(double x = 0, double y = 0); //just constructor
	Point(const Point& other);
	void operator=(const Point& other);
	~Point();

	//Methods:
	double distance(Point other);
	void print() const;
};