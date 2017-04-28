#include <iostream>
using namespace std;

unsigned int rand() {
	return seed = seed * 31097 + 37031;
}

bool isPrime(unsigned long long n) {
	for (long long i = 2; i < n; i++) 
		if (n % i == 0)
			return false;
	return true;
}

unsigned int countPrimes(insigned long long N) {
	unsigned int count = 0;
	for (long long n = 2; n < N; n++) {
		for (long long i = 2; i < n; i++)
			if (n % i == 0)
				goto notPrime;
		count++;
		notPrime: ;
	}
	return count;
}

int main() {
	for (int i = 0; i < 10; i++)
		cout << i;

	for (; ;) { //the middle condition isn't specified
		//infinite loop
	}

	for (int i = 0; ; i++) {
		//infinite
	}

	for (int i = 1; i != 0; i++) { //eventually reaches max int then loops back around.
		cout << i; 
	}

	while (true) {
		//also infinite. best option
	}

	while(1) {
		//also works for infinite
	}

	int r;
	do { //for if you want it at least once
		cin >> r;
	} while (r < 0 && r > 2*M_PI);

	isPrime(15051)

	for (int i = 0; i < 10; i++) 
		if (i%5 == 4)
			break;
		else
			cout << i;

	for (int i = 0; i < 10; i++) 
		if ( i % 5 == 4)
			continue; //skip the loop
		else
			cout << i; //01235678
}