/**
  HW1b - Convergence of N Gons 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
#include <math.h>
using namespace std;


int main() {
	double rOriginal = 1;
	double r = 1;
	int n;
	double PI = 3.14159265;

	while(true){
		cout << "Enter n for number circumscribes" << endl;
		cin >> n;
		r = 1;
		for(n; n >= 3; n--){
			r = r/(cos(PI/n));
		}
		cout << r << endl;
	}

    return 0;
    //exit(0); is another option
}