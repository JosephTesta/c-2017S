/**
  HW1c - Sum 1-100 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
using namespace std;


int main() {
	int a = 100;
	int gaussSum = 0;
	gaussSum = a*(a+1)/2;

	cout << "Gauss formula (n(n+1))/2 for 1 to 100: " << gaussSum << endl;

	int forSum = 0;
	
	for(int c = 1; c <= 100; c++){
	forSum += c;
	}

	cout << "For loop sum is: " << forSum << endl;


    return 0;
    //exit(0); is another option
}