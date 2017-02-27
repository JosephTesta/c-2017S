#include <iostream>
#include "Car.hh"
#include "SportsCar.hh"
#include "Bus.hh"
using namespace std;

#if 0
//you can declare something multiple times, but only define it once.
int x; // definition
extern int x; //declaration. theres an x somewhere that is defined
extern int x;

class A {};
class A; //declaration
class A;
class A; 

#endif

int main() {
	Car c1 (100, "Red");
	Bus b(55,14);
	SportsCar s1(140, "Blue", 400.0);

	cout << c1.payToll() << '\n';
	cout << b.payToll() << '\n';
	cout << s1.payToll() << '\n';

	Vehicle* p = &c1; //Vehicle p is an error
	cout << p->payToll();
	p = &b;
	cout << p->payToll();

	Vehicle* array[2];
	array[0] = &c1;
	array[1] = &b;

	for (int i=0; i < 2; i++)
		cout << array[i]->payToll();

	//c1.drive();
	//s1.drive();
}