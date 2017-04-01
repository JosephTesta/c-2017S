#include <iostream>

class Array {
private:
	int anArray[3];
	static int count;

public:
	Array(int x = 0, int y = 0, int z = 0) {
		anArray[0] = x;
		anArray[1] = y;
		anArray[2] = z;
		count++;
	}

	~Array() {
		count--;
	}

	static int getCount() {
		return count;
	}

	int getMemberCount() const{
		return count;
	}

	int getX() const{
		return anArray[0];
	}

	int getY() const{
		return anArray[1];
	}

	int getZ() const{
		return anArray[2];
	}

	friend Array operator +(const Array& a, const Array& b) {
		return Array(a.anArray[0]+b.anArray[0],a.anArray[1]+b.anArray[1],a.anArray[2]+b.anArray[2]);
	}

	friend std::ostream& operator <<(std::ostream& s, const Array& a) {
		return s << "(" << a.anArray[0] << "," << a.anArray[1] << "," << a.anArray[2] << ")";
	}

	friend Array operator -(const Array& a) {
		return Array(-a.anArray[0],-a.anArray[1],-a.anArray[2]);

	}
};

int Array::count = 0;



int main() {

	Array a = Array(2,4);
	Array b(1,2,3);
	std::cout << a.getX() << a.getY() << a.getZ() << std::endl;
	std::cout << b.getX() << b.getY() << b.getZ() << std::endl;
	std::cout << a << b << std::endl;
	Array c = a + b;
	Array d = -c;
	std::cout << c << d << a.getX() << std::endl;
	std::cout << a.getMemberCount() << Array::getCount() << a.getCount() << std::endl;
}