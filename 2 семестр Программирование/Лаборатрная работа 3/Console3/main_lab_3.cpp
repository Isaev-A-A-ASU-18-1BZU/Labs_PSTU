#include "time.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	time a;
	cout << "time a\n";	cin >> a;
	time b(15, 10);
	cout << "time b: " << b << endl; 
	time c = a;
	c = c + b;
	cout << "time c=c+b: " << c << endl; 
	if (a == b)			
		cout << "����� a ����� b\n";
	else cout << "����� a �� ����� b\n";
	system("pause");

}