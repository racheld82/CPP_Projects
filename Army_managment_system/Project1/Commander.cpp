#include"Commander.h"
//constructors
Commander::Commander(int id, string fname, string lname, int num, int* grade, bool combat) :PrivateSoldier(id, fname, lname, num, grade)
{
	isCombat = combat;
}
Commander::Commander() :PrivateSoldier()
{
	isCombat = false;
}

Commander::~Commander()
{
	if(grades)
		delete[]grades;
	grades = nullptr;
}

Commander::Commander(const Commander& s) {
	id = s.id;
	firstName = s.firstName;  lastName = s.lastName;
	numOfOperation = s.numOfOperation;
	int i = 0;
	while (i < s.numOfOperation) {
		grades[i++] = s.grades[i];
	}
	isCombat = s.isCombat;
}

Commander::Commander(const Commander&& s) {
	id = s.id;
	firstName = s.firstName;  lastName = s.lastName;
	numOfOperation = s.numOfOperation;
	delete[]grades;
	grades = s.grades;
	isCombat = s.isCombat;
}
//print character
void Commander::print() {
	cout << soldierType() << endl;
	PrivateSoldier::print();
	cout << "combat:";
	if (isCombat)
		cout << "yes";
	else
		cout << "no";
}
//return type
string Commander::soldierType() {
	return "commander";
}
//return if deserve a medal
bool Commander:: medal() {
	if (numOfOperation > 7 && isCombat) {

		int sum = 0;
		for (int i = 0; i < numOfOperation; i++) {
			sum += grades[i];
		}
		float avarage = sum / numOfOperation;
		return avarage > 90;
	}
	return false;
}