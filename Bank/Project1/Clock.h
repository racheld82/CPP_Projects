#pragma once

#include<iostream>
using namespace std;
class Clock
{
public:
	Clock(int, int, int);
	Clock(const Clock&);
	Clock();
	int getHour() const;
	void setHour(int);
	int getMinute() const;
	void setMinute(int);
	int getSecond() const;
	void setSecond(int);
	Clock& operator+=(int);
	friend ostream& operator<<(ostream&,Clock&);
	friend istream& operator>>(istream&, Clock&);
private:
	int hour = 0;
	int minute = 0;
	int second = 0;
};

