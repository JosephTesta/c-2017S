#include <iostream>
#define _USE_CONSTANTS //this mmight be wrong. it's for PI
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;
//inline only has to do with how fast it runs. If you never use it, then it won't do inline
void polar2rect(double r, double theta, double& x, double& y) {
	x = r * cos(theta);
	y = r * sin(theta);
}


int main() {
	int a = 2; //variable
	int b = a; //exact copy of a
	a++; //a is now 3
	cout << b << '\n';
	int& s = b; //reference to b
	s = 5; //both r and b are now 5

	double r = 1, theta = PI/2;
	double x,y;
	polar2rect(r,theta,x,y);
}