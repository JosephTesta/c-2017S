class Engine {
private:
	double hp;
public:
	Engine(double hp) : hp(hp) {}


};

class Tire {
private:
	int p;
public:
	Tire(int p) : p(p) {}
};

class Car : public Engine { //fails english test. a car is an engine. not really true


}

//Question: is it always true (temporal)
//Question: is it one to 1? 1:1


class Car { //this doesn't really work either

	friend Engine;

};


//you have to do this



class Car {
private:
	Engine e;
	string model;
	string color;
	Tire w1,w2,w3,w4;
public:
	Car(const string& model, double hp) : e(hp), model(model), color("red"), w1(28), w2(28), w3(30), w4(30) {}

}

//be prepared that the order of these things depends on the order in memory. Engine is first, then model, then color, then Tire. The initiliazer list order is irrelevant



//////////////////////////////////////////////////////////////
//////Problem 2: software modeling organ ownership and donors
//////////////////////////////////////////////////////////////


class Heart {
public:
	Heart() {}
};

class Kidney {
public:
	Kidney() {}
};

class Person { //you can only inherit once. so you could technically make Heart a parent. You aren't your heart, so this isn't the best way
private:
	Heart* heart;
	Kidney* k1; //can't write Kidney* k1,k2; You can write Kidney *k1, *k2; 
	Kidney* k2;
public:
	Person() {
		heart = new Heart();
		k1 = new Kidney();
		k2 = new Kidney();
	}
	~Person() {
		delete heart;
		delete k1;
		delete k2;
	}

	Person(const Person& orig); //becasue the default behavior is to let you copy, we can just not fully write a copy constructor, so a copy is impossible. no cloning humans
	operator=(const Person& orig); // we don't want an operator = either, so declare it, but don't define it. This removes teh default behavior.
};

#if 0
ofstream f("test.dat");
ofstream g(f);
//you can't copy an object that represents a file, this makes no sense to do. when copying makes no sense, don't do it
#endif


class Stock {
private:
	const long long cusip; //unique number for a company's stock number
	string symbol; //name of the company can change, but number can't
public:
	Stock(const string& symbol, long long cusip) : cusip(cusip), symbol(symbol) {}

	void f() { // this doesn't work since cusip is const
		cusip = 19;
	}
};


//for n to n relationships
class Person {
	vector<Car*> owned;


};

class Car {
private:
	vector<Person*> owner;


};



//
class Person{
};

class Car {

};

//this is one to one. There is a multimap
map<Car*, Person*> personByCar;
map<Person*, Car*> carByPerson;

multimap< > 