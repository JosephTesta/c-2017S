#include <iostream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	//initializer list synta is prefferred. know both ways
	//in this cas it is the only one that works
	//Fraction(int n, int d) : num(n), den(d) {}
	// Fraction(int n) : num(n), den(1) {}
	// Fraction() : num(0), den(1) {}

	// Fraction(int num, int den) { //this method is bad, if you were using const, then it messes up
		//this ->num = num;
		//this->den = den; }

	Fraction(int num, int den) : num(num), den(den) {}
	Fraction(int num) : num(num), den(1) {}
	Fraction() : num(0), den(1) {}

	Fraction(int num = 0, int den = 1) : num(num), den(den) {}

};

int main() {
	Fraction x(1,2); //must call a constructor with 2 parameters. can only have 1 constructor with the same parameters.
	Fraction y(3);
	Fraction z(); //this won't cause an error, but z is a function. really weird
	Fraction w; //automatically makes num=0 and den = 1

	//illegal: num is private w.num = 5;//wont work since num is private
	//illegal because z is a function of some kind z.num = 9; 

	/*
	int a;
	a = 5;
	int b = 5;

	//const initialization example
	const int c = 5; //fine
	const int d;
	d = 5; //error
	*/


}