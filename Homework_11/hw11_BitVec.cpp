//g++ -std=c++11 hw11_BitVec.cpp -o hw11

#include "BitVec.hh"

#include <iostream>
using namespace std;
//BitVec<1000000> b2; //it knows at compile time. faster than dynamic memory
//Stack<256> s;
int main() {
	#if 1
	const int n = 1000000;
	BitVec b(n);

	#if 0
	for (int i = 0; i < n; i++) 
		cout << b.isSet(i);
	cout << endl;
	#endif

	for (int i = 0; i < n; i += 17)
		b.set(i);

	#if 0
	for (int i = 0; i < n; i++) 
		cout << b.isSet(i);
	cout << endl;
	#endif

	for (int i = 0; i < n; i += 19)
		b.set(i);

	#if 0
	for (int i = 0; i < n; i++) 
		cout << b.isSet(i);
	cout << endl;
	#endif
	for (int i = 0; i < n; i++)
		b.toggle(i);

	#if 0
	for (int i = 0; i < n; i++) 
		cout << b.isSet(i);
	cout << endl;
	#endif

	for (int i = 0; i < n; i++)
		if (!b.isSet(i) && i % 4 == 0 && i % 21 == 0) //if you are a multiple of 17 or 19, and 4 and 21 , so Multiples of 84
			cout << i << ' ';

	cout << '\n';
	#endif

	#if 0
	BitVec a(150);
	a.set(64);
	a.set(63);
	a.set(65);
	a.toggle(63);
	a.set(2);
	a.clear(64);
	a.toggle(64);
	a.toggle(2);

	a.isSet(0);
	a.isSet(2);
	a.isSet(64);
	a.isSet(64);
	a.isSet(124);
	a.set(124);
	a.isSet(124);
	a.isSet(63);
	a.isSet(64);
	a.isSet(65);
	#endif

}