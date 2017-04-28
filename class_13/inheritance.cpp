//c++ specific it is called base and derived. general it is called parent and child

class Base {
private: //nobody but you sees this
	int x; //only visible to entities declared within this class. including friends
protected:
	int y; //visible to this class and all children
public:
	int z; // visible to everybody


};

//design rule: data should always be private
//you can't say who your children are. the children decide who their parents are
//make any methods private that you dont need to be public. be stingy

class Derived : public Base {

	//what was private in the base is ..?? invisible to you
	//what was protected in the base is ..?? protected to me
	//what was public in the base is
};

class Myclass : public Yourclass {

};

class Airplane {
private:
	double fuel;
protected:
	double getFuel() const {
		return fuel;
	}
public:
	void fly();
};

class FighterPlane : public Airplane {

};


FighterPlane p;
p.fly();


class Engine {

};

class Car : private Engine{ //everything I can see in engine is now private. kind of useless

};

class Car { //this is better 
private:
	Engine e;
};

class Derived : protected Base { //what was private is invisible. what was protected  or puvlic is protected
};

//instead
class Derived {
protected:
	Base b;
};


class Chicken {
public:
	nutrition();
};
class Beef {
public:
	nutrition();
};
class Shrimp {
public:
	nutrition();
};

class Mushu{
public:
	void flavor();
};
class Garlic{
public:
	void flavor();
};

class MushuChicken : public Chicken, public Mushu { //this case works, but in general it doesnt always

};
//you can't have the same function or the same variable 

class Employee {
private:
	long ssn;
public:
	pay();
};

class Secretary : public Employee  {
public:
	void f();
};

class Professor : public Employee  {
public:
	void teach();
};

class Temp : public Employee {
public:
	Temp(long ssn, Date exp) {}
};

//just dont do this
class VisitingProfessor : public Temp, public Professor {

}

//you have to do something with virtual