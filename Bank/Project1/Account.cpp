
#include<string>
#include<iostream>
#include"Account.h"
using namespace std;

int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;

//default constructor
Account::Account()
{
	this->accountNumber = 0;
	this->balance = 0;
	this->code = 0;
	this->email = "";
}
//parametrize constructor
Account::Account(int numOfAccount, int code, float balance, string email)
{
	string s1 = ".com", s2 = ".co.il";
	if (code < 1000 || code>9999)
		throw "ERROR: code must be of 4 digits!";
	if (code / 1000 == 0)
		throw "ERROR: wrong code!";
	if (email.find("@") == string::npos)
		throw "ERROR: email must contain @!";
	if ((email.find("@") == 0) || (email.find(" ") != string::npos))
		throw "ERROR: wrong email!";
	if ((email.compare(email.length() - s1.length(), s1.length(), s1) != 0) && (email.compare(email.length() - s2.length(), s2.length(), s2) != 0))
		throw "ERROR: email must end at .com or .co.il!";
	this->accountNumber = numOfAccount;
	this->balance = balance;
	this->code = code;
	this->email = email;
}
//getters
int Account::getAccNum() {
	return this->accountNumber;
}

int Account::getCode() {
	return this->code;
}

float Account::getBalance() {
	return this->balance;
}

string Account::getEmail() {
	return this->email;
}
//istream operator
istream& operator>>(istream& in, Account& acc) {
	string s1 = ".com", s2 = ".co.il";
	int accNumber, code;
	string email;
	in >> accNumber >> code >> email;

	if (code < 1000 || code>9999)
		throw "ERROR: code must be of 4 digits!";
	if (code / 1000 == 0)
		throw "ERROR: wrong code!";
	if (email.find("@") == string::npos)
		throw "ERROR: email must contain @!";
	if ((email.find("@") == 0) || (email.find(" ") != string::npos))
		throw "ERROR: wrong email!";
	if ((email.compare(email.length() - s1.length(), s1.length(), s1) != 0) && (email.compare(email.length() - s2.length(), s2.length(), s2) != 0))
		throw "ERROR: email must end at .com or .co.il!";
	acc.accountNumber = accNumber;
	acc.code = code;
	acc.email = email;
	acc.balance = 0;
	return in;
}
//function for operating withdraw
void Account::withdraw(int nis) {

	if (this->balance <= -6000)
		throw("ERROR: cannot have less than - 6000 NIS!\n");
	if (nis > 2500)
		throw("ERROR: cannot withdraw more than 2500 NIS!\n");


	this->balance -= nis;
	sumWithdraw += nis;
}
//function for operating deposit
void Account::deposit(int check) {
	if (check > 10000)
		throw("ERROR: cannot deposit more than 10000 NIS!\n");
	this->balance += check;
	sumDeposit += check;
}
//get static variables
int Account::getSumDeposit() {
	return sumDeposit;
}

int Account::getSumWithdraw() {
	return sumWithdraw;
}
