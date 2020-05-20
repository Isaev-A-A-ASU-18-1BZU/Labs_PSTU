#pragma once
#include "Pair.h"
#include <iostream>

using namespace std;
class Fraction :
	public Pair
{
public:
	Fraction(void);
public:
	void show();
	~Fraction();
	Fraction(int, int);
	Fraction(const Fraction&);
	Fraction& operator=(const Fraction&);
	friend istream& operator>>(istream&in, Fraction &f);
	friend ostream& operator<<(ostream&out, const Fraction &f);
	bool operator==(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<(const Fraction&);
};

