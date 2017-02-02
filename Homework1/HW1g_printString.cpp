/**
  HW1g - Print String 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangi, and John Martin
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	string thisString = "";
	cout << "enter an integer" << endl;
	cin >> n;

	if(n == 0){
		char x = '0';
		thisString = x + thisString;
	}
	while(n>0){
		char x = n % 10 + '0';
		thisString = x + thisString;
		n /= 10;
	}	

	cout << thisString << endl;


    return 0;
    //exit(0); is another option
}