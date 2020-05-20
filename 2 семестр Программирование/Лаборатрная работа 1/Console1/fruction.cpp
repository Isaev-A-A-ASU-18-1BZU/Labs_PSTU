#include <iostream>
#include "fruction.h"
using namespace std;

void fruction ::Init(int F, int S)
{
	first = F;
	second = S;
}
void fruction::Read()
{
	cout << "\n Firt "; cin >> first;
	cout << "\n Second "; cin >> second;
}
void fruction::Show()
{
	cout << "\n first =  " << first;
	cout << "\n Second =  " << second<<endl;

}
double fruction::Ipart()
{
	if (second == 0)
	{
		cout << "Fatal error..."<<endl;
		return 0;
	}
		return (first/second);
}
