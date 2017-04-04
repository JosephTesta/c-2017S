#include <iostream>
#include <string>
using namespace std;
//typedef double Precision //everytime we say Precision, we mean double. can be used to help debug


#if 0
class Complex {
private:
	double real, imag;
public:
	Complex(double r, double i) : real(r), imag(i) {}
};

class Complex {
private:
	float real, imag;
public:
	Complex(float r, float i) : float(r), float(i) {}
};

//can't have two definitions of the same class

extern x;
extern x;
int x;
can only have one int x; but multiple extern x;

could do
class ComplexFloat {
	
}
class ComplexInt {
	
}
but this is a lot of extra work.
#endif

//instead

template<typename Precision>
class Complex {
private:
	Precision real, imag;
public:
	Complex(Precision r, Precision i) : real(r), imag(i) {}

	Complex neg() const { //don't need Complex<Precision> for method since it is in the class and knows it already 
		return Complex(-real,-imag);
	}

	friend Complex<Precision> operator +(Complex<Precision> a, Complex<Precision> b) {
		return Complex<Precision>(a.real+b.real, a.imag+b.imag);
	}

	friend Complex<Precision> operator -(Complex<Precision> a, Complex<Precision> b) { //friend on inside
		return Complex<Precision>(a.real - b.real, a.imag - b.imag);
	}

	friend ostream& operator <<(ostream& s, const Complex<Precision>& c) {
		return s << c.real << ' ' << c.imag;
	}
};


class Person {
private:
	string fname, lname;
};

int main() {
	const Complex<double> c1(1.5,2.0); //you have to tell it what type
	Complex<double> c3 = c1.neg();
	Person p1, p2;
	//Complex<Person> c2(p1,p2); //this is fine, but what if you add operator +? We didn't define what adding a person is anywhere
	Complex<string> c2("a","b"); 
	//Complex<string> c4 = c2.neg(); //you can't negate this though. Testing templates is hard because you need to test every permutation

	cout << c1 << '\n'; //this makes another requirement. first we write an operator << then it requires that each type we use is printable
	cout << c2 << '\n';
	cout << c3 << '\n';

	#if 0
	List<Elephant> elephants;
	List<int> list 1;
	//cin >> a;
	//List<a>; //can't do this since it hasn't compiled based on what you are asking in run time. 
	//templates are not run time.
	#endif
}