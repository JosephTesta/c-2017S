#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	static int count; // in this context, static means class shared
public:
	Person(string name, int age) : name(name), age(age) { //nameinsidetheobject(parameter name being passed)
		count ++;
	}

	~Person() { //deconstructor
		count--;
	}
	
	string getName() {
		return name;
	}

	static int getMemberCount() {
		return count;
	}

	friend ostream& operator <<(ostream& s, const Person& p) {//can have Person p or const Person& p which copies a person. faster. you want to write to a stream and change it. the stream isn't const
		return s << p.name << " " << p.age;
	}
};

int Person::count = 0; //inside class person there is count and it is zero.

void f() {
	Person p3("Maria", 32);
}

void g(Person p) {
	cout << p << '\n';
}


int main() {
	cout << Person::getCount();
	f();
	for (int i = 0; i < 5; i++)
		g(p2)
	const Person p1("Dov", 50);
	cout << p1.getName() << '\n';
	const Person p2("Yu-Dong", 45);
	cout << p1 << '\n';
	cout << p2.getMemberCount();

}