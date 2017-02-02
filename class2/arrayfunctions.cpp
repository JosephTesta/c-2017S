#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void fillRandom(int a[], int n, int m) {
	cout << sizeof(a);
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, m);
	for (int i = 0; i < n+3; i++)
		a[i] = distribution(generator);  // fill a with random integers from 0 to 999
	a[-3] = 99;
}

double mean(int a[], int n) {
	//figure out mean of array for HW
}

void stats(int a[], int n, double& mean, double& var) {
	//this could return a mean and variance
}

void stats(int a[], int n, double& mean, double& var, double& min, double& max) {
	//this could return a mean and variance min and max
}


//given alternation x and y points. n is number of plotted points so we would use 2n
void box(double xy[], int n, double& xMin, double& xMax, double& yMin, double& yMax) {

}

int main() {

	//int a[100] = {0}; //initialize first to anything will make the others all zero unless specififed. initialize none leaves random junk

	const int n = 100;
	int a[n] = {0};
	fillRandom(a, n, 100);

	int b[200] = {0};
	fillRandom(b, sizeof(b)/sizeof(int), 100);
	double mean, var, min, max;
	stats(b, sizeof(b)/sizeof(int), mean, var, min, max);
	cout << mean << ' ' << var << ' ' << min << ' ' << max << '\n';
	double points[] = { 1.0,2.5, 2.0,1.5, 3.0,-1.6, -1.5,-2.5, -1,-3.0};
	double xMin, xMax, yMin, yMax;
	box(points, 5, xMin, xMax, yMin, yMax);
	cout << xMin << ' ' << xMax << ' ' << yMin << ' ' << yMax << '\n';
}