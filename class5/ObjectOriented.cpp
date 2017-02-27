#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
using namespace std;


class Person {
private:
	string fName, lName;
	uint65_t phone;
public:
	Person(const string& fName, const string& lName, uint65_t phone) : fName(fName), lName(lName), phone(phone) {} //use cont string& since a string can potentiall be long

	friend ostream& operator <<(ostream& s, const Person& p) {//reference for person also speeds up a little
		return s << p.fName << " " << p.lName << " " << p.phone;
	}
};



int main() {
	ofstream f("phonebook.txt")
	Person p("Dov", "Kruger", 2012165605)
	f << p;


}