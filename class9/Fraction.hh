#ifndef FRACTION_HH_
#define FRACTION_HH_

#include "DivByZero"

class Fraction {
private:
	int num, den;

public:
	Fraction(int n, int d) throw (DivByZero) : num(n), den(d) { //never let bad values get into object, like denom of zero
		if (d == 0) {
			throw DivByZero(__LINE__,__FILE__);
		}
	}
	
	friend Fraction operator +(Fraction a, Fraction b) {
		return Fraction(a.num*b.den + b.num*a.den, a.den*b.den);
	}

	friend Fraction operator *(Fraction a, Fraction b) {
		return Fraction(a.num*b.num, a.den*b.den);
	}

	friend std::ostream& operator <<(std::ostream& s, Fraction f) {
		return s << f.num << '/' << f.den;
	}
};

#endif