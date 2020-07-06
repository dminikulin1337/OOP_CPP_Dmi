#include<iostream>
#include<string>
using namespace std;

class Human 
{
	string name;
	string surname;
	unsigned int age;
public:
	const string& get_name() const { return name; }
	const string& get_surname() const { return surname; }
	unsigned int get_age() const { return age; }

	string& set_name(const string& name) { return this->name = name; }
	string& set_surname(const string& surname) { return this->surname = surname; }
	unsigned int set_age(unsigned int age) { return this->age = age; }

	Human(const string& name, const string& surname, unsigned int age)
	{
		set_name(name);
		set_surname(surname);
		set_age(age);
	}
	~Human()
	{
		
	}
	void print()const
	{
		cout << name << " " << surname << " " << age << " год.\n";
	}
};

class Student :public Human
{
	string group;
	unsigned int rating;
	unsigned int attendance;
public:
	const string& get_group()const { return group; }
	unsigned int get_rating()const { return rating; }
	unsigned int get_attendance()const { return attendance; }

	string& set_group(const string& group) { return this->group = group; }
	unsigned int set_rating(unsigned int rating) { return this->rating = rating; }
	unsigned int set_attedance(unsigned int attendance) { return this->attendance = attendance; }

	Student(const string& name, const string& surname, unsigned int age,
		const string& group, unsigned int rating, unsigned int attendance
	) :Human(name, surname, age)
	{
		set_group(group);
		set_rating(rating);
		set_attedance(attendance);
	}
	~Student() 
	{
		
	}
	void print() const 
	{
		Human::print();
		cout << group << " Рейтинг: " << rating << " Посещаемость: " << attendance << "\n";
	}
};

class Teacher :public Human 
{
	string spec;
	unsigned int exp;
public:
	const string& get_spec()const { return spec; }
	unsigned int get_exp()const { return exp; }

	string& set_spec(const string& spec) { return this->spec = spec; }
	unsigned int set_exp(unsigned int exp) { return this->exp = exp; }

	Teacher(const string& name, const string& surname, unsigned int age,
		const string& spec, unsigned int exp
	) :Human(name, surname, age) 
	{
		set_spec(spec);
		set_exp(exp);
	}
	~Teacher() 
	{

	}
	void print() const
	{
		Human::print();
		cout << "Специальность: " << spec << " Опыт работы: " << exp << "\n";
	}
};

class Graduate :public Student
{
	string topic;
public:
	const string& get_topic() const { return topic; }
	string& set_topic(const string& topic) { return this->topic = topic; }

	Graduate(const string& name, const string& surname, unsigned int age,
		const string& group, unsigned int rating, unsigned int attendance,
		const string& topic):Student(name, surname, age, group, rating, attendance)
	{
		set_topic(topic);
	}
	Graduate(const Student& BP, const string& topic):Student(BP)
	{
		set_topic(topic);
	}
	~Graduate()
	{

	}
	void print()const 
	{
		Student::print();
		cout << "Тема работы: " << topic << "\n";
	}
};

//#define HUMAN
//#define STUDENT
//#define TEACHER
//#define GRADUATE
#define ARRAY_OMG

void main()
{
	setlocale(LC_ALL, "");
#ifdef HUMAN
	Human D("TТ", "Абвгдеёж", 35);
	D.print();
#endif // HUMAN

	//cout << "\n <<<---------------------------------------------------------------------------------------------------------->>>\n" << endl;
#ifdef STUDENT
	Student BP("Вячеслав", "Мясников", 36, "PV911", 3, 90);
	//BP.print();
#endif // STUDENT

#ifdef TEACHER
	Teacher EM("Александр", "Попов", 40, "Пишет юмористические номера", 20);
	EM.print();
#endif // TEACHER

#ifdef GRADUATE
	cout << "\n <<<---------------------------------------------------------------------------------------------------------->>>\n" << endl;
	Graduate DS("Маркус", "Хэлоуей", 24, "DedSec", 1, 0, "Почему ctOS неэффективна?");
	DS.print();
	cout << "\n <<<---------------------------------------------------------------------------------------------------------->>>\n" << endl;
	Graduate VS(BP, "Глубинный смысл песен Уральских Пельменей");
	VS.print();
#endif // GRADUATE

	Human group[] =
	{
		Student("Sitara", "Dhavan", 27, "DedSec", 3, 100),
		Student("Wrench", "", 20, "DedSec", 2, 100),
		Teacher("Trey", "Stelmann", 40, "Cyber Security", 20),
		Student("Josh", "Sauchak", 21, "DedSec", 4, 100),
		Teacher("Jason", "Texas", 40, "Hardware PC", 20),
		Graduate("Marcus", "Holloway", 24, "DedSec", 1, 0, "Why ctOS is failed?")
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human); i++)
	{
		group[i].print();
	}
}