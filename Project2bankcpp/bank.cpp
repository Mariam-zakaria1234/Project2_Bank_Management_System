#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include"bank.hpp"
#include"Account.hpp"
#include"sivCheck.hpp"
using namespace std;

void bank::deposit(double amount, int  ID) {
	if (amount <= 0) {
		throw
			invalid_argument("Invalid deposit amount! must be greater than '0'");
	}
	auto it = find_if(accounts.begin(), accounts.end(), [ID](const auto& ac) {
		return (ac->gettID() == ID);
		});
	//found
	if (it != accounts.end()) {
		(*it)->deposit(amount) ;
	}
	else {
		throw
			runtime_error("Error: Account not found ");
	}
}
void bank::createAccount() {
    string name;
    int ID;
    double balance;

    cout << "Enter Account ID: ";
    while (true) {
        while (!(cin >> ID)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid ID: Please enter numbers only: ";
        }
        auto it = find_if(accounts.begin(), accounts.end(), [ID](auto& acc) {
            return acc->gettID() == ID;
            });
        if (it != accounts.end()) {
            cout << "this Account ID already exists:please enter a different ID \n";
        }
        else {
            break;
        }
    }
    cout << "Enter Username: ";
    cin >> name;

    cout << "Enter Initial Balance: ";
    while (!(cin >> balance) || balance < 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid balance! Please enter a valid number: ";
        }
        else {
            cout << "balance cannot be negative:enter a positive balance:\n ";
        }
    }
   

    int choice;
    cout << "Select account type:\n";
    cout << "1. Current account\n";
    cout << "2. Saving account\n";

    while (true) {
        cout << "Enter your choice (1 or 2): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            accounts.push_back(make_shared<check>(name, ID, balance));
            cout << "Current Account created successfully\n";
            break;
        }
        else if (choice == 2) {
            accounts.push_back(make_shared<saving>(name, ID, balance));
            cout << "Saving Account created successfully\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
void bank::withdraw(double amount, int  ID) {
	auto it = find_if(accounts.begin(), accounts.end(), [ID](const auto& acc) {
		return (acc->gettID()==ID);
		});
	if (it != accounts.end()) {
		(*it)->withdraw(amount);
	}
}
void bank::displayAllAccount() {
	if (accounts.empty()) {
		cout << "No accounts found in the bank yet\n";
		return;
 }
	cout << "***************All bank accounts**************\n";
		 for (const auto& a : accounts) {
		     a->displayData();
	}
}
void bank::displaydetails(const int & id) {
	auto it = find_if(accounts.begin(), accounts.end(), [id](const auto& ac) {
		return (ac->gettID() == id);
		});
	if (it != accounts.end()) {
		(*it)->displayData();
	}
}
void bank::saveToFile() {
    ofstream outFile("accounts.txt", ios::trunc);
    if (!outFile) {
        cout << "error opening file for writing \n";
        return;
    }
    for (const auto& acc : accounts) {
        acc->save(outFile);
    }
    outFile.close();
}
void bank::loadFromFile() {
    ifstream inFile("accounts.txt");
    if (!inFile) {//اول مره نفتحه 
        return;
    }
    int type, id;
    string name;
    double balance;
    while (inFile >> type >> id >> name >> balance) {
        if (type == 1) {
            accounts.push_back(make_shared<check>(name, id, balance));
        }
        else if (type == 2) {
            accounts.push_back(make_shared<saving>(name, id, balance));
        }
        inFile.close();
    }




}
bank::bank() {
    loadFromFile();
}