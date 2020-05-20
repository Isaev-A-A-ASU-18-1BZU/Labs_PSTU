#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"
using namespace std;

void main()
{
	Time p;
	int k, c, k1;
	char file_name[30];
	int nom;
	cout << "Enter file name: ";
	cin >> file_name;//������ ��� �����
	do
	{ //����
		cout << "\n1. Make file";//�������� �����
		cout << "\n2. Print file";//������ �����
		//������ �� ������� � ��������
		cout << "\n3. Delete (ravnoe zadannomy znacheniu)";
		cout << "\n4. Add 1:30 to record in file";
		cout << "\n5. Add K records after element in file";
		cout << "\n0. Exit\n";
		cout << "> ";
		cin >> c;
		switch (c)
		{
		case 1: 
			k = make_file(file_name);//����� ������� ��� ������ � ����
			if (k < 0)
				cout << "Can't make file";//����� ��������� �� ������
			break;
		case 2: 
			k = print_file(file_name);//����� ������� ��� ������ �����
			if (k == 0)
				cout << "Empty file\n";//���� ���� ������
			if (k < 0)
				cout << "Can't read file\n";//���� ���� ������ �������
			break;
		case 3:
			cout << "Delete Time: ";
			cin >> p;
			k = DeleteTime(file_name, p);
			if (k < 0) 
				cout << "\nCan't read file";
			if (k == 0) 
				cout << "\nNot such record";
			break;
		case 4:
			cout << "Time? ";
			cin >> p;
			k = add130(file_name, p);
			if (k < 0) 
				cout << "\nCan't read file";
			if (k == 0) 
				cout << "\nNot such record";
			break;
		case 5:
			cout << "K? ";
			cin >> k1;
			cout << "Number of element? ";
			cin >> nom;
			k = addKRecords(file_name, k1, nom);
			if (k < 0) 
				cout << "\nCan't read file";
			if (k == 0) 
				cout << "\nNot such record";
			break;
		}
	} while (c != 0);
	system("pause");
}