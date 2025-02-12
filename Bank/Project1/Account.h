#pragma once

#include<iostream>
#include<string>
using namespace std;
class Account
{
public:
	Account();
	Account(int, int, float, string);
	int getAccNum();
	int getCode();
	float getBalance();
	string getEmail();
	friend istream& operator>>(istream&, Account&);
	void withdraw(int);
	void deposit(int);
	static int sumWithdraw;
	static int sumDeposit;
	static int getSumWithdraw();
	static int getSumDeposit();
private:
	int accountNumber;
	int code;
	float balance;
	string email;


};
