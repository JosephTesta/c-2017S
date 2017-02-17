#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

int main() {
	double theta = 0;
	double r = 0;
	double xCoord = 0;
	double yCoord = 0;
	while(true) {
		cout << "Enter an angle(degrees) and distance" << endl;
		cin >> theta >> r;
		if(theta < 0 || r < 0)
			return 0;
		theta = 90.0 - theta;
		theta = theta * M_PI / 180.0;
		xCoord += r * cos(theta);
		yCoord += r * sin(theta);
		cout << "Location: x = " << xCoord << ", y = " << yCoord << endl;
	}

	return 0;
}