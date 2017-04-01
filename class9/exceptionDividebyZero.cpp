#include <iostream>
using namespace std;
#include <string>

class DivByZero {
private:
	int linenum;
	const string filename;

public:
	DivByZero(int linenum, const char filename[]) : linenum(linenum), filename(filename){} //can't just use __LINE__ here or you get this line. old fashion C pointer
	friend ostream& operator <<(ostream& s, const DivByZero& e) { //not copying is a lot faster because of the string (which is a pointer)
		return s << "DivByZero Error in " << e.filename << ": " << e.linenum;
	}
};

void g() throw (DivByZero) { //here it means this function could throw this exception. it's a list of what could be thrown throw(DivByZero,BadSize, etc.). dont have to do this, but it's good practice
	int x = 0, y = 0;
	if(x==0)
		throw DivByZero(__LINE__,__FILE__);
	y/x;
}
void f() throw (DivByZero) { //throw(*) means throw everything
	g();
}

int main() throw() { //main itself doesn't throw anything
	try {
		f();
	}
		catch(const DivByZero& e) {
		cout << e << '\n';
	}
}