#include <iostream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	//default constructor: written only if none written Fraction() {}
	Fraction(int num, int den) : num(num), den(den) {}
	Fraction(int num) : num(num), den(1) {}
	Fraction() : num(0), den(1) {}


	friend ostream& operator <<(ostream& s, const Fraction f) {
		return s << f.num << "/" << f.den;
	}

	void print() const { //needs const there or else const Fraction x(1,2) can't be used even if it isn't changing anything. wont change the this parameter Fraction* this = our object
		//putting const with the parameter would say you aren't changing that parameter. could still change this->num for example in this class
		cout << num << "/" << den; //could use this->num but it understands just num
	}

	friend Fraction add(Fraction a, Fraction b) { //copies the object. passes by value

	}

	friend Fraction add(const Fraction& a, const Fraction& b) { //

	}


	friend Fraction operator +(Fraction a, Fraction b) { //
		//could create a fraction named something, then return the named value
		return Fraction(a.num * b.den + b.num * a.den, a.den * b.den); //privacy is on a class bases. friend function has the rights to all objects of FRaction class
	}

	friend Fraction operator -(Fraction a, Fraction b) { //
		//could create a fraction named something, then return the named value
		return Fraction(a.num * b.den - b.num * a.den, a.den * b.den); //privacy is on a class bases. friend function has the rights to all objects of FRaction class
	}

	friend Fraction operator -(Fraction a) { 
		return Fraction(-a.num,a.den); 
	}

};

int main() {
	const Fraction x(1,2);
	cout << x; //passed by value(copy) x is not changed. cout is passed by reference
	x.print();
	const Fraction y(1,3);
	Fraction z = add(x,y);
	Fraction f = -x; //one paramater

	int a = 5;
	int b = a++; //first make b = a, then add 1 to a. post increment
}