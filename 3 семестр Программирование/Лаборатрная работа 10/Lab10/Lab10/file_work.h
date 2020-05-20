#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//функция создания файла
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream)
		return -1;//ошибка открытия файла
	int n;
	Time p;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока
		stream << p << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}

//функция печати содержимого файла
int print_file(const char*f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)
		return -1;//ошибка открытия файла
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

//функция удаления элемента из файла
int DeleteTime(const char*f_name, Time pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)
		return -1;//ошибка открытия файла
	int i = 0; Time p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())
			break;
		i++;
		//если объекты не совпадают, то записываем его во вспомогательый файл
		if (!(p == pp)) 
			temp << p;
	}
	//закрыть файлы
	stream.close(); 
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}

//функция изменения элементов файла
int add130(const char*f_name, Time pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)
		return -1;//ошибка открытия файла
	int i = 0; 
	Time p, a;
	Time t(1, 30);
	a = pp + t;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())
			break;
		i++;
		if (pp == p) 
			temp << a;
		else 
			temp << p;
		
	}
	//закрыть файлы
	stream.close(); 
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}

//функция добавления элементов в файл
int addKRecords(const char*f_name, int k, int n)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream) 
		return -1;//ошибка открытия файла
	int i = 0; 
	Time p, a;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
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
	//закрыть файлы
	stream.close(); 
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}