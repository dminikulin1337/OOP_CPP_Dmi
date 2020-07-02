#include<iostream>
#include<string>
using namespace std;

class BOX 
{
	double width;
	double height;
	double length;
public:
	double get_width() const { return width; }
	double get_height() const { return height; }
	double get_length() const { return length; }

	double set_width(double width) 
	{
		if (width < 0) { width = -width; }
		return this->width = width;
	}
	double set_height(double height)
	{
		if (height < 0) { height = -height; }
		return this->height = height;
	}
	double set_length(double length)
	{
		if (length < 0) { length = -length; }
		return this->length = length;
	}
	BOX(double width, double height, double length) :
		width(set_width(width)), 
		height(set_height(height)), 
		length(set_length(length))
	{
		cout << "B___constructor: " << this << endl;
	}
	~BOX()
	{
		cout << "B___destrutor: " << this << endl;
	}
	//methods
	void print() const 
	{
		cout << width << "x" << height << "x" << length << endl;;
	}
};

class GiftBox:public BOX
{
	string cover;
	bool tie;
public:
	const string& get_cover() const 
	{
		return this->cover;
	}
	bool get_tie() const 
	{
		return this->tie;
	}

	GiftBox(double width, double height, double length, const string& cover, bool tie):BOX(width, height, length)
	{
		this->cover = cover;
		this->tie = tie;
		cout << "GB___constructor: " << this << endl;
	}
	~GiftBox()
	{
		cout << "GB___destructor: " << this << endl;
	}

	void print() const 
	{
		BOX::print();
		cout << "Cover is " << cover << endl;
		cout << "Is there a tie? " << (tie? "Yes!" : "Nope") << endl;
	}
};
void main() 
{
	setlocale(LC_ALL, "");
	/*BOX A(2, 3, 4);
	A.print();*/
	GiftBox gb(2, 3, 4, "blue and yellow", true);
	gb.print();
}