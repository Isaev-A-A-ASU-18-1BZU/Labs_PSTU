#include "Time.h"
Time::Time()
{
	minute = 0;
	second = 0;
}
Time::Time(int m, int s)
{
	minute = m;
	second = s;
}
Time::Time(const Time&p)
{
	minute = p.minute;
	second = p.second;
}
Time Time::operator =(const Time&p)
{
	if (&p == this) 
		return *this;
	minute = p.minute;
	second = p.second;
	return*this;
}
Time::~Time()
{
}
ostream& operator<<(ostream& out, const Time &p)
{
	out << p.minute << " : " << p.second << "\n";
	return out;
}
istream& operator>>(istream& in, Time&p)
{
	cout << "minute? "; 
	in >> p.minute;
	cout << "second? "; 
	in >> p.second;
	return in;
}
//дружественные функции для работы с файловыми потоками
fstream& operator>>(fstream& fin, Time&p)
{
	fin >> p.minute;
	fin >> p.second;
	return fin;
}
fstream& operator<<(fstream& fout, const Time &p)
{
	fout << p.minute << "\n" << p.second << "\n";
	return fout;
}

Time Time::operator+(const Time k)
{
	int t = minute * 60 + second;
	int tk = k.minute * 60 + k.second;
	t += tk;
	Time temp(t / 60, t % 60);
	return temp;
}

bool Time::operator == (const Time& p)
{
	return (minute == p.minute && second == p.second);
}
