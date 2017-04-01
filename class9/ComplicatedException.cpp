#include <new>
using namespace std;


class ComplicatedException {
private:
	int* a;
	int* b;
public:
	ComplicatedException() {

		a = new int[100];
		try {
			b = new int[1000000000000000000000000000LL];
		} catch (bad_alloc e) {
			delete [] a; //delete a if it is partially built
			throw ;//rethrows the error you got
		}

	}
	~ComplicatedException() {
		delete [] a;
		delete [] b;
	}
};