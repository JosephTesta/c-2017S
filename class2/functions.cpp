#include <iostream>
#include <cmath>
using namespace std;

void hello() { //void means returns nothing
	cout << "hello";
}

void printDouble(int x) {
	cout << x * 2;
	x++; //isn't carried through
}

double f(double x) { return pow(x, 2); } // compiler makes it x*x in c++


int main() {
	hello(); //prints hello by calling function
	hello();
	printDouble(3); //prints 6 by function
	for (int i = 0; i < 3; i++)
		printDouble(3);
	int sum = 0;
	for (int i = 1; i < 10; i ++) {
		sum = sum + f(i); //shouldn't do this since it wants double
		cout << << sum << '\n'; //could've done type casts double (i) or (double) i
	}


	return 0;
}