/**
  hw2c - Multiple Primes 
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

int countPrimes(unsigned long long a, unsigned long long b) {
	int primeCount = 0; 
	if (a > b) {
		for (unsigned long long i = b; i <= a; i++){
			if (isPrime(i) == true) {
				primeCount++;
			} 
		}
	}
	if (b > a) {
		for (unsigned long long i = a; i <= b; i++){
			if (isPrime(i) == true) {
				primeCount++;
			} 
		}
	}
	return primeCount;
}

int main() {
	unsigned long long a = 0, b = 0;
	cout << "Enter a number to check if its prime\n";
	cin >> a >> b;
	cout << "There are " << countPrimes(a,b) << " primes between " << a << " and " << b << '\n';
	return 0;
}