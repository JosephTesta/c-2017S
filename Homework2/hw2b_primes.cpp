/**
  hw2b - Primes
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangiarella, and John Martin
*/

#include <iostream>
using namespace std;

bool isPrime(unsigned long long p) {
	if (p <= 1) {
		return false;
	}
	for (unsigned long long i = 2; i < p; i++) {
		bool returnValue = true;
		if (p % i == 0)
			return false;
	}
	return true;
}

int main() {
	unsigned long long x = 0;
	cout << "Enter a number to check if its prime\n";
	cin >> x;
	if (isPrime(x) == true) {
		cout << x << " is prime" << '\n';
	}
	else {
		cout << x << " is NOT prime" << '\n';
	}

	return 0;
}