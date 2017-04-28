
#include <iostream>
using namespace std;

void f() {
	cout << "hello\n";
}

void g() {
	cout << "byte\n";
}

//WRONG void *ptr();
void (*ptr)(); // ptr is pointer to function that take NO paramaters and return nothing
int main() {
	f();
	g();
	void* p = (void*)f;
	cout << p << "\n"; //the name of the function is where it is located in memory
	ptr = f;
	ptr = g;
	ptr();
}