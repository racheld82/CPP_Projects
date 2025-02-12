#include "Solider.h"
//constructors
Solider::Solider(int id, string fname, string lname, int num)
{
	this->id = id;
	this->firstName = fname;
	this->lastName = lname;
	this->numOfOperation = num;
}
Solider::Solider()
{
	this->id = 0;
	this->firstName = "";
	this->lastName = "";
	this->numOfOperation = 0;
}
//print characters
void Solider::print() {
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operation: " << numOfOperation << endl;
}
