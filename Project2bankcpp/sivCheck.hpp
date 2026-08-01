#include <iostream>
#include "Account.hpp"
#include<fstream>
#include<string>
#ifndef SIVCHECK_HPP
#define SIVCHECK_HPP

using namespace std;
class saving :public Account {
private:
 const double minBalance = 100.0;
public:
	saving(string name,int i , double ba) {
		username = name;
		id = i;
		balance = ba;
		
	}
	void  withdraw(double amount) override;
	void displayData()override;
	void save(ofstream& outFile) override {
		outFile << 2 << " " << id << " "<<username << " " << balance << "\n";
	}
};

class check :public Account {
public:
	check(string name, int i, double ba) {
		username = name;
		id = i;
		balance = ba;
	}
	void  withdraw(double amount) override;
	void displayData() override;
	void save(ofstream& outFile)override {
		outFile << 1 << " " << id << " " << username << " " << balance << "\n";
	}
};
#endif