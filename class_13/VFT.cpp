
class A {
public:
	virtual void f() = 0; //pure virtual function. can't instantiate
	virtual void g() = 0;

};

//A a1; //no instantiating!!!!
//a1.f();

class B : public A {
public: 
	void f() {}
	void g() {}
};

B b1; // cant instantiate unless you write f()
b1.f();

A* p = &b1;
p->f(); //(*p).f star has less precedence than  . so you need parentheses. don't confuse with .*

class C : private A {
public:
	void f() {}
	void g() {}
};

//private inheritance is useless for polymorphism

C c1; 
p = &c1; //NO 
p->f();// NO