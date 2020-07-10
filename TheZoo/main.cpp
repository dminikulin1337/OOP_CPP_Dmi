#include<iostream>
using namespace std;

class Animal //Abstract main class
{
	int hunger;
public:
	virtual void sound() = 0;
};

class Cat : public Animal
{
public:
	void sound() { cout << "Meow" << endl; }
};

class Dog: public Animal
{
	int evil;
public:
	void sound() { cout << "Bark" << endl; }
};
void main()
{
	//Animal animal; //Can't make instance(Нельзя сделать экземляр)
	Cat cat;
	cat.sound();
	Dog dog;
	dog.sound();
}