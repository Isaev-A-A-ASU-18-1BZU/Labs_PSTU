#include<iostream>
#include "fruction.h"
using namespace std;

fruction make_fruction(int F, int S)
{
	fruction t;
	t.Init(F, S);
	return t;
}

void main()
{
	setlocale(LC_ALL,"Russian");
	fruction A;
	fruction B;
	cout << "¬вод дроби а: ";
	A.Read();
	cout << "¬вод дроби b: ";
	B.Read();
	A.Show();
	B.Show();
	cout << "A.Ipart (" << A.first << "/" << A.second << ") = "<< A.Ipart()<<endl;
	cout << "B.Ipart (" << B.first << "/" << B.second << ") = "<< B.Ipart()<<endl;
	fruction *X = new fruction;
	X->Init(2, 5);
	X->Show();
	X->Ipart();
	cout << "X.Ipart (" << X->first << "," << X->second << ")=" <<X->Ipart()<<endl;
	fruction mas[3];
	for (int i = 0; i < 3; i++)
	{
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Ipart();
		cout << "mas[" << i << "].Ipart(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Ipart() << endl;
	}
	int y;
	int z;
	cout << "first?"; cin >> y;
	cout << "second?"; cin >> z;
	fruction F = make_fruction(y, z);
	F.Show();
}