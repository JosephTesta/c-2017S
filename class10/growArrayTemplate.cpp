#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

template<typename T>
class GrowArray {
private:
	T* data;
	uint32_t used;
	uint32_t capacity;
	void grow() { //private so the user doesn't call it
		capacity = capacity * 2 + 2; //slightly more than a factor of 2 allows it to increase from 0. 0*2 alone is still 0
		T* temp = data;
		data = new T[capacity]; // or (T*)new char[sizeof(T)*capacity] char for 1 byte. this allows us to not call the constructor a bunch of times
		for (int i = 0; i < used; i++)
			data[i] = temp[i];
		delete [] temp;
	}

public:
	GrowArray() : data(nullptr), used(0), capacity(0) {

	}

	~GrowArray() {
		delete [] data;
	}

	GrowArray(const GrowArray& orig) : data(new T[orig.used]), used(orig.used), capacity(orig.used) {
		for (int i = 0; i < used; i++) {
			data[i] = orig.data[i];
		//commonly seen, but not necessarily more efficient
		//memcpy(data,used*sizeof(int),orig.data) //but this isn't really faster anymore
		}
	}

	GrowArray& operator =(GrowArray copy) { //copy, not by reference
		T* temp = data; data = copy.data; copy.data = temp;
		//copy's destructor will be called after this operator = ends
	}

	GrowArray(GrowArray&& orig) : data(orig.data), used(orig.used), capacity(orig.capacity) { //only needed if you have a function that returns a GrowArray and you don't want to copy it
		orig.data = nullptr; //steal their memory
	}

	void add(const T& v) {
		if (used >= capacity)
			grow();
		data[used++] = v;
	}

	friend ostream& operator <<(ostream& s, const GrowArray<T>& list) {
		for (int i = 0; i < list.used; i++) {
			s << list.data[i] << ' ';
		}
		return s;
	}
};

GrowArray<int> g() { //this one will end up using the GrowArray
	GrowArray<int> a;
	for(int i = 0; i < 10; i++)
		a.add(i);
	return a;
}

int main() {
	GrowArray<int> f = g();
	GrowArray<string> a;
	a.add("abc");
	a.add("def");
	GrowArray<string> b = a; //make a new varaible b which is an exact copy of a. copy constructor
	//can alsy do below, which will allow you to change a and b will still change with it. 
	//auto b = a;
	GrowArray<string> c;
	c = a; //operator =
	cout << f << '\n';
	cout << a << '\n';
	cout << c << '\n';
	a.add("hhhhh");
	cout << c << '\n';

}