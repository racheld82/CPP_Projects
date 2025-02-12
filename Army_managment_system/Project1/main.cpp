#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include"Solider.h"
#include"PrivateSoldier.h"
#include"Commander.h"
#include"Officer.h"
using namespace std;

//racheli dissen 325849982
//ex 10
//c++
enum option {
	EXIT,
	ADD_NEW_SOLDIER,
	MEDAL_DESERVES,
	SOCIOMETRIC_HIGHEST,
	PRIVATE_MEDAL_COUNT,
	NONCOMBAT_COMMANDER,
	SUPER_SOLDIER,
	OFFICER_REMOVE
};
void add(vector<Solider*> & soliders) {
	std::cout << "choose a soldier\n";
	std::cout << "enter 1 to add a private\n";
	std::cout << "enter 2 to add a commander\n";
	std::cout << "enter 3 to add an officer\n";
	int option,id,num;
	string fname, lname;
	std::cin >> option;
	std::cout << "enter id, first name, last name and number of operations\n";
	std::cin >> id >> fname >> lname >> num;
	int* grades = new int[num];
	
	Commander* c;
	Solider* s;
	Officer* o;
	switch (option)
	{
	case 1:
		if (num) {
			std::cout << "enter " << num << " grades\n";
			for (int i = 0; i < num; i++) {
				std::cin >> grades[i];
			}
		}
		s = new PrivateSoldier(id, fname, lname, num, grades);
		soliders.push_back(s);
		break;
	case 2:
		if (num) {
			std::cout << "enter " << num << " grades\n";
			for (int i = 0; i < num; i++) {
				std::cin >> grades[i];
			}
		}
		std::cout << "enter 1 if the soldier is combat and 0 if not\n";
		bool combat;
		std::cin >> combat;
		c = new Commander(id, fname, lname, num, grades, combat);
		soliders.push_back(c);
		break;
	case 3:
		std::cout << "enter the sociometric score\n";
		int soci;
		std::cin >> soci;
		o = new Officer(id, fname, lname, num,soci);
		soliders.push_back(o);
	default:
		break;
	}
}
void printMedalList(vector<Solider*> soliders) {
	for (int i = 0; i < soliders.size(); i++) {
		if (soliders[i]->medal()) {
			soliders[i]->print();
			cout << endl;
		}
	}
}
Solider*& highesttSociometricScore(vector<Solider*> soliders) {
	int i = 0;
	int max = 0;
	Solider* maxS=nullptr;
	for (; i < soliders.size(); i++) {
		if (soliders[i]->soldierType() == "officer") {
			if (((Officer*)soliders[i])->getSocioMetric() > max) {
				max = ((Officer*)soliders[i])->getSocioMetric();
				maxS = soliders[i];
			}
		}
	}
	return maxS;
}
int main()
{
	Solider* s;
	vector<Solider*> soliders;
	int op;
	int sum;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:
			add(soliders);
			break;
		case MEDAL_DESERVES:
			printMedalList(soliders);
			break;
		case SOCIOMETRIC_HIGHEST:
			s = highesttSociometricScore(soliders);
			if (s) {
				cout << "Officer with the highest sociometric score: ";
				cout << s->getfname() << ' ' << s->getlname() << endl;
			}
			break;
		case PRIVATE_MEDAL_COUNT: cout << "number of privates that received medals :";
			sum = 0;
			[soliders,&sum]() {
				for (int i = 0; i < soliders.size(); i++) {
					if (soliders[i]->soldierType() == "private" && soliders[i]->medal()) {
						sum++;
					}
				}
			}();
			cout <<sum<< endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";
			[soliders]() {
				for (int i = 0; i < soliders.size(); i++) {
					if (soliders[i]->soldierType() == "commander" && !((Commander*)soliders[i])->getCombat()) {
						cout<<soliders[i]->getfname();
						cout << " " << soliders[i]->getlname();
					}
				}
			} ();
			cout << endl;
			break;		
		case SUPER_SOLDIER:
			bool super;
			[soliders, &super]() {
				for (int i = 0; i < soliders.size(); i++) {
					if (soliders[i]->getNum() > 15) {
						super = true;
						return;
					}
				}
				super = false;
			}();
			if(super)
				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
				break;
		case OFFICER_REMOVE:
			[&soliders]() {
				vector<Solider*>::iterator start;
				start = soliders.begin();
				for (int i = 0; i < soliders.size(); i++,start++) {
					if (soliders[i]->soldierType() == "officer" && soliders[i]->getNum()==0) {
						soliders.erase(start);
					}
				}
			}();
			for (int i = 0; i < soliders.size(); i++) {
				soliders[i]->print();
				cout << endl;
			}
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}

//exmple:
//enter 0 - 7
//1
//choose a soldier
//enter 1 to add a private
//enter 2 to add a commander
//enter 3 to add an officer
//1
//enter id, first name, last nameand number of operations
//1
//a
//a
//3
//enter 3 grades
//12
//2
//2
//enter 0 - 7
//2
//enter 0 - 7
//1
//choose a soldier
//enter 1 to add a private
//enter 2 to add a commander
//enter 3 to add an officer
//2
//enter id, first name, last nameand number of operations
//2
//s
//s
//7
//enter 7 grades
//100
//100
//100
//100
//100
//100
//100
//enter 1 if the soldier is combat and 0 if not
//1
//enter 0 - 7
//1
//choose a soldier
//enter 1 to add a private
//enter 2 to add a commander
//enter 3 to add an officer
//2
//enter id, first name, last nameand number of operations
//4
//d
//d
//3
//enter 3 grades
//10
//10
//10
//enter 1 if the soldier is combat and 0 if not
//0
//enter 0 - 7
//1
//choose a soldier
//enter 1 to add a private
//enter 2 to add a commander
//enter 3 to add an officer
//3
//enter id, first name, last nameand number of operations
//6
//g
//g
//8
//enter the sociometric score
//100
//enter 0 - 7
//2
//ID: 6
//first name : g
//last name : g
//num operation : 8
//sociometric score : 100enter 0 - 7
//3
//Officer with the highest sociometric score : g g
//enter 0 - 7
//4
//number of privates that received medals : 0
//enter 0 - 7
//1
//choose a soldier
//enter 1 to add a private
//enter 2 to add a commander
//enter 3 to add an officer
//1
//enter id, first name, last nameand number of operations
//3
//c
//c
//11
//enter 11 grades
//100
//100
//100
//100
//100
//100
//100
//100
//100
//100
//100
//enter 0 - 7
//4
//number of privates that received medals : 1
//enter 0 - 7
//5
//list of noncombat commanders : d d
//enter 0 - 7
//6
//no soldier did more than 15 operations
//enter 0 - 7
//7
//ID : 1
//first name : a
//last name : a
//num operation : 3
//grades : 12  2  2  ID : 2
//first name : s
//last name : s
//num operation : 7
//grades : 100  100  100  100  100  100  100  combat : yesID : 4
//first name : d
//last name : d
//num operation : 3
//grades : 10  10  10  combat : noID : 6
//first name : g
//last name : g
//num operation : 8
//sociometric score : 100ID : 3
//first name : c
//last name : c
//num operation : 11
//grades : 100  100  100  100  100  100  100  100  100  100  100  enter 0 - 7
//1
//choose a soldier
//enter 1 to add a private
//enter 2 to add a commander
//enter 3 to add an officer
//3
//enter id, first name, last nameand number of operations
//1
//e
//e
//23
//enter the sociometric score
//24
//enter 0 - 7
//6
//there is at least one soldier that did more than 15 operations
//enter 0 - 7
//7
//ID: 1
//first name : a
//last name : a
//num operation : 3
//grades : 12  2  2  ID : 2
//first name : s
//last name : s
//num operation : 7
//grades : 100  100  100  100  100  100  100  combat : yesID : 4
//first name : d
//last name : d
//num operation : 3
//grades : 10  10  10  combat : noID : 6
//first name : g
//last name : g
//num operation : 8
//sociometric score : 100ID : 3
//first name : c
//last name : c
//num operation : 11
//grades : 100  100  100  100  100  100  100  100  100  100  100  ID : 1
//first name : e
//last name : e
//num operation : 23
//sociometric score : 24enter 0 - 7
//0
