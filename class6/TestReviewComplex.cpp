#include <iostream>
using namespace std;

class Complex {
private:
	double r,i;
public:
	Complex(double r, double i) : r(r), r(i) {}

	friend Complex operator +(const Complex& a, const Complex& b) {
		Complex ans(a.r + b.r, a.i + b.i);
		return ans;
		//or return Complex(a.r + b.r, a.i + b.i);
	}
	friend ostream& operator <<(ostream& s, const Complex& c){
		return s << c.r << " + " << c.i << "i";
	}
	



};


int main() {
	Complex a(2.5, 0.5);
	Complex b(1.5, 1.0);
	const Complex c = a + b;
}