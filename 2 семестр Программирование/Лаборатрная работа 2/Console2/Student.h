#pragma once
#include<iostream>
#include<string>

using namespace std;

class Student
{
	string name; 
	string group;
	float bal;
public:
	Student();
	Student(string, string, float);
	Student(const Student&);
	Student &operator=(const Student&);
	~Student();
	string get_name();
	void set_name(string);
	string get_group();
	void set_group(string);
	float get_bal();
	void set_bal(float); 	
	void show();
};


