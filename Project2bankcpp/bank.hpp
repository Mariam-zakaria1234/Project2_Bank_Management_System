#include<iostream>
#ifndef BANK_HPP
#define BANK_HPP
#pragma once 
#include"Account.hpp"
#include "sivCheck.hpp"
#include <vector>
#include <string>
#include<memory>
class bank {
private:
	vector<shared_ptr<Account>>accounts;
public:
	bank();
	void deposit(double amount,int  ID);
	void  withdraw(double amount, int ID);
	void displayAllAccount();
	void createAccount();
	void displaydetails(const int& id);
	void saveToFile();
	void loadFromFile();

};
#endif 