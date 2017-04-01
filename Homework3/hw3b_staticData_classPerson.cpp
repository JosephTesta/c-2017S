/**
  hw3b - Static Data 
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangiarella, and John Martin
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	static int count;// in this context, static means class shared
public:
	Person(string n, int a):name(n), age(a) {
		count++;
		//cout << name << " is born" << endl;
	}

	~Person() {
		count--;
		//cout << name << " has died" << endl;
	}

	string getName() const {
		return name;
	}
	
	int getMemberCount() const{
		return count;
	}

	static int getCount() {
		return count;
	}

	friend ostream&  operator <<(ostream& s, const Person& p) {
    return s << p.name << " " << p.age;
	}
};

int Person::count = 0;

void f() {
	Person p3("Maria", 32);
}

void g(const Person& p) {
	cout << p << '\n';
}

int main() {
	cout << Person::getCount();
	f();
	const Person p1("Dov", 50);
	cout << p1.getName() << '\n';
	
	const Person p2("Yu-Dong", 45);
	for (int i = 0; i < 5; i++)
		g(p2);
	cout << p1 << '\n';
	cout << p2.getMemberCount();
	cout << '\n' << "Maria's object only exists within the function f. The constructor and destructor are both called in the line f(); so she doesn't add to the count." << endl;
}
