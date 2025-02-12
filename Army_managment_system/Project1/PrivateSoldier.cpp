#include"PrivateSoldier.h"
//constructor
PrivateSoldier::PrivateSoldier(int id,string fname, string lname, int num, int* grade) :Solider(id, fname, lname, num) {
	grades = grade;
}

PrivateSoldier::PrivateSoldier() :Solider() {
	grades = nullptr;
}

PrivateSoldier::PrivateSoldier(const PrivateSoldier& s) {
	id = s.id;
	firstName = s.firstName;  lastName = s.lastName;
	numOfOperation = s.numOfOperation;
	int i = 0;
	while (i<s.numOfOperation) {
		grades[i++] = s.grades[i];
	}
}

PrivateSoldier::PrivateSoldier(const PrivateSoldier&& s) {
	id = s.id;
	firstName = s.firstName;  lastName = s.lastName;
	numOfOperation = s.numOfOperation;
	delete[]grades;
	grades = s.grades;
}
//print characters
void PrivateSoldier::print() {
	cout << soldierType() << endl;
	Solider::print();
	if (numOfOperation > 0) {
		cout << "grades: ";
		for (int i = 0; i < numOfOperation; i++) {
			cout << grades[i] << " ";
		}
	}
 }

//destructor
PrivateSoldier::~PrivateSoldier() {
	if (grades)
		delete[]grades;
	grades = nullptr;
 }
//return solider type
string PrivateSoldier::soldierType() {
	return "private";
}
//return if deserve a medal
bool PrivateSoldier::medal() {
	if (numOfOperation < 10) {
		return false;
	}
	
	int sum = 0;
	for (int i = 0; i < numOfOperation; i++) {
		sum+= grades[i];
	}
	float avarage = sum / numOfOperation;
	return avarage > 95;
}
