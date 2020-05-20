#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//������� �������� �����
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//������� ��� ������
	if (!stream)
		return -1;//������ �������� �����
	int n;
	Time p;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//���� ��������� ������� �� ������������ ������
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}

//������� ������ ����������� �����
int print_file(const char*f_name)
{
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)
		return -1;//������ �������� �����
	Time p; 
	int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

//������� �������� �������� �� �����
int DeleteTime(const char*f_name, Time pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)
		return -1;//������ �������� �����
	int i = 0; Time p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())
			break;
		i++;
		//���� ������� �� ���������, �� ���������� ��� �� �������������� ����
		if (!(p == pp)) 
			temp << p;
	}
	//������� �����
	stream.close(); 
	temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}

//������� ��������� ��������� �����
int add130(const char*f_name, Time pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)
		return -1;//������ �������� �����
	int i = 0; 
	Time p, a;
	Time t(1, 30);
	a = pp + t;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())
			break;
		i++;
		if (pp == p) 
			temp << a;
		else 
			temp << p;
		
	}
	//������� �����
	stream.close(); 
	temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}

//������� ���������� ��������� � ����
int addKRecords(const char*f_name, int k, int n)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream) 
		return -1;//������ �������� �����
	int i = 0; 
	Time p, a;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())
			break;
		i++;
		temp << p;
		if (i == n)
		{
			for (int t = 0; t < k; t++)
			{
				cin >> a;
				temp << a;
			}
		}
	}
	//������� �����
	stream.close(); 
	temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}