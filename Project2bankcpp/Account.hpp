#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#pragma once 
#include <iostream>
#include <fstream>//to using ofstream
#include<string>
using namespace std;
class Account {
protected:
	string username;
	int  id;
	double balance;
	
public:
	Account() = default;
	string gettusername() {
		return username;
	}
	int gettID() {
		return id;
	}
	double  gettbalance() {
		return balance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance = balance + amount;
			cout << "Done \n";
			cout << "New balance: " << balance;
		}
		else {
			cout << "Invalid deposit amount\n ";
		}
	}
	virtual void  withdraw(double amount) = 0;
	virtual void displayData() = 0;
	virtual void save(ofstream& outFile) = 0;

};
#endif 
