#include "time.h"
#include <iostream>

using namespace std;

time & time::operator=(const time &t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;

}

bool time::operator==(const time &t)
{
		int temp1 = min * 60 + sec;
		int temp2 = t.min * 60 + t.sec;
		if (temp1 == temp2)
			return true;
		else return false;
}

time time::operator+(const time &t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

istream & operator >> (istream & in, time &t)
{
	cout << " minutes - "; in >> t.min;
	cout << " seconds  - "; in >> t.sec;
	return in;
}

ostream & operator<<(ostream & out, const time & t)
{
	return (out << t.min << " : " << t.sec);
}
