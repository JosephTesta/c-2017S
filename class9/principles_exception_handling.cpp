#include 'mystring'
#include <iostream>
using namespace std;

int main() throw (bad_alloc) {

	//Rule 1: dont use exceptions as some kind of weird goto break out for normal behavior
	try{
		for (int i = 0; ; i++) { //goes on forever since no second term
			if (i >= 10000){
				throw "yow!";
			}
		}
	} catch (const char* msg) {
		cout << "this is not a good way to break from a loop" << endl;

	}

	//Rule 2: Use exceptions to represent UNEXPECTED problems

	//Rule 3: Resource Allocation is initilization


	mystring s1(10000000000LL, 'q'); //ask for a ton of memory
}