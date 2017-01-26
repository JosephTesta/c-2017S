/**
  HW1a - 3n+1 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
using namespace std;

int main() {

	int a;
	cout << "enter a number" << endl;
	cin >> a;

	while(a != 1){
		if(a % 2 == 1) {
			a = a*3 + 1;
		}
		else {
			a = a/2;
		}
		cout << "a is currently:" << a << endl;
	}
	cout << "The final number is now: " << a << endl;
    return 0;
    //exit(0); is another option
}
