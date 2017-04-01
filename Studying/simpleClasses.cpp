#include <iostream>
#include <string>

class phoneBook {
private:
	std::string first;
	std::string last;
	long number;
	static int count;
public:
	phoneBook(const std::string& n = "No", const std::string& l = "One", long long num = 0) : first(n), last(l), number(num) {count++;}

	~phoneBook() {count--;}

	std::string getFirst() {
		return first;
	}

	friend std::ostream& operator <<(std::ostream& s, const phoneBook& a) {
		return s << "Name: " << a.first << " " << a.last << '\n' << "Number: " << a.number << std::endl;
	}

	static int getCount() {
		return count;
	}

	int getTheCount() {
		return count;
	}
};

class Person {
private:
	std::string first;
	std::string last;
	static int count;

public:
	Person(const std::string& f= "Bob", const std::string& l = "Bobertson") : first(f), last(l) {count++;}
	~Person() {count--;}
	virtual int take() const {
	//virtual int takeDump() const = 0; //pure virtual version. makes it abstract class.
		return 1;
	}
	static int getCount() {
		return count;
	}
};

class Sumo : public Person {
private:
	double weight;
public:
	Sumo(const std::string& f, const std::string& l, double w) : Person(f,l), weight(w) {}
	int take() const {
		return 10;
	}
};


class Zach : public Person {
private:
	int num;
public:
	Zach(const std::string& f, const std::string& l, int nc) : Person(f,l), num(nc) {}
	int take() const {
		return 9001;
	}
};

int phoneBook::count = 0;
int Person::count = 0;

int main() {
	phoneBook a;
	phoneBook b("Joe","Testa",923456789);
	std::cout << a;
	std::cout << b.getFirst() << std::endl;
	std::cout << phoneBook::getCount() << a.getTheCount() << std::endl;
	Person someone("Joey","DeLosa"); //can only do with virtual function. not pure virtual.
	std::cout << someone.take() << std::endl;
	Person * c[3];
	c[0] = new Sumo("Coach","Fatty", 483);
	c[1] = new Sumo("Rob","Fea",350.0);
	c[2] = new Zach("Zach","Mulhal",45);
	std::cout << (*c[0]).take() << ' ' << c[1]->take() << ' ' << c[2]->take() << std::endl;
	std::cout << Person::getCount() << std::endl;

	delete c[0];
	delete c[1];
	delete c[2];
}