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
	cin >> file_name;//задаем имя файла
	do
	{ //Меню
		cout << "\n1. Make file";//создание файла
		cout << "\n2. Print file";//печать файла
		//пункты по заданию в варианте
		cout << "\n3. Delete (ravnoe zadannomy znacheniu)";
		cout << "\n4. Add 1:30 to record in file";
		cout << "\n5. Add K records after element in file";
		cout << "\n0. Exit\n";
		cout << "> ";
		cin >> c;
		switch (c)
		{
		case 1: 
			k = make_file(file_name);//вызов функции для записи в файл
			if (k < 0)
				cout << "Can't make file";//вывод сообщения об ошибке
			break;
		case 2: 
			k = print_file(file_name);//вызов функции для печати файла
			if (k == 0)
				cout << "Empty file\n";//если файл пустой
			if (k < 0)
				cout << "Can't read file\n";//если файл нельзя открыть
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