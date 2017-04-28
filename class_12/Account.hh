#ifndef ACCOUNT_HH_
#define ACCOUNT_HH_
#include <iostream>
using namespace std;

class Account {
private:
	long long balance;
public:
	Account() {
		balance = 0; //start with no money
	}

	void deposit(long long amt) {
		balance += amt; //READ balance into register add amt
	}

	bool withdraw(long long amt) {
		if (amt < balance) {
			balance -= amt;
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& s, const Account a) {
		return s << "balance = " << a.balance;
	}
};

#endif