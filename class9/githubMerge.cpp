//file 1
class A {
	A() {}
};



////////////////////////
//file 2

class A {
public:
	A(int x) {}

}


////////////////////////
//after you pull. you can edit it out and put both constructors, then delete the < and = signs
//pretty much use a text editor affter pulling and decide what stays and what goes

class A {
public:
<<<<<<<<<<<<<<<<<<<<<<<
	A() {}
=======================
	A(int x) {}
};