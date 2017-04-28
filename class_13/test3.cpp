#if 0
template functions

template classes

inheritance

virtual functions

pure virtual functions (virtual f() = 0)

dynamic memory
	constructor must know
	destructor must know
	copy constructor must know
	operator = must know
	copy and swap. avoid the if statement. not required on test but appreciated
	move constructor c++11 ??? maybe on test. could be  he doesn't knwo yet


pointers (not too hard for pointers)
#endif

	int * p; pointer
	const int * q; readonly pointer
	int* const s = something; //pointer locked to one spot.
	int x[10]; //x is an int* const pointer
	const int y[10]; //y is const int* const

	x[i] ==     *(x+i) are the same thing

	p[-1] goes one before a pointer

(*p)++ //increment value at that address
*p++ //take the current value, then increment the pointer itself
++*p //preincrement the value at that address
*++p //preincrement the current value, then take that value