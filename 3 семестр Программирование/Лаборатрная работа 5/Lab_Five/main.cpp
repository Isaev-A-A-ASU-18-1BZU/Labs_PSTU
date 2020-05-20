#include <iostream>
#include "Object.h"
#include "Pair.h"
#include "Fraction.h"
#include "Vector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Vector v(5);
	Pair a;
	cin >> a;
	Fraction b;
	cin >> b;

	Object *p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << p;
	cout << endl;

	system("Pause");
	return 0;
}