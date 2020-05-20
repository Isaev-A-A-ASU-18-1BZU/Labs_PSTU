#include <iostream>;

using namespace std;

struct Comp
{
	float Re;
	float Im;
};

int sum(int a, int b)
{
	int c = a + b;
	cout<< "Cумма целых чисел = " << c;
	return c;
	 
}
int summ(int num, ...)
{
	int *p = &num;
	int i(0);
	while (num != 0)
	{
		num--;
		++p;
		i +=*p;
	}
	return i;
	}

Comp sum(Comp a, Comp b)
{
	Comp sum;
	sum.Re = a.Re + b.Re;
	sum.Im = a.Im + b.Im;
	cout << "\n Сумма комплексных чисел равна = " << sum.Re << " + i" << sum.Im << endl;
	return sum;
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j;
	cout << " ********* 7.1**********" << endl;
	cout << "Введите первое слагаемое: "; cin >> i;
	cout << "Введите вторе слагаемое: "; cin >> j;
	Comp com1;
	cout << "Введите первое комплексное число: \n";
	cout << "Действительная часть = "; cin >> com1.Re;
	cout << "Мнимая часть = "; cin >> com1.Im;
	Comp com2;
	cout << "Введите второе комплексное число: \n";
	cout << "Действительная часть = "; cin >> com2.Re;
	cout << "Мнимая часть = "; cin >> com2.Im;
	sum(i, j);
	sum(com1, com2);
	cout << "********* 7.2**********" << endl;
	cout << "\n 1+2+3 =  "<< summ(3,1,2,3);
	cout << "\n 1+2+3+4+5+6+7 =  " << summ(7, 1, 2, 3, 4,5,6,7);
	cout << "\n 1+2+3+4+5+5+5+5+5+5+6 =  " << summ(11, 1, 2, 3, 4,5,5,5,5,5,5,6)<<endl;
	system("pause");
	return 0;
}
