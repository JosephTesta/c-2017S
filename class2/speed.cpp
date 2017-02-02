#include <iostream>
#include <cmath>
using namespace std;


void printDouble(int x) {
	cout << x * 2;
	x++; //isn't carried through
}

inline double f(double x) { return pow(x, 2); } // compiler makes it x*x in c++
	//inline does something with optimization?

int main() {
	const long long n = 1000000000LL;
	long sum = 0;
	for (long long i = 1; i <= n; i ++)
		sum = sum + f(i);
	cout << sum;



	return 0;
}