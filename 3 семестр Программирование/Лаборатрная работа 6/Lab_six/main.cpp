#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{  
	setlocale(LC_ALL, "Russian");
	Vector a(5),b(10),c(10);
	cout << a << endl;
	cin >> a;
	cout <<"Вектор а - " << a << endl;
	a[2] = 228;
	cout << a << endl;
	cout << "Vector b - " << b << endl;
	cout << "Vector b=a - " << (b=a) << endl;
	b + 100;
	c = b;
	cout << "Vector c=b+100 - " <<c << endl;
	cout << "Lenth A = " << a() << endl;
	cout << *(a.first()) << endl;
	Iterator I = a.first();
	++I;
	cout << *I << endl;
	for (I = a.first(); I != a.last(); ++I)
	{
		cout << *I << endl;
	}
	system("pause");
	return 0;
}