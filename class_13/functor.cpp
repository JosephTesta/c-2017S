#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x); // integral(f,0,1) = 1/3
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

int main() {
	cout << setprecision(15) << euler(f,0,1,100000000) << '\n';
}