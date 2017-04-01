#include <iostream>
//#include "Car.hh" //don't need since sports car includes car
#include "SportsCar.hh"
#include "Bus.hh"
#include "Truck.hh"
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
	Truck t(70, 18000, 5);

	cout << c1.payToll() << '\n';
	cout << b.payToll() << '\n';
	cout << s1.payToll() << '\n';
	cout << t.payToll() << '\n';

	Vehicle* p = &c1; //Vehicle p is an error
	cout << p->payToll() << '\n'; //will call Car::payToll
	p = &b;
	cout << p->payToll() << '\n';

	Vehicle* array[5]; //array of pointers
	array[0] = &c1;
	array[1] = &b;
	array[2] = &b;
	array[3] = &t;
	array[4] = &s1;
	//this way has to make run time decisions and check

	for (int i=0; i < 2; i++)
		cout << array[i]->payToll() << endl;

	//c1.drive();
	//s1.drive();
}