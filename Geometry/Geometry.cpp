#include<iostream>
#include<string>
#include<Windows.h>
#include<cmath>
using namespace std;

#define PI 3.14
namespace Geometry
{
	class Figure
	{
		string color;
	public:
		Figure(string color = "White") { this->color = color; }
		virtual ~Figure() {};

		virtual double area() const = 0;
		virtual double perimeter() const = 0;
		virtual void draw() const = 0;
	};

	class Square : public Figure
	{
		double side;
	public:
		double get_side() const { return side; }
		double set_side(double side)
		{
			if (side < 0) { side = -side; }
			return this->side = side;
		}

		Square(double side) :side(set_side(side))
		{

		}
		~Square()
		{

		}
		double area() const { return side * side; }
		double perimeter() const { return side * 4; }
		void draw()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "*";
				}
				cout << "\n";
			}
		}
	};

	class Rectangle :public Figure
	{
		double side1;
		double side2;
	public:
		double get_side1() const { return side1; }
		double get_side2() const { return side2; }

		double set_side1(double side1)
		{
			if (side1 < 0) { side1 = -side1; }
			return this->side1 = side1;
		}
		double set_side2(double side2)
		{
			if (side2 < 0) { side2 = -side2; }
			return this->side2 = side2;
		}

		Rectangle(double side1, double side2)
		{
			set_side1(side1);
			set_side2(side2);
		}
		~Rectangle() {}

		double area() const
		{
			return side1 * side2;
		}
		double perimeter() const
		{
			return (side1 + side2) * 2;
		}
		double diagonal() const
		{
			return sqrt(pow(side1, 2) + pow(side2, 2));
		}
		void draw() const
		{
			for (int i = 0; i < side1; i++)
			{
				for (int j = 0; j < side2; j++)
				{
					cout << "*";
				}
				cout << "\n";
			}
		}
	};
	
	class Triangle : public Figure
	{
		double side1, side2, side3;
	public:
		double get_1()const { return side1; }
		double get_2()const { return side2; }
		double get_3()const { return side3; }

		double set_1(double side1)
		{
			if (side1 < 0) { side1 = -side1; }
			return this->side1 = side1;
		}
		double set_2(double side2)
		{
			if (side2 < 0) { side2 = -side2; }
			return this->side2 = side2;
		}
		double set_3(double side3)
		{
			if (side3 < 0) { side3 = -side3; }
			return this->side3 = side3;
		}

		Triangle(double side1, double side2, double side3)
		{
			set_1(side1);
			set_2(side2);
			set_3(side3);
			if (side3 >= (side1 + side2) || side1 >= (side2 + side3) || side2 >= (side1 + side3)) { throw std::exception("Wrong side picked"); }
		}
		~Triangle() {}

		double area() const
		{
			double p = perimeter() / 2;
			return sqrt(p * (p - side1) * (p - side2) * (p - side3));
		}
		double perimeter() const
		{
			return side1 + side2 + side3;
		}
		void draw() const
		{

		}
	};
}
int main()
{
	setlocale(LC_ALL, "");
	Geometry::Square sq(5);
	cout << "Площадь квадрата: " << sq.area() << endl;
	cout << "Периметр квадрата: " << sq.perimeter() << endl;
	sq.draw();
	
	Geometry::Rectangle rect(5, 8);
	cout << "Площадь прямоугольника: " << rect.area() << endl;
	cout << "Периметр прямоугольника: " << rect.perimeter() << endl;
	cout << "Диагональ прямоугольника: " << rect.diagonal() << endl;
	rect.draw();

	try
	{
		Geometry::Triangle trgl(6, 7, 7);
		cout << "Площадь треугольника: " << trgl.area() << endl;
		cout << "Периметр треугольника: " << trgl.perimeter() << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	
	return 0;
}