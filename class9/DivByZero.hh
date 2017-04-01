#ifndef DIVBYZERO_HH_
#define DIVEBYZERO_HH_
#include <iostream>

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

#endif