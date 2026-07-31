#include<iostream>
#include "sivCheck.hpp"
using namespace std;

void  saving::withdraw(double amount) {
	if (amount <= 0) {
		throw 
		invalid_argument("Invalid withdraw amount! must be greater than '0' ");
	}
	if (  balance - amount < minBalance) {
		throw 
			runtime_error("Exceed minimum balance limit ");
	}
	balance = balance - amount;
	cout << "The amount of " << amount << " has been succefully withdraw\n ";
}
void  saving::displayData() {
	cout << "************Saving Account Details*************\n";
	cout << "Account ID: " << id;
	cout << "\nUser name: " << username;
	cout << "\nBalance: " << balance;
	cout << "\nMinimum balance limit: " << minBalance;
	cout << "\nSaving Account\n ";
}
void check::withdraw(double amount) {
	if (amount <= 0) {
		throw
			invalid_argument("Invalid withdraw amount! must be greater than '0' ");
	}
	if (balance - amount < 0) {
		throw
	       runtime_error("Exceed minimum balance limit ");
	}
	balance = balance - amount;
	cout << "The amount of " << amount << " has been succefully withdraw\n ";
}
void   check::displayData() {
	cout << "************Check Account Details*************\n";
	cout << "Account ID: " << id;
	cout << "\nUser name: " << username;
	cout << "\nBalance: " << balance;
	cout << "\nCurrent  Account\n ";
}