// goal: represent numbers lik 1/2, 2/3, 5/2, 0/0, 5/0
#include <iostream>
using namespace std;


class Fraction {
private:
	int num, den;

public:
	/*
	Fraction(int n, int d) : num(n), den(d) {//constructor is a special function with the
							//same name as the class. no return type like void. doesn't return. called whenever make object. initialization
		//num = n; den =d; //can do it this way or with the colon preferred way initialization. Do it with colon

	}

	Fraction(int n) : num(n), den(1) {

	} 

	Fraction(): num(0), den(1) { //this is for case c, not d

	}
	*/

	Fraction(int n = 0, int d = 1) : num(n), den (d) {} //this does all three of the above, but in one constructor

	/*
	void print() { //this is a method. object.print(); to use it
		cout << num << '/' << den;
	}
	*/

	void print() const {
		cout << num << '/' << den;
	} //this member function (method) is READONLY. use const for speed and safety. use whenever you can


};
/*
	class 	object
	methods	messages

	class = specification of an object
	object = instance of a class

	encapsulation: hiding the details of an object internally (private)
*/
/*
void Fraction::print() const
{
	cout << num << "/" << den;
}
*/
int main() {
	const Fraction a(1,2); //you would need const in a different place as well. by the void print
	//Fraction a(1,2); //this will make a fraction 1/2
	Fraction b(3); // 3/1
	Fraction c; // 1/1 --> 0/1 these are reasonable choice for unitialized 
	Fraction d(); // This is not an object. This is a function prototype

	int x = 3; //immediately initialized. Do this
	int y; // not assigned anything yet.
	cout << y << endl; //printing random junk
	y = 3;



	a.print(); //a method print on the object that prints content of the fraction
	b.print();
	c.print();
}