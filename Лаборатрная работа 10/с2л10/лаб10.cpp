#include<iostream>

using namespace::std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	int delnum,addnum;
	cout << "������� ������ ������� - ";
	cin >> size;
	int *mas = new int[size];
	int *masdel = new int[size-1];
	int *masadd = new int[size+1];
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 10;
		cout << i << " - ������� =  " << mas[i] << endl;
	}
	cout <<endl << "������� ����� �������� ������� ���������� ������� - ";
	cin >> delnum;
	if(size<delnum)
	{
		cout << "����� �� ����� ���� ������ ������� �������";
		return -1;
	}
	
	for (int i = 0; i < delnum ; i++)
	{
		masdel[i] = mas[i];
		cout << i  << " - ������� =  " << masdel[i] << endl;
	}
	
	for (int i = delnum; i <= size-1; i++)
	{
		masdel[i-1] = mas[i];
	}
	for (int i = delnum; i < size - 1; i++)
	{
		cout << i +1 << " - ������� =  " << masdel[i] << endl;
	}
	
	cout << endl << "������� ����� �������� ������� ���������� �������� - ";
	cin >> addnum;

	for (int i = 0; i < addnum; i++)
	{
		masadd[i] = mas[i];
		cout << i << " - ������� =  " << masadd[i] << endl;
	}
	masadd[addnum] = rand() % 100;
	for (int i = addnum; i < size + 1; i++)
	{
		masadd[i + 1] = mas[i];
	}
	for (int i = delnum; i < size + 1; i++)
	{
		cout << i  << " - ������� =  " << masadd[i] << endl;
	}

	system("pause");
	return 0;
}