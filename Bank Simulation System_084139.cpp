#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	string ownerName;
	double balance;

public:
	BankAccount(string name) : ownerName(name),
	balance(0.0) {}

	void deposit(double amount) {
		balance =+ amount;
		cout << "Deposited: $" << amount << endl;
	}

	void withdraw(double amount) {
		if (amount > balance) {
			cout << "Insufficient funds!" << endl;
		} else {
			balance -= amount;
			cout << "withdrew: $" << amount << endl;
		}
	}

	void displayBalance() const {
		cout << "Balance for " << ownerName << ": $" << balance << endl;
	}
};

int main() {
	BankAccount account("Abednego");

	account.deposit(1000);
	account.withdraw(500);
	account.displayBalance();

	account.withdraw(600);

	return 0;
}