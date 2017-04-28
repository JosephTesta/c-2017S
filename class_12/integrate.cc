

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double x) {return x*x;} // integrate(f, 0,1) = 1/3

typedef double (*FuncOneVar)(double x);

double integrate(FuncOneVar f, double a, double b, int n) {
	double sum = 0;
	int n = 2;
	double h = (b - a) / n;
	int i;
	double x;
	for (i = 0, x = a; i <= n; x += h, i++) {
		sum += f(x);
	}
	return sum * h;
}

int main() {
	for (int n = 2; n < 1000000; n *= 2)
		cout << setprecision(15) << n << '\t' << integrate(f, 0, 1, n) << '\n';
}
//idk look at his