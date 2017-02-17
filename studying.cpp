#include <iostream>
using namespace std;

class A {
private:
	int x;	
public:
	A(int x) : x(x) { cout << "created" << endl;}
	~A() { cout << "DED" << endl;}
};

void f() {
	A a1(2);
}

int main() {
	cout << "here" << endl;
	A a1(5);
	cout << "now here" << endl;
	f();
	//cout << "random stuff" << endl;

}