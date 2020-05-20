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
	cout << " ФИО - ";
	cin.get();
	cin.getline(s->name, 25);
	cout << " Введите год рождения -  "; cin >> s->year;
	cout << "\n Оценки экзаменов: \n ";
	cout << "\t Оценка экзамена по русскому - :  "; cin >> s->evaluateR;
	cout << "\t Оценка экзамена по физике - :  "; cin >> s->evaluateF;
	cout << "\t Оценка экзамена по математике -  : "; cin >> s->evaluateM;
	cout << " Введите средний балл аттестата - "; cin >> s->mscore;

}

void file(app *b)
{
	ofstream fout;
	fout.open("Text.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "Файла не существует. \t";
	}
	fout << "ФИО - " << b->name<<endl;
	fout << "Год рождения - " << b->year << endl;
	fout << "Русский язык - " << b->evaluateR << endl;
	fout << "Математика - " << b->evaluateM << endl;
	fout << "Физика - " << b->evaluateF << endl;
	fout << "Средний балл аттестата - " << b->mscore << endl;

}

void Delete(app *b, int num, int j)
{
	ifstream fin;
	ofstream fout;
	fout.open("Text1.txt", ios::app);
	fin.open("Text.txt",ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "Файл не открыт..." << endl;
	}
	if ( j == num)
	{
		return;
	}
	fout << "ФИО - " << b->name << endl;
	fout << "Год рождения - " << b->year << endl;
	fout << "Русский язык - " << b->evaluateR << endl;
	fout << "Математика - " << b->evaluateM << endl;
	fout << "Физика - " << b->evaluateF << endl;
	fout << "Средний балл аттестата - " << b->mscore << endl;
}

void add(app *b, char *c)
{
	ifstream fin;
	ofstream fout;
	fin.open("Text.txt");
	fout.open("Text2.txt", ios::app);
	fout << "ФИО - " << b->name << endl;
	fout << "Год рождения - " << b->year << endl;
	fout << "Русский язык - " << b->evaluateR << endl;
	fout << "Математика - " << b->evaluateM << endl;
	fout << "Физика - " << b->evaluateF << endl;
	fout << "Средний балл аттестата - " << b->mscore << endl;
	if (strcmp(b->name,c)==0)
	{
		cout << " Добавление структуры  "<<endl;
		cout << " ФИО - ";
		cin.get();
		cin.getline(b->name, 25);
		cout << " Введите год рождения -  "; cin >> b->year;
		cout << "\n Оценки экзаменов: \n ";
		cout << "\t Оценка экзамена по русскому - :  "; cin >> b->evaluateR;
		cout << "\t Оценка экзамена по физике - :  "; cin >> b->evaluateF;
		cout << "\t Оценка экзамена по математике -  : "; cin >> b->evaluateM;
		cout << " Введите средний балл аттестата - "; cin >> b->mscore;
		fout << "ФИО - " << b->name << endl;
		fout << "Год рождения - " << b->year << endl;
		fout << "Русский язык - " << b->evaluateR << endl;
		fout << "Математика - " << b->evaluateM << endl;
		fout << "Физика - " << b->evaluateF << endl;
		fout << "Средний балл аттестата - " << b->mscore << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	fout.open("Text.txt", ios::app);
	int number = 0;
	int numdel = 0;
	cout << "Введите колличество абитуриентов - ";
	cin >> number;
	app *b = new app [number];
	for (int i = 0; i < number; i++)
	{
		fout << "-------- Абитуриент №" << i+1 << " --------" << endl;
		input(&b[i]);
		file(&b[i]);
	}
	char str[25];
	cout << "Введите фамилию после которой необходимо добавить элемент - "; cin >> str;
	for (int i = 0; i < number; i++)
	{
		add(&b[i], str);
	}
	cout << "Введите номер абитуриента, которого необходимо удалить - "; cin >> numdel;
	--numdel;
	for (int i = 0; i < number; i++)
	{
		Delete(&b[i], numdel, i);
	}
	delete b;
	system("pause");
	return 0;
}

