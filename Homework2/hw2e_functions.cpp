/**
  hw2e - Functions 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangiarella, and John Martin
*/

#include <iostream>
using namespace std;

double fact(unsigned int x) {
	if(x == 0){
		return 1;
	}
	double factorial = 1;
	while(x >= 1) { 
		factorial = factorial*x;
		x--;
	}

	return factorial;
}

double fact2(unsigned int x) {
	if(x == 0) {
		return 1;
	}
	else if(x == 1) {
		return 1;
	}
	else {
		return x*fact2(x-1);
	}
}


double choose(unsigned int n, unsigned int r) {
	double b = fact(n)/(fact(r)*fact(n-r));
	return b;
}

double fibo(int x) {
	double a = 1, b = 1, c = 1;
	for(int i = 3; i <= x; i ++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

double fibo2(unsigned int x) {
	if(x == 1 || x == 2) {
		return 1;
	}
	return fibo2(x-2) + fibo2(x-1);
}


 int main() {
	cout << fact(5) << ' ' << fact2(5) << '\n';
	cout << fact(15) << ' ' << fact2(15) << '\n';
	cout << fibo(5) << ' ' << fibo2(5) << '\n'; 
	cout << fibo(13) << ' ' << fibo2(13) << '\n';
	cout << choose(52,6) << '\n';


	return 0;
 }