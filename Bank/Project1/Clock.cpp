
#include<iostream>
#include"Clock.h"
using namespace std;

//constructor
Clock::Clock(int hour, int minute, int second)
{
	if (second < 0)
		throw("Invalid time - negative number of seconds/n");
	else if (second > 60)
		throw("Invalid time - more than 60 seconds/n");
	if (minute < 0)
		throw("Invalid time - negative number of minutes./n");
	else if (minute > 60)
		throw("Invalid time - more than 60 minutes./n");
	if (hour < 0)
		throw("Invalid time - negative number of hours./n");
	else if (hour > 24)
		throw("Invalid time - more than 24 hours./n");

	this->hour = hour;
	this->minute = minute;
	this->second = second;

}
//default constructor
Clock::Clock() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
//copy constructor
Clock::Clock(const Clock& time) {
	this->hour = time.hour;
	this->minute = time.minute;
	this->second = time.second;
}

//getters
int Clock::getHour() const {
	return this->hour;
}
int Clock::getMinute() const {
	return this->minute;
}
int Clock::getSecond() const {
	return this->second;
}
//setters
void Clock::setHour(int hour) {

	if (hour < 0)
		throw("Invalid time - negative number of hours./n");
	else if (hour > 24)
		throw("Invalid time - more than 24 hours./n");

	this->hour = hour;
}
void Clock::setMinute(int minute) {

	if (minute < 0)
		throw("Invalid time - negative number of minutes./n");
	else if (minute > 60)
		throw("Invalid time - more than 60 minutes./n");

	this->minute = minute;
}
void Clock::setSecond(int second) {

	if (second < 0)
		throw("Invalid time - negative number of seconds./n");
	else if (second > 60)
		throw("Invalid time - more than 60 seconds./n");

	this->second = second;
}
//add-equal operator
Clock& Clock::operator+=(int seconds) {
	this->second += seconds;
	while (this->second >= 60) {
		this->second = second - 60;
		this->minute += 1;
		while (this->minute >= 60) {
			this->minute = minute - 60;
			this->hour++;
		}
	}
	return *this;
}
//iostream operators
ostream& operator<<(ostream& out, Clock& time) {
	if (time.getHour() < 10)
		out << "0" << time.getHour() << ":";
	else
		out << time.getHour() << ":";
	if (time.getMinute() < 10)
		out << "0" << time.getMinute() << ":";
	else
		out << time.getMinute() << ":";
	if (time.getSecond() < 10)
		out << "0" << time.getSecond() << endl;
	else
		out << time.getSecond() << endl;
	return out;
}

istream& operator>>(istream& is, Clock& clk) {
	is >> clk.second;
	if (clk.second < 0)
		throw("Invalid time - negative number of seconds./n");
	else if (clk.second > 60)
		throw("Invalid time - more than 60 seconds./n");
	is >> clk.minute;
	if (clk.minute < 0)
		throw("Invalid time - negative number of minutes./n");
	else if (clk.minute > 60)
		throw("Invalid time - more than 60 minutes./n");
	is >> clk.hour;
	if (clk.hour < 0)
		throw("Invalid time - negative number of hours./n");
	else if (clk.hour > 24)
		throw("Invalid time - more than 24 hours./n");
	return is;
}