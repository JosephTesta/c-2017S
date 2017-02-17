/**
  HW1e - Factorial 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
using namespace std;


int main() {
	int inputNumber = 0;
	double factorial = 1;
	cout << "enter a number to solve factorial: " << endl;
	cin >> inputNumber;
	while(inputNumber >= 1) { 
	factorial = factorial*inputNumber;
	inputNumber--;
	}

	cout << "factorial is: " << factorial << endl;




    return 0;
    //exit(0); is another option
}
