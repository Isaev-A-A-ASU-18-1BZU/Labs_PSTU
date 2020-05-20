#include "Fraction.h"



Fraction::Fraction(void) : Pair()
{
}

Fraction::~Fraction()
{
}
Fraction::Fraction(int c, int d) : Pair(c, d)
{
}

Fraction::Fraction(const Fraction &f) : Pair(f)
{
}

Fraction& Fraction::operator=(const Fraction& f)
{
	if (&f == this)
		return *this;
	first = f.first;
	second = f.second;
	return *this;
}

istream& operator>>(istream&in, Fraction& f)
{
	cout << "\nInteger part: "; in >> f.first;
	cout << "Fractional part: "; in >> f.second;
	return in;
}
ostream& operator<<(ostream&out, const Fraction& f)
{
	out << "Integer part: " << f.first;
	out << "\nFractional part: " << f.second;
	out << "\n";
	return out;
}
bool Fraction::operator==(const Fraction&f)
{
	if (first == f.first && second == f.second)
		return true;
	else return false;
}

bool Fraction::operator>(const Fraction&f)
{
	if ((first > f.first) || (first == f.first && second > f.second))
		return true;
	else return false;
}

bool Fraction::operator<(const Fraction&f)
{
	if ((first < f.first) || (first == f.first && second < f.second))
		return true;
	else return false;
}

void Fraction::show()
{
	cout << first << "." << second<<endl;
}
