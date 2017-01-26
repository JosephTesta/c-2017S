/**
  HW1d - Sum Reciprocals 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
using namespace std;


int main() {

float sum1Float = 0;
float sum2Float = 0;
double sum1Double = 0;
double sum2Double = 0;


	for(float a = 1; a <= 100; a++){
	sum1Float += 1/a;
	}

	for(float b = 100; b >= 1; b--){
	sum2Float += 1/b;
	}

	for(double c = 1; c <= 100; c++){
	sum1Double += 1/c;
	}

	for(double d = 100; d >= 1; d--){
	sum2Double += 1/d;
	}

	cout << "sum1 using float: " << sum1Float << endl;
	cout << "sum2 using float: " << sum2Float << endl;
	cout << "difference of floats: " << sum1Float-sum2Float << endl;
	cout << "sum1 using double: " << sum1Double << endl;
	cout << "sum2 using double: " << sum2Double << endl;
	cout << "difference of doubles: " << sum1Double-sum2Double << endl;


    return 0;
    //exit(0); is another option
}
