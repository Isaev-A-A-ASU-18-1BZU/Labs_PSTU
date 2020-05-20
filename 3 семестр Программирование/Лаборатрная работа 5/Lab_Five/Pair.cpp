#include "Pair.h"
#include <iostream>

using namespace std;

Pair::Pair(void)
{
	first = 0;
	second = 0;
}
Pair::~Pair(void)
{
}
Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

void Pair::Set_first(int f)
{
	first = f;
}
void Pair::Set_second(int s)
{
	second = s;
}

Pair& Pair::operator=(const Pair&p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}
std::istream& operator>>(std::istream&in, Pair&p)
{
	std::cout << "First: "; in >> p.first;
	std::cout << "\nSecond: "; in >> p.second;
	return in;
}
std::ostream& operator<<(std::ostream&out, const Pair&p)
{
	out << "First: " << p.first;
	out << "\nSecond: " << p.second;
	out << "\n";
	return out;
}


bool Pair::operator==(const Pair& p)
{
	if (first == p.first && second == p.second)
		return true;
	else return false;
}

bool Pair::operator>(const Pair&p)
{
	if ((first > p.first) || (first == p.first && second > p.second))
		return true;
	else return false;
}

bool Pair::operator<(const Pair&p)
{
	if ((first < p.first) || (first == p.first && second < p.second))
		return true;
	else return false;
}

void Pair::show()
{
	cout << "\n first = " << first;
	cout << " \n second = " << second;
	cout << endl;
}
