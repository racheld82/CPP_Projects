#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;
//racheli dissen 325849982
//ex 4 
//c++

enum ACTION {
	STOP,
	BALANCE,
	DEPOSIT,
	WITHDRAW,
	SUM_DEPOSIT,
	SUM_WITHDRAW
};
ACTION menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all deposits" << endl;
	cout << "enter 5 to see the sum of all withdrawals" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (ACTION)x;
}
int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccNum() != number)
		i++;
	if (i >= size)
		throw "ERROR: no such account number\n";
	cout << "please enter the code:\n";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
	cout << c << "\t";
	switch (ac) {
	case BALANCE: cout << "account #: " << a.getAccNum() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT:
	case WITHDRAW: cout << "account #: " << a.getAccNum() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUM_DEPOSIT:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case SUM_WITHDRAW:
		cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], BALANCE, c);
}
void cashDeposit(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the deposit:\n ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
	for (int j = 0; j < i; j++)
		if (bank[i].getAccNum() == bank[j].getAccNum())
			throw "ERROR: account number must be unique!\n";
}
int main() {
	const int SIZE = 10;
	Clock c(8, 0, 0);
	Account bank[SIZE];
	cout << "enter account number, code and email for " << SIZE << " accounts:\n";
	for (int i = 0; i < SIZE; i++) {
		try {
			cin >> bank[i];
			checkAccount(bank, i);
		}
		catch (const char* msg) {
			cout << c << '\t' << msg;
			i--;
		}
	}
	ACTION ac = menu();
	while (ac) {
		switch (ac) {
		case BALANCE:
			try {
				getBalance(bank, SIZE, c);
			}
			catch (const char* msg) {
				cout << c << " " << msg;
			}
			break;
		case WITHDRAW:
			try {
				cashWithdraw(bank, SIZE, c);
			}
			catch (const char* msg) {
				cout << c << " " << msg;
			}
			break;
		case DEPOSIT:
			try {
				cashDeposit(bank, SIZE, c);
			}
			catch (const char* msg) {
				cout << c << " " << msg;
			}
			break;
		case SUM_DEPOSIT:
			c += 60;
			printTransaction(bank[0], SUM_DEPOSIT, c);
			break;
		case SUM_WITHDRAW:
			c += 60;
			printTransaction(bank[0], SUM_WITHDRAW, c);
		}

		ac = menu();
	}

	return 0;
}

//example:
//enter account number, codeand email for 10 accounts:
//12345
//1234
//r@k.cpm
//08:00 : 00
//ERROR : email must end at.com or .co.il!
//12345
//1234
//r@g.com
//90807
//1456
//t@f.com
//34567
//1567
//r@yy.co.il
//145678
//123
//e@g.co.il
//08:00 : 00
//ERROR : code must be of 4 digits!
//19078
//2348
//y@y.com
//90456
//4567
//r@r.co.il
//171717
//1717
//e@gmail.com
//13523
//2323
//e@e.com
//18907
//7897
//r@dd.com
//4563
//3344
//w@2.com
//45789
//1010
//e@we.com
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//1
//please enter account number :
//45789
//please enter the code :
//1010
//08 : 00 : 20
//account # : 45789        balance : 0
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//2
//please enter account number :
//4563
//please enter the code :
//3344
//enter the amount of the deposit :
//1000
//08 : 00 : 50
//account # : 4563 new balance : 1000
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//2
//please enter account number :
//45789
//please enter the code :
//1010
//enter the amount of the deposit :
//234
//08 : 01 : 20
//account # : 45789        new balance : 234
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//3
//please enter account number :
//12345
//please enter the code :
//1234
//enter the amount of money to withdraw :
//2000
//08 : 02 : 10
//account # : 12345        new balance : -2000
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//4
//08:03 : 10
//sum of all deposits : 1234
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//5
//08:04 : 10
//sum of all withdrawals : 2000
//enter 1 to get account balance
//enter 2 to deposit money
//enter 3 to withdraw money
//enter 4 to see the sum of all deposits
//enter 5 to see the sum of all withdrawals
//enter 0 to stop
//0