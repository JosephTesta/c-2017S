/**
  hw2d - Choose 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangiarella, and John Martin
*/

#include <iostream>
using namespace std;

double factorial(unsigned int x) {
	if(x == 0){
		return 1;
	}
	unsigned int factorial = 1;
	while(x >= 1) { 
		factorial = factorial*x;
		x--;
	}

	return factorial;
}


double choose(unsigned int n, unsigned int r) {
	double b = factorial(n)/(factorial(r)*factorial(n-r));
	return b;
}


 int main() {
  	cout << choose(1,1) << '\n';
   	cout << choose(2,1) << '\n';	
 	cout << choose(2,0) << '\n';
 	cout << choose(2,2) << '\n';
 	cout << choose(8,3) << '\n';

 	return 0;
 }