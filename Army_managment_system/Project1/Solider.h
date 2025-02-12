#pragma once
#include<iostream>
using namespace std;
class Solider
{
public:
	Solider(int,string,string,int);
	Solider();
	virtual ~Solider() { id = 0; };
	virtual bool medal() = 0;
	virtual void print();
	virtual string soldierType() = 0;
	int getId() { return id; };
	int getNum() { return numOfOperation; };
	string getfname() { return firstName; };
	string getlname() { return lastName; };

protected:
	int id;
	string firstName;
	string lastName;
	int numOfOperation;

};


