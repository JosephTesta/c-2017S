#include <iostream>


class Fraction {
private:
	int num, den;
	static int count;
public:
	Fraction(int n=0, int d = 1): num(n), den(d) {
		count++;
	}
	~Fraction() {
		count--;
	}

	friend Fraction operator +(const Fraction& a, const Fraction& b) {
		return Fraction(a.num*b.den + b.num*a.den, a.den*b.den);
	}
	friend std::ostream& operator <<(std::ostream& s, const Fraction& a) {
		return s << a.num << " / " << a.den << std::endl;
	}

	static int getCount() {
		return count;
	}

	int getNum() {
		return num;
	}

	int getDen() {
		return den;
	}

	Fraction add(const Fraction& a){
		return Fraction(a.num*den + num*a.den, a.den*den);
	}

	int getMemberCount() {
		return count;
	}

};

int Fraction::count = 0;

int main() {
	Fraction a = Fraction(1,5);
	//std::cout << Fraction::getCount() << std::endl;
	Fraction b(0);
	Fraction f[3];
	f[0] = Fraction(2);
	std::cout << f[0];
	//std::cout << Fraction::getCount() << std::endl;
	Fraction c(2);
	//std::cout << Fraction::getCount() << std::endl;
	Fraction d = a + b;
	Fraction e = a.add(c);
	//std::cout << Fraction::getCount() << std::endl;
	std::cout << a << b << c << d << e;
	std::cout << a.getNum() << b.getDen() << std::endl;
	std::cout << a.getMemberCount() << std::endl;
	//std::cout << Fraction::getCount();
	



}