class Complex {
private:
	double r, i;
	static int count; // --> extern. im decalring it, but someone else is defining it
public:
	static int getCount() {
		return count;
	}
};

int Complex::count = 0;


class A { //size 1 byte
};

class B : public A {
private:
	int x; // 4 bytes
	B() {} 
protected:
	int y; //4
	void f() {}
public:
	int z; //4
}

sizeof(A);