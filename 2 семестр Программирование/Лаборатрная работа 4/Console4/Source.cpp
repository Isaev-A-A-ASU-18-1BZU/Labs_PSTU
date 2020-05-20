#include <iostream>
#include "Pair.h"
using namespace std;

class Fraction :


	public Pair
{
public:
	Fraction(void);
public:
	~Fraction();
	Fraction(int, int);
	Fraction(const Fraction&);
	Fraction& operator=(const Fraction&);
	friend istream& operator >> (istream&in, Fraction &f);
	friend ostream& operator<<(ostream&out, const Fraction &f);
	bool operator==(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<(const Fraction&);
};


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

istream& operator >> (istream&in, Fraction& f)
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


void f1(Pair&c)
{
	c.Set_first(11);
	cout << c;
}

Pair f2()
{
	Fraction l(17, 11);
	return l;
}


void main()
{
	setlocale(LC_ALL, "russian");
	//работа с классом Pair
	Pair a;
	cin >> a;
	cout << "--a--\n";
	cout << a;
	Pair b(4, 5);
	cout << "--b--\n";
	cout << b;
	cout << "Сравнение: \n";
	if (a == b)
		cout << "a == b\n";
	if (a < b)
		cout << "a < b\n";
	if (a > b)
		cout << "a > b\n";
	a = b;
	cout << "--a после присваивания b--\n";
	cout << a;
	Fraction c;
	cin >> c;
	cout << "--c--\n";
	cout << c;
	Fraction d(7, 9);
	cout << "--d--\n";
	cout << d;
	cout << "Сравнение: \n";
	if (c == d)
		cout << "c == d\n";
	if (c < d)
		cout << "c < d\n";
	if (c > d)
		cout << "c > d\n";
	cout << "Принцип подстановки:\n";
	f1(c);
	a = f2();
	cout << a;
	system("pause");
}
