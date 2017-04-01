#include <iostream>
using namespace std;
#include <string>;
int a; //good
int dummy; //good
int a123; //good 
//int 1a; //Illegal. don't start a variable with a number 
//int a+1; //Illegal
int asdajsfkasjf_; //good
//int _abc; //Don't do this. variable beginning with _ are reserved to the compiler
//int __SYMBOLS__// Don't do this: reserved to the standard
//just don't start variables with underscores

//__LINE__  //this is the line number in the current file. they maintain the count.
//__FILE__  // the file name you are in
//__FUNCTION__  //??? Not important, different depending on C or C++ and C++11



class A {
	int _a; //some people use this notation to make in private, but Kruger doesn't like this
}

class BadSize {
private:
	int linenum;
	const string filename;

public:
	BadSize(int linenum, const char filename[]) : linenum(linenum), filename(filename){} //can't just use __LINE__ here or you get this line. old fashion C pointer
	friend ostream& operator <<(ostream& s, const BadSize& e) { //not copying is a lot faster because of the string (which is a pointer)
		return s << "BadSize at" << e.filename << ": " << e.linenum
	}
};

class Matrix {
private:

public:
	friend Matrix operator +(const Matrix& a, const Matrix& b) {
		int a = 5, b = 6;
		if (a != b)
			//you have the ball, which you defined as something. you can throw a string, number, Tantrum (class that you create)
			throw BadSize(__LINE__,__FILE__);
	}
}


int main() {
	try {
		int a = 5, b = 6;
		if (a != b)
			throw BadSize(__LINE__,__FILE__);
	}
		catch(const BadSize& e) {
		cout << e << '\n';
	}
}