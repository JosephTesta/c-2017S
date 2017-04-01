#include <string.h>
#include <cstdint>
using namespace std;

class mystring {
private:
	char* p;
	int size;

public:
	mystring(uint64_t size, char x) throw (bad_alloc) : size(size){
	//you have to countthe size
	//size = strlen(s);

	p = new char[size]; //throw bad_alloc for ran out of space

	for (uint_64_t i = 0; i < size; i ++{
		p[i] = x;
	}

	~mystring() {
		delete [] p;
	}
}
};