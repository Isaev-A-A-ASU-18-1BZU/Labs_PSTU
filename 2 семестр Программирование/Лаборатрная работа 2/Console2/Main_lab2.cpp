#include "Student.h" 
#include <iostream> 
#include <string> 

using namespace std;

 Student make_student()
{
	string s;
	string i;
	float d;
	cout << "Enter name - "; cin >> s;
	cout << "\nEnter group - "; cin >> i;
	cout << "\nEnter bal - "; cin >> d;
	Student t(s, i, d);
	return t;
}

 void print_stutent(Student t)
 {
	 t.show();
 }

 int main()
 {
	 setlocale(LC_ALL, "Russian");
	 Student t1;
	 Student t4;
	 Student *t5;
	 t5 = new Student;
	 *t5 = t4;
	 t1.show();
	 Student t2("Egor", "EVT", 3.8);
	 t2.show();
	 Student t3 = Student(t2);
	 t3.show();
	 cout << "Enter t4" << endl;
	 (*t5).set_name("Alex");
	 t5->set_group("WST");
	 t5->set_bal(5);
	 t5->show();
	 //cout << "Адресс t5 - " << &t5<< endl;
	 t5->~Student();
	 t5->show();

	 return 0;
 }