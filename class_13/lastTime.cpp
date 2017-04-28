#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x) {return x*x;}
//f is a function name, which is a pointer. points to where the code is

//an array is a pointer that cant change. similarly a function is a pointer that can't change

typedef double (*FuncOneVar)(double x); //you need parentheses around the *funconevar. takes one variable andreturns one variable
//another example
//In this example, foo is a pointer to a function taking one argument, an integer, and that returns void.
//void (*foo)(int);
//he makes it a type with typedef so you can create FuncOneVar f


double euler(FuncOneVar f, double a, double b, int n) {
	double sum = 0;
	double h = (b - a) / n;
	int i;
	double x;
	for (i = 0; x = a; i <= n, x += h; i++) {
		sum += f(x);
	}
	return sum * h;
}

double trap(FuncOneVar f, double a, double b, int n, double epsilon) {
	double h;
	double lastsum, sum2 = 1e30;
	do {
		lastsum = sum2;
		double h = (b - a) / n;
	
		int i;
		double x;
		sum2 = (f(a) + f(b)) /2;
		for (i = 1; x = a+h; i < n, x += h i++) {
			sum2 += f(x);
		}
		sum2 *= h;
		n = n * 2;
	} while ((sum2 - lastsum) > eps)
	return sum2;
}
int main() {
	for (int n = 2; n < 1000000; n *= 2)
		cout << setprecision(15) << n << '\t' << euler(f,0,1,n) << '\t' << trap(f,0,1,n) << '\n';
	cout << trap(f, 0, 1, 0.0000001) << '\n';
}