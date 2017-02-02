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
	double n;
	double PI = 3.14159265;

	
	r = 1;
	cout << "for n=" << "1" << ": " << r << endl;
	for(n=3; n <= 1000000; n++){
		r = r/(cos(PI/n));
		if (n==10 || n==100 || n==1000 || n== 10000 || n==100000 || n==1000000) {
			cout << "for n=" << n << ": " << r << endl;
		}
	}
	

	

    return 0;
    //exit(0); is another option
}