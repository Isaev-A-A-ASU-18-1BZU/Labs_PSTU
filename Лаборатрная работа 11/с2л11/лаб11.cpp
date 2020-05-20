#include<iostream>
#include<fstream>

using namespace::std;

struct a 
{
	int key;
};

struct list
{
	a A;
	list* next;
};

void print(list *a)
{
	list *Print = a;
		while (Print)
	{
		cout << Print->A.key << " --> ";
		Print = Print->next;
	}
	cout << " END LIST" << endl;
}

void make(list **b, int n)
{
	*b = new list;
	(*b)->A.key = 0;
	(*b)->next = NULL;
	list *end = *b;
	for (int i =n;i > 0; i--)
	{
		end->next = new list;
		end = end->next;
		end->A.key = rand()%100;
		end->next = NULL;
	}
}
void add(list **b, a &i,int &c)
{
	int m = 1;
	if (*b == NULL)
	{
		return;
	}
	list *t = new list;
	t->A = i;
	list *p = *b;
	list *p1 = p->next;
	while (p1)
	{
		if (m == c)
		{
			p->next = t;
			t->next = p1;
		}
		p = p1;
		p1 = p1->next;
		m++;
	}
}

void Delete(list **b, const int i)
{
	int m = 1;
	if (*b == NULL)
	{
		return;
	}
	list *t = *b;
	list *t1 = t->next;
	while (t1)
	{
		if (m == i)
		{
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
		m++;
	}
}

void file(list *b)
{
	ofstream fout;
	fout.open("list.txt", ios::app);
	list *f = b;
	while (f)
	{
		fout << f->A.key<< " ";
		f = f->next;
	}
	cout << " Список выведен в файл list.txt..." << endl;
}

void Free (list **b)
{
	if (*b==NULL)
	{
		return;
	}
	list *p = *b;
	list *t;

	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*b = NULL;
}


void rec(list **b)
{
	int v;
	ifstream fin;
	fin.open("list.txt");
	*b = new list;
	fin >> v;
	(*b)->A.key = v;
	(*b)->next = NULL;

	list *end = *b;

	while (!fin.eof())
	{
		end->next = new list;
		end = end->next;
		fin >> v;
		end->A.key = v;
		end->next = NULL;
	}
	cout << " Восстановленый список ";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	list *begin = NULL;
	int N = 7;
	make(&begin, N);
	print(begin);	
	a i;
	int numlist(0);
	i.key= rand()%1000;
	cout << "Введите номер после которого необходимо добавить элемент = "; cin >> numlist;
	add(&begin, i, numlist);
	print(begin);
	int j;
	cout << "Введите номер числа после которое необходимо удалить = "; cin >> j;
	Delete(&begin, j);
	print(begin);
	file(begin);
	Free(&begin);
	rec(&begin);
	print(begin);
	system("pause");
	return 0;
}
