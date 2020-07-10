#include<iostream>
#include<String.h>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

//ATTENTION!!! The author of ierarchy doesn't know how to draw some figures. He done what he could in drawing(outputing).

#define PI 3.14

class Figure //Фигуры вообще
{
public:
	virtual void draw() = 0;
};

class OneDimension :public Figure //Одномерные фигуры
{
public:
	virtual void length() = 0;
};

class Dot :public OneDimension
{
public:
	void draw() { cout << "Dot: " << char(249) << endl; }
	void length() { cout << "Dot has no length" << endl; }
};

class Line :public OneDimension
{
	double len;
public:
	double get_length() const { return len; }
	
	double set_length(double len)
	{
		if (len < 0) { len = -len; }
		return this->len = len;
	}
	Line()
	{
		this->len = 1;
	}
	Line(double len):len(set_length(len))
	{
		
	}
	~Line()
	{

	}
	void draw() 
	{
		cout << "Line" << endl;
		for (int i = 0; i < (int)len; i++)
		{
			cout << char(196);
		}
		cout << endl;
	}
	void length()
	{
		cout << len << " points" << endl; 
	}
};

class TwoDimension :public Figure //Двумерные фигуры
{
public:
	virtual void perimeter() = 0;
	virtual void area() = 0;
};

class Triangle :public TwoDimension
{
	double sideA;
	double sideB;
	double sideC;
public:
	double get_A() const { return sideA; }
	double get_B() const { return sideB; }
	double get_C() const { return sideC; }

	double set_A(double sideA)
	{
		if (sideA < 0)sideA = -sideA;
		return this->sideA = sideA;
	}
	double set_B(double sideB)
	{
		if (sideB < 0)sideB = -sideB;
		return this->sideB = sideB;
	}
	double set_C(double sideC)
	{
		if (sideC < 0)sideC = -sideC;
		return this->sideC = sideC;
	}

	Triangle()
	{
		this->sideA = 3;
		this->sideB = 4;
		this->sideC = 5;
	}
	Triangle(double sideA, double sideB, double sideC):
		sideA(set_A(sideA)),
		sideB(set_B(sideB)),
		sideC(set_C(sideC))
	{
		
	}
	~Triangle()
	{

	}
	void draw()
	{
		cout << "Triangle" << endl;
	}
	void perimeter()
	{
		cout << "Perimeter: " << get_A() + get_B() + get_C() << endl;
	}
	void area()
	{
		double p = 0.5 * (get_A() + get_B() + get_C());
		double h = 2 / get_A() * sqrt(p*(p-get_A()) * (p - get_B()) * (p - get_C()));
		double S = 0.5 * get_A() * h;
		cout << "Area: " << S << endl;
	}
};

class Paralelogram : public TwoDimension
{
	double sideA;
	double sideB;
	double angle;
public:
	double get_A() const { return sideA; }
	double get_B() const { return sideB; }
	double get_angle() const { return angle; }

	double set_A(double sideA)
	{
		if (sideA < 0) { sideA = -sideA; }
		return this->sideA = sideA;
	}
	double set_B(double sideB)
	{
		if (sideB < 0) { sideB = -sideB; }
		return this->sideB = sideB;
	}
	double set_angle(double angle)
	{
		if (angle < 0) { angle = -angle; }
		if (angle > 180) { angle = 180; }
		return this->angle = angle;
	}
	Paralelogram()
	{
		this->sideA = 5;
		this->sideB = 10;
		this->angle = 60;
	}
	Paralelogram(double sideA, double sideB): //Конструктор прямоугольника
		sideA(set_A(sideA)),
		sideB(set_B(sideB)),
		angle(NULL)
	{
		
	}
	Paralelogram(double sideA): //Конструктор квадрата
		sideA(set_A(sideA)),
		sideB(NULL),
		angle(NULL)
	{
		
	}
	Paralelogram(double sideA, double sideB, double angle): //Конструктор паралелепипеда
		sideA(set_A(sideA)),
		sideB(set_B(sideB)),
		angle(set_angle(angle))
	{
		
	}
	//Для ромба конструктор не получился(ошибка C2535: member function already defined or declared).
	//Рекомендую при создании объекта указать одинаковые размеры сторон.
	~Paralelogram()
	{

	}
	void draw()
	{
		if (sideB == 0 && angle == 0)
		{
			cout << "Square" << endl;
			cout << char(218);
			for (int i = 1; i < get_A() - 1; i++)
			{
				cout << char(196);
			}
			cout << char(191) << endl;
			for (int i = 1; i < get_A() - 1; i++)
			{
				cout << char(179);
				for (int j = 1; j < get_A() - 1; j++)
				{
					cout << " ";
				}
				cout << char(179) << endl;
			}
			cout << char(192);
			for (int i = 1; i < get_A() - 1; i++)
			{
				cout << char(196);
			}
			cout << char(217) << endl;
		}
		else if (angle == 0)
		{
			cout << "Rectangle" << endl;
			cout << char(218);
			for (int i = 1; i < get_A() - 1; i++)
			{
				cout << char(196);
			}
			cout << char(191) << endl;
			for (int i = 1; i < get_B() - 1; i++)
			{
				cout << char(179);
				for (int j = 1; j < get_A() - 1; j++)
				{
					cout << " ";
				}
				cout << char(179) << endl;
			}
			cout << char(192);
			for (int i = 1; i < get_A() - 1; i++)
			{
				cout << char(196);
			}
			cout << char(217) << endl;
		}
		else if (sideA == sideB) { cout << "Diamond" << endl; }
		else { cout << "Paralelogram" << endl; }
	}
	void perimeter()
	{
		if (sideA == sideB || (sideB==0 && angle==0)) { cout << "Perimeter: " << get_A() * 4 << endl; }
		else { cout << "Perimeter: " << (get_A() + get_B()) * 2 << endl; }
	}
	void area()
	{
		if (sideB == 0 && angle == 0) { cout << "Area: " << get_A() * get_A() << endl; }
		else if (angle == 0) { cout << "Area: " << get_B() * get_A() << endl; }
		else { cout << "Area: " << get_A() * get_B() * sin(get_angle() * PI / 180) << endl; }
	}
};

class Circle : public TwoDimension
{
	double radius;
public:
	double get_radius() const { return radius; }
	
	double set_radius(double radius)
	{
		if (radius < 0) { radius = -radius; }
		return this->radius = radius;
	}
	Circle()
	{
		this->radius = 5;
	}
	Circle(double radius):radius(set_radius(radius))
	{

	}
	~Circle()
	{

	}
	void draw()
	{
		cout << "Circle" << endl;
	}
	void perimeter()
	{
		cout << "Length of circle: " << 2 * PI * get_radius() << endl;
	}
	void area()
	{
		cout << "Area: " << PI * (get_radius() * get_radius()) << endl;
	}
};

class ThreeDimension :public Figure
{
public:
	virtual void area() = 0;
	virtual void volume() = 0;
};

class Paralelepiped : public ThreeDimension 
{
	double sideX;
	double sideY;
	double sideZ;
public:
	double get_X() const { return sideX; }
	double get_Y() const { return sideY; }
	double get_Z() const { return sideZ; }

	double set_X(double sideX)
	{
		if (sideX < 0) { sideX = -sideX; }
		return this->sideX = sideX;
	}
	double set_Y(double sideY)
	{
		if (sideY < 0) { sideY = -sideY; }
		return this->sideY = sideY;
	}
	double set_Z(double sideZ)
	{
		if (sideZ < 0) { sideZ = -sideZ; }
		return this->sideZ = sideZ;
	}

	Paralelepiped()
	{
		this->sideX = 3;
		this->sideY = 4;
		this->sideZ = 5;
	}
	Paralelepiped(double sideX): //Конструктор куба
		sideX(set_X(sideX)),
		sideY(NULL),
		sideZ(NULL)
	{
	
	}
	Paralelepiped(double sideX, double sideY, double sideZ):
		sideX(set_X(sideX)),
		sideY(set_Y(sideY)),
		sideZ(set_Z(sideZ))
	{

	}
	~Paralelepiped()
	{

	}

	void draw()
	{
		if (sideY == 0 && sideZ == 0) { cout << "Cube" << endl; }
		else { cout << "Paralelepiped" << endl; }
	}
	void area()
	{
		if (sideY == 0 && sideZ == 0) { cout << "Area of cover: " << (get_X() * get_X()) * 6 << endl; } //В случае, если нам нужен куб
		else { cout << "Area of cover: " << (get_X() * get_Y() + get_Y() * get_Z() + get_X() * get_Z())*2 << endl; }
	}
	void volume()
	{
		if (sideY == 0 && sideZ == 0) { cout << "Volume: " << get_X() * get_X() * get_X() << endl; } //В случае, если нам нужен куб
		else { cout << "Volume: " << get_X() * get_Y() * get_Z() << endl; }
	}
};

class Pyramid : public ThreeDimension //Только правильная пирамида - с квадратной основой
{
	double edge;
	double height;
public:
	double get_edge() const { return edge; }
	double get_height() const { return height; }

	double set_edge(double edge)
	{
		if (edge < 0) { edge = -edge; }
		return this->edge = edge;
	}
	double set_height(double height)
	{
		if (height < 0) { height = -height; }
		return this->height = height;
	}
	Pyramid()
	{
		this->edge = 5;
		this->height = 10;
	}
	Pyramid(double edge, double height):
		edge(set_edge(edge)),
		height(set_height(height))
	{

	}
	~Pyramid()
	{

	}
	void draw()
	{
		cout << "Pyramid" << endl;
	}
	void area()
	{
		double b = sqrt(get_edge() * get_edge() + get_height() * get_height());
		double sbottom = get_edge() * get_edge();
		double S = sbottom + 2 * get_edge() * sqrt(b * b + sbottom / 4);
		cout << "Area of cover: " << S << endl;
	}
	void volume()
	{
		cout << "Volume: " << 0.33 * (get_edge() * get_edge()) * get_height() << endl;
	}
};

class Cone : public ThreeDimension
{
	double r;
	double height;
public:
	double get_r() const { return r; }
	double get_height() const { return height; }

	double set_r(double r)
	{
		if (r < 0) { r = -r; }
		return this->r = r;
	}
	double set_height(double height)
	{
		if (height < 0) { height = -height; }
		return this->height = height;
	}

	Cone()
	{
		this->r = 5;
		this->height = 5;
	}
	Cone(double r, double height):
		r(set_r(r)),
		height(set_height(height))
	{

	}
	~Cone()
	{

	}
	void draw()
	{
		cout << "Cone" << endl;
	}
	void area()
	{
		double b = sqrt(get_r() * get_r() + get_height() * get_height());
		cout << "Area: " << b * PI * get_height() << endl;
	}
	void volume()
	{
		double S = get_r() * get_r() * PI;
		cout << "Volume: " << 0.33 * S * get_height() << endl;
	}
};

class Sphere : public ThreeDimension
{
	double r;
public:
	double get_r() const { return r; }

	double set_r(double r)
	{
		if (r < 0) { r = -r; }
		return this->r = r;
	}

	Sphere()
	{
		this->r = 5;
	}
	Sphere(double r):r(set_r(r))
	{

	}
	~Sphere()
	{

	}
	void draw() { cout << "Sphere" << endl; }
	void area()
	{
		cout << "Area: " << 4 * PI * get_r() * get_r() << endl;;
	}
	void volume()
	{
		cout << "Volume: " << 1.33 * PI * (get_r() * get_r() * get_r()) << endl;
	}
};

int main()
{
	Dot dot;
	dot.draw();
	dot.length();

	cout << "\n";

	Line line(20.34);
	line.draw();
	line.length();

	cout << "\n";

	Triangle t(3, 4, 5);
	t.draw();
	t.perimeter();
	t.area();

	cout << "\n";

	Paralelogram paralel(5, 4, 30);
	paralel.draw();
	paralel.perimeter();
	paralel.area();

	cout << "\n";

	Paralelogram rectangle(10, 8);
	rectangle.draw();
	rectangle.perimeter();
	rectangle.area();

	cout << "\n";

	Paralelogram diamond(5, 5, 60);
	diamond.draw();
	diamond.perimeter();
	diamond.area();

	cout << "\n";

	Paralelogram square(7);
	square.draw();
	square.perimeter();
	square.area();

	cout << "\n";

	Paralelepiped piped;
	piped.draw();
	piped.area();
	piped.volume();

	cout << "\n";

	Paralelepiped cube(5);
	cube.draw();
	cube.area();
	cube.volume();

	cout << "\n";

	Pyramid pyramid;
	pyramid.draw();
	pyramid.area();
	pyramid.volume();

	cout << "\n";

	Cone cone;
	cone.draw();
	cone.area();
	cone.volume();

	cout << "\n";

	Sphere sphere;
	sphere.draw();
	sphere.area();
	sphere.volume();

	return 0;
}