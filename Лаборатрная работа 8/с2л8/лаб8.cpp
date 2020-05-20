#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>

using namespace std;

struct app
{
	char name[25];
	int year;
	int evaluateM;
	int evaluateF;
	int evaluateR;
	float mscore;
};

void input(app *s)
{
	ofstream fout;
	fout.open("Text.txt", ios::app);
	cout << " ��� - ";
	cin.get();
	cin.getline(s->name, 25);
	cout << " ������� ��� �������� -  "; cin >> s->year;
	cout << "\n ������ ���������: \n ";
	cout << "\t ������ �������� �� �������� - :  "; cin >> s->evaluateR;
	cout << "\t ������ �������� �� ������ - :  "; cin >> s->evaluateF;
	cout << "\t ������ �������� �� ���������� -  : "; cin >> s->evaluateM;
	cout << " ������� ������� ���� ��������� - "; cin >> s->mscore;

}

void file(app *b)
{
	ofstream fout;
	fout.open("Text.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "����� �� ����������. \t";
	}
	fout << "��� - " << b->name<<endl;
	fout << "��� �������� - " << b->year << endl;
	fout << "������� ���� - " << b->evaluateR << endl;
	fout << "���������� - " << b->evaluateM << endl;
	fout << "������ - " << b->evaluateF << endl;
	fout << "������� ���� ��������� - " << b->mscore << endl;

}

void Delete(app *b, int num, int j)
{
	ifstream fin;
	ofstream fout;
	fout.open("Text1.txt", ios::app);
	fin.open("Text.txt",ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "���� �� ������..." << endl;
	}
	if ( j == num)
	{
		return;
	}
	fout << "��� - " << b->name << endl;
	fout << "��� �������� - " << b->year << endl;
	fout << "������� ���� - " << b->evaluateR << endl;
	fout << "���������� - " << b->evaluateM << endl;
	fout << "������ - " << b->evaluateF << endl;
	fout << "������� ���� ��������� - " << b->mscore << endl;
}

void add(app *b, char *c)
{
	ifstream fin;
	ofstream fout;
	fin.open("Text.txt");
	fout.open("Text2.txt", ios::app);
	fout << "��� - " << b->name << endl;
	fout << "��� �������� - " << b->year << endl;
	fout << "������� ���� - " << b->evaluateR << endl;
	fout << "���������� - " << b->evaluateM << endl;
	fout << "������ - " << b->evaluateF << endl;
	fout << "������� ���� ��������� - " << b->mscore << endl;
	if (strcmp(b->name,c)==0)
	{
		cout << " ���������� ���������  "<<endl;
		cout << " ��� - ";
		cin.get();
		cin.getline(b->name, 25);
		cout << " ������� ��� �������� -  "; cin >> b->year;
		cout << "\n ������ ���������: \n ";
		cout << "\t ������ �������� �� �������� - :  "; cin >> b->evaluateR;
		cout << "\t ������ �������� �� ������ - :  "; cin >> b->evaluateF;
		cout << "\t ������ �������� �� ���������� -  : "; cin >> b->evaluateM;
		cout << " ������� ������� ���� ��������� - "; cin >> b->mscore;
		fout << "��� - " << b->name << endl;
		fout << "��� �������� - " << b->year << endl;
		fout << "������� ���� - " << b->evaluateR << endl;
		fout << "���������� - " << b->evaluateM << endl;
		fout << "������ - " << b->evaluateF << endl;
		fout << "������� ���� ��������� - " << b->mscore << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	fout.open("Text.txt", ios::app);
	int number = 0;
	int numdel = 0;
	cout << "������� ����������� ������������ - ";
	cin >> number;
	app *b = new app [number];
	for (int i = 0; i < number; i++)
	{
		fout << "-------- ���������� �" << i+1 << " --------" << endl;
		input(&b[i]);
		file(&b[i]);
	}
	char str[25];
	cout << "������� ������� ����� ������� ���������� �������� ������� - "; cin >> str;
	for (int i = 0; i < number; i++)
	{
		add(&b[i], str);
	}
	cout << "������� ����� �����������, �������� ���������� ������� - "; cin >> numdel;
	--numdel;
	for (int i = 0; i < number; i++)
	{
		Delete(&b[i], numdel, i);
	}
	delete b;
	system("pause");
	return 0;
}

