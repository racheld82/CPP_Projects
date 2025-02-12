#include"Officer.h"
//constructors
Officer::Officer(int id, string fname, string lname, int num, int soci): Solider(id,fname,lname,num)
{
	sociometric = soci;
}

Officer::Officer(const Officer& of)
{
	id = of.id;
	firstName = of.firstName;
	lastName = of.lastName;
	numOfOperation = of.numOfOperation;
	sociometric = of.sociometric;

}
Officer::Officer(const Officer&& of)
{
	id = of.id;
	firstName = of.firstName;
	lastName = of.lastName;
	numOfOperation = of.numOfOperation;
	sociometric = of.sociometric;

}
//print characters
void Officer::print() {
	cout << soldierType() << endl;
	Solider::print();
	cout << "sociometric score: " << sociometric;
}
//return solider type
string Officer::soldierType() {
	return "officer";
}
//return if deserve medal
bool Officer::medal() {
	return numOfOperation > 2 && sociometric > 92;
}