#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person(const string& name, int age) : name(name), age(age) {}

	friend ostream& operator <<(ostream& s, const Person& p) {
		return s << p.name << ' ' << p.age;
	}

};

int main() {
	cout << sizeof(Person) << '\n';
	int a[10]; //array is a const pointer and memory allocation. can't change it like you can another pointer
	int*b = a; //this is ok since a is pointing to first element
	for (int i = 0; i < 10; i++)
		*b++ = 0;
	//b is pointing one past the end

	b = &a[9]; //make it point to the last one.
	for (int i = 9; i >= 0; i--)
		*b-- = i;
	//b pointing where? a[-1]. one beyond the start.
	//pointer can go outside of your range, but don't try using it or you could crash or overwrite stuff.

	Person c[3] = {
		Person("Dov", 50), //old way
		{"Yu-Dong", 40}, //new way in c++11
		Person("Moshe", 15)

	};

	for (int i = 0; i < 3; i++)
		cout << c[i] << '\n';



}