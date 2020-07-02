#include<iostream>
#include<string>
using namespace std;

class Human 
{
	string name;
	string surname;
	int age;
	string gender;
public:
	const string& get_name() const { return this->name; }
	const string& get_surname() const { return this->surname; }
	int get_age() const { return age; }
	const string& get_gender() { return this->gender; }

	int set_age(int age)
	{
		if (age < 0) { age = -age; }
		return this->age = age;
	}
	Human(const string& name, const string& surname, int age, const string& gender) :
		name(name),
		surname(surname),
		age(set_age(age)),
		gender(gender)
	{
		/*cout << "H___constructor: " << this << endl;*/
	}
	~Human()
	{
		/*cout << "H___destructor: " << this << endl;*/
	}
	void print()const
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
		cout << "Gender: " << gender << endl;
	}
};

class Student :public Human
{
	string group;
	int rating;
	int attendance;
	string speciality;
public:
	const string& get_group() const { return this->group; }
	int get_rating()const { return rating; }
	int get_attendance()const { return attendance; }
	const string& get_speciality()const { return this->speciality; }

	int set_rating(int rating)
	{
		if (rating == 0) { rating = 1; }
		if (rating < 0) { rating = -rating; }
		return this->rating = rating;
	}
	int set_attendance(int attendance)
	{
		if (attendance < 0) { attendance = -attendance; }
		if (attendance > 100 || (attendance > 100 && attendance < 0)) { attendance = 100; }
		return this->attendance = attendance;
	}
	Student(const string& name, const string& surname, int age, const string& gender,
		const string& group, int rating, int attendance, const string& speciality) :
		Human(name, surname, age, gender) 
	{
		this->group = group;
		this->rating = set_rating(rating);
		this->attendance = set_attendance(attendance);
		this->speciality = speciality;
		/*cout << "S____constructor: " << this << endl;*/
	}
	~Student()
	{
		/*cout << "S___destructor: " << this << endl;*/
	}
	void print() const
	{
		Human::print();
		cout << "Group: " << group << endl;
		cout << "Place in rating: " << rating << endl;
		cout << "Attendance: " << attendance << endl;
		cout << "Speciality: " << speciality << endl;
	}
};

class Teacher :public Human 
{
	string subject;
	string experience;
	string specialiti;
	bool kindness;
public:
	const string& get_subject() const { return this->subject; }
	const string& get_experiexnce() const { return this->experience; }
	const string& get_specialiti() const { return this->specialiti; }
	bool get_kindness() const { return this->kindness; }

	Teacher(const string& name, const string& surname, int age, const string& gender,
		const string& subject, const string& experience, const string& specialiti, bool kindness) :
		Human(name, surname, age, gender) 
	{
		this->subject = subject;
		this->experience = experience;
		this->specialiti = specialiti;
		this->kindness = kindness;
		/*cout << "T___constructor: " << this << endl;*/
	}
	~Teacher()
	{
		/*cout << "T___destructor: " << this << endl;*/
	}

	void print() const 
	{
		Human::print();
		cout << "Subject: " << subject << endl;
		cout << "Experience: " << experience << endl;
		cout << "Speciality: " << specialiti << endl;
		cout << "Is this teacher kind? " << (kindness ? "Yes" : "No") << endl;
	}
};

//#define HUMAN
#define STUDENT
#define TEACHER

void main()
{
#ifdef HUMAN
	Human D("Andrii", "Poltava", 35, "Male");
	D.print();
#endif // HUMAN

	cout << "\n <<<---------------------------------------------------------------------------------------------------------->>>\n" << endl;
#ifdef STUDENT
	Student BP("Dmytro", "Nikulin", 16, "Male", "PV911", 3, 92, "Software development");
	BP.print();
#endif // STUDENT

	cout << "\n <<<---------------------------------------------------------------------------------------------------------->>>\n" << endl;
#ifdef TEACHER
	Teacher EM("Andrii", "Kobylinsliy", 40, "Male", "Hardware/Windows configuration", "20 years", "System administrator", true);
	EM.print();
#endif // TEACHER

}