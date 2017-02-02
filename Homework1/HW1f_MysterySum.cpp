/**
  HW1f - Mystery Sum (Pi)
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	float sumOfSquares = 0;
	for(float a = 1; a <= 100000; a++){
		sumOfSquares += 1/(a*a);
	}

		float sumOfSquares2 = 0;
	for(float a = 100000; a >= 1; a--){
		sumOfSquares2 += 1/(a*a);
	}
	

	cout << "Sum forward gives: " << sqrt(6*sumOfSquares) << endl;
	cout << "Sum backwards gives: " << sqrt(6*sumOfSquares2) << endl;

    return 0;
    //exit(0); is another option
}
