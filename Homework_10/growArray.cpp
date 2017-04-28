/**
  hw10 - GrowArray
  Joe Testa
*/

#include <iostream>
#include <cstdint>
using namespace std;

class GrowArray {
private:
	int* data;
	uint32_t used;
	uint32_t capacity;
	void grow() {
		capacity = capacity * 2 + 2;
		int* temp = data;
		data = new int[capacity];
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

	GrowArray(const GrowArray& orig)throw (bad_alloc) : data(new int[orig.used]), used(orig.used), capacity(orig.used) {
		for (int i = 0; i < used; i++)
			data[i] = orig.data[i];
		//commonly seen, not necessary
		// not necessarily more efficient
		//memcpy(data, used*sizeof(int), orig.data);
	}
	// this operator = uses "copy and swap" to deallocate the destination
	GrowArray& operator =(GrowArray copy) {
		int* temp = data; data = copy.data; copy.data = temp;
		used = copy.used;
		capacity = copy.capacity;
	}
	GrowArray(GrowArray&& orig) : data(orig.data), used(orig.used), capacity(orig.capacity) {
		orig.data = nullptr;
	}
	void add(const int& v) throw (bad_alloc) {
		if (used >= capacity)
			grow();
		data[used++] = v;
	}

	// x[i] not x [] i
	// cannot be friend!
	// this is the readonly version
	int operator [](int i) const {
		return data[i];
	}

	// this is the read/write
	int& operator [](int i) {
		return data[i];
	}	

  friend ostream& operator <<(ostream& s, const GrowArray& list) {
		for (int i = 0; i < list.used; i++)
			s << list.data[i] << ' ';
		return s;
	}
};

GrowArray f(GrowArray x) {
  x.add(1);
  return x;
}

int main() {
  GrowArray a;
  for (int i = 0; i < 10; i++)
    a.add(i);
  GrowArray b = a;
  cout << b << '\n';
  GrowArray c;
  c = a;
  cout << b << '\n';
  c = f(b);
  cout << b << '\n';
}