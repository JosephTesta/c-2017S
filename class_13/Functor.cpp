#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class F {
	double operator ()(double x) {
		return x*x;
	}
}

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

template<typename Func>
double euler2(Func f, double a, double b, int n) {
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