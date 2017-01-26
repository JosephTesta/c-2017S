/**
  HW1f - Mystery Sum (Pi)
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double sumOfSquares = 0;
	for(double a = 1; a <= 100000; a++){
		sumOfSquares += 1/(a*a);
	}
	

	cout << sqrt(6*sumOfSquares) << endl;

    return 0;
    //exit(0); is another option
}
