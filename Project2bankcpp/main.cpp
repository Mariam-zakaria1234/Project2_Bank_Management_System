#include <iostream>
#include <memory>
#include"bank.hpp"
using namespace std;
int main() {
	int choice;
	bank b;
	b.loadFromFile();
	do {
		cout << "*******************************WELCOME*********************************************\n";
		cout << "please select the operation\n";
		cout << "1.Withdraw\n2.Deposit\n3.Create Account\n4.Display Data\n5.Display All Account\n6.Save to data\n7.EXIT\n";
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Invalid input \n";
		}
		
	  switch (choice) {
	  
	case 1: {
		cout << "*****************************************\n";
		int  id;
		while (true) {

			cout << "Entr your Account ID \n";
			cin >> id;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else {
				break;
			}
		}
		double amount;

			cout << "Entr  amount to withdraw\n";
			cin >> amount;
			
			bool successful = false;
				while (successful) {
					try {
						b.withdraw(amount, id);
						successful = true;
						
					}
					catch (const exception& e) {
						cout << e.what() << endl;
						cout << "please try again \n";
					}
				}
				
				break;
	}
	case 2: {
		cout << "*****************************************\n";
		int  id;
		while (true) {

			cout << "Entr your Account ID \n";
			cin >> id;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else {
				break;
			}
		}
		double amount;

		cout << "Entr  amount to withdraw\n";
		cin >> amount;
		bool successful = false;
		while (successful) {
			try {
				b.deposit(amount, id);
				successful = true;

			}
			catch (const exception& e) {
				cout << e.what() << endl;
				cout << "please try again \n";
			}
		}
		break;
	}
	case 3: {
		cout << "******************************************\n";
		b.createAccount();
		
		break;
	}
	case 4: {
		cout << "*****************************************\n";
		int id;
		while (true) {

			cout << "Entr your Account ID \n";
			cin >> id;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else if (id < 0) {
				cout << "Invalid ID: Please enter a positive number: ";
			}
			else {
				break;
			}
		}
		b.displaydetails(id) ;
		
		break;
	}
	case 5: {
		cout << "*****************************************\n";
		b.displayAllAccount();
		
		break;
	}
	case 6: {
		b.saveToFile();
		cout << "Data saved successfully\n";
		break;
		}
	case 7: {
		cout << "Exiting the program:Goodbye...\n";
		b.saveToFile();
		break;
	}
	default: cout << "Invalid input\n";
		break;
		
		} 

	} while (choice != 7);
	return 0;
}