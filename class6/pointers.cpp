#include <iostream>
using namespace std;

int a = 1; //will be lower in memory
int main() {
	int a = 1;
	const int b = 2; //read backwards b is an integer which is const
	int * c; //c is a pointer to an integer
	cout << &a << '\n'; //this will print the hex number of where a is in memory
	cout << & ::a << '\n'; //lower memory location
	c = &a; // c points to the address of a
	//now tell me what c is pointing at
	cout << *c << endl; // prints the value in the lcoation that c points to
	cout << c << endl; //prints the physical memory location that c is a pointer to
	//long int x = 1;
	//c = (int*)x; //these arent the same size and it will be pointing to memory location 1, which is probably inaccessible. will cause crash
	//cout << *c << '\n';

	cout << '\n' << '\n' << endl;
	int d[5] = {1, 2, 3}; 
	c = &d[0]; //address of first element. c = d is also going to point to first element. addray is a pointer to first element;
	cout << *c << endl; // prints the value in the location that c points to
		cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
	*c++ = 5; //first use c then increment it. ++c is incr then use
		cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
	//wrote 5 to d[0] now c is pointing to d[1]
	cout << ++*c << endl; // d[1] is now 3. the ++ here does not apply to the pointer, rather what it's pointing to
		cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
	*++c = 4; // first increment c, so c now points to d[2] which is the number 3. then change that value to d[2] = 4
		cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
	cout << (*c)++ << endl; //first print out d[2] which is 4, then add 1 to the 4 making it 5
		cout << d[0] << ' ' << d[1] << ' ' << d[2] << endl;

	//Memorize this, quiz on it next week. is that in class or online??

}