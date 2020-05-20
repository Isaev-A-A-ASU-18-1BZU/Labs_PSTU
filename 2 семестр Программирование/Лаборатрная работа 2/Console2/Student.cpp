#include "Student.h"
#include<string>
#include<iostream>

using namespace std;

Student::Student()
{
		name = ""; 
		group = "";  
		bal = 0.0;  
		cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

Student::Student(string N, string K, float S)
{
	name = N;
	group = K;
	bal = S;
	cout << "Constructor s parametrami dlia objecta " << this << endl;
}

Student::Student(const Student &t)
{
	name = t.name;
	group = t.group;
	bal = t.bal;
	cout << "Constructor copirovania dlia objecta " << this << endl;
}
Student & Student::operator=(const Student &t)
{
	if (&t == this) return *this;
	name = t.name;
	group = t.group;
	bal = t.bal;
	return *this;
}

Student::~Student()
{
	cout << "~Destructor dlia objecta   " << this << endl;
}

string Student::get_name()
{
	return name;
}

string Student::get_group()
{
	return group;
}
float Student::get_bal()
{
	return bal;
}

void Student::set_name(string N)
{
	name = N;
}
void Student::set_group(string K)
{
	group = K;
}

void Student::set_bal(float S)
{
	bal = S;
}
void Student::show()
{
	cout << "Name student: " << name << endl;
	cout << "Group of student: " << group << endl;
	cout << "Midle bal: " << bal << endl;
}
