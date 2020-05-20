#include<fstream>
#include<iostream>
#include<cstring>

using namespace::std;

int sizefile ( char *a)
{
	int b = 0;
	fstream fin(a);
	fin.seekg(0, ios::end);
	b = fin.tellg();
	fin.close();
	return b;
 }
int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	fout.open("out.txt",ios::app);
	ifstream fin;
	fin.open("in.txt",ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "Файл не открыт..." << endl;
	}
	const char ch = '\n';
	char str[30][12];
	for (int i(0); i < 12; i++)
	{
		fin.getline(str[i], 29, ch);
		if (i % 2 == 0)
		{
			fout << str[i] << endl;
		}
	
	}
	
	int fsize1 = sizefile("in.txt");
	int fsize2 = sizefile("out.txt");
	cout << " Размер файла F1 - " << fsize1 << " байт" << endl;
	cout << " Размер файла F2 - " << fsize2 << " байт" << endl;
	
	system("pause");
	return 0;
}
