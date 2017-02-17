/**
  hw2a - Wind Chill 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangiarella, and John Martin
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double axisArray[12][18] = {0}; //I thought it said to use an array. I'm dumb. This could've been a lot simpler, but I learned more this way
	for(int i = 0; i < 12; i++)
		for (int j = 0; j < 18; j++) {
			double T = (-5*j+40);
			double V = 5*(i+1);
			axisArray[i][j] = 35.74 + 0.6215*T - 35.75*pow(V,0.16) + 0.4275*T*pow(V,0.16);
		}
	for(int i = 0; i < 12; i++) {
		for (int j = 0; j < 18; j++) 
			cout << int(nearbyint(axisArray[i][j])) << ' '; 
		cout << '\n';
	}
	return 0;
}