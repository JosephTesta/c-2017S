// goal: represent numbers lik 1/2, 2/3, 5/2, 0/0, 5/0
#include <iostream>
using namespace std;


class Fraction {
private:
	int num, den;

public:
	Fraction(int n = 0, int d = 1) : num(n), den (d) {} //this does all three of the above, but in one constructor
	friend ostream& operator <<(ostream& s, Fraction f);

};

ostream& operator <<(ostream& s, Fraction f) {
	s << f.num << "/" << f.den; //we can't use num and den unless you use friend
	return s;
}

int main() {
	const Fraction a(1,2); //you would need const in a different place as well. by the void print
	//Fraction a(1,2); //this will make a fraction 1/2
	Fraction b(3); // 3/1
	Fraction c; // 1/1 --> 0/1 these are reasonable choice for unitialized 
	cout << a << ' ' << b << '\n';
	//Fraction d = a + b;
}