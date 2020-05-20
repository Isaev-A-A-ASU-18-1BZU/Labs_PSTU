#pragma once
#include<iostream>

using namespace std;
class time
{
	int min;
	int sec;
public:
	time() { min = 0; sec = 0; };
	time(int m, int s) { min = m; sec = s; }
	time(const time &t) { min = t.min; sec = t.sec; }
	~time() {};
	int get_min(){ return min; }
	int get_sec() { return sec; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }
	time &operator=(const time&);
	bool operator== (const time&);
	time operator+ (const time&);
	friend istream& operator >> (istream&in, time&t);
	friend ostream& operator << (ostream&out, const time&t);


};

