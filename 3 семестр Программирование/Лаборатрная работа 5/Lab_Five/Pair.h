#pragma once
#include "Object.h"
#include<iostream>
class Pair : public Object
{
public:
	Pair(void);
public:
	virtual ~Pair(void);
	void show();
	Pair(int, int);
	Pair(const Pair&);
	int Get_first() { return first; }
	int Get_second() { return second; }
	void Set_first(int);
	void Set_second(int);
	Pair& operator=(const Pair&);
	bool operator==(const Pair&);
		bool operator>(const Pair&);
	bool operator<(const Pair&);
	friend std::istream& operator>>(std::istream&in, Pair&p);
	friend std::ostream& operator<<(std::ostream&out, const Pair&p);

protected:
	int first;
	int second;
};


