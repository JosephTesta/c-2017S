/**
  hw3a - Vec3D
  Joe Testa

  I worked in collaboration (yet coded individually) with Robert Fea, Brian Silver, Vin Cangiarella, and John Martin
*/

#include <iostream>
using namespace std;

#if 1
class Vec3d {
private:
	double x, y, z;

public:
	Vec3d(double xNum = 0, double yNum = 0, double zNum = 0) : x(xNum), y(yNum), z(zNum) {} 

	friend ostream& operator <<(ostream& s, Vec3d someVector) {
		s << '(' << someVector.x << ", " << someVector.y << ", " << someVector.z << ")\n";
		return s;
	}

	//Why doesn't this need to be const Vec3d? how do consts work?
	/*Vec3d add(Vec3d a) const {
		Vec3d c;
		c.x = this->x + a.x;
		c.y = this->y + a.y;
		c.z = this->z + a.z;
		return c;
	}
	this works but is longer*/



	// const before everything means it returns a const
	//add(const Vec3d a) means it will only accept a const
	// add(vec3d a) const means the function doesn't edit parameters
	Vec3d add(Vec3d a) const{
		return Vec3d(this->x + a.x, this->y + a.y, this->z + a.z);
	}

	//Same question with const?
	double dot(Vec3d a) const {
		double b = 0;
		b = this->x * a.x + this->y * a.y + this->z * a.z;
		return b;
	}

	//This doesn't need const at all?
	friend Vec3d operator+(Vec3d a, Vec3d b) {
		return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	//vector times a scalar
	friend Vec3d operator*(Vec3d a, double b) {
		return Vec3d(a.x*b, a.y*b, a.z*b);
	}

	//this one is for scalar times the vector. The function is outside of the class in this case.
	friend Vec3d operator*(double a, Vec3d b);

};

Vec3d operator*(double a, Vec3d b) {
	return Vec3d(a*b.x, a*b.y, a*b.z);
}
#endif

#if 0
//Practice by redoing this hw. This way is probably better in terms of using consts when possible
class Vec3d {
private:
	double x,y,z;
public:
	Vec3d(double x = 0, double y = 0, double z = 0) : x(x),y(y),z(z) {}
	friend ostream& operator <<(ostream& s, const Vec3d& a) {
		return s << a.x << ' ' << a.y << ' ' << a.z << endl;
	}

	friend Vec3d operator +(const Vec3d& a, const Vec3d& b) {
		return Vec3d(a.x+b.x, a.y+b.y, a.z+b.z);
	}

	double dot(const Vec3d& a) const {
		return x*a.x + y*a.y + z*a.z;
	}

	Vec3d add(const Vec3d& a) const;

	Vec3d operator *(double num) const {
		Vec3d a(x*num,y*num,z*num);
		return a;
	}

	friend Vec3d operator *(double num, const Vec3d& a);

};


//you can separate out friend functions or even methods.
Vec3d operator *(double num, const Vec3d& a) {
	return Vec3d(a.x*num, a.y*num, a.z*num);
}

Vec3d Vec3d::add(const Vec3d& a) const {
	return Vec3d(a.x+x, a.y+y, a.z+z);
}


#endif

int main() {
	const Vec3d a(1.0, 2, 2.5); //(1.0, 2.0, 2.5) (x,y,z)
	cout << a << '\n';
	Vec3d b(5.0);         //(5.0, 0.0, 0.0)
	Vec3d c = a + b;
	cout << c << '\n';
	Vec3d c2 = a.add(b);   // call a method
	cout << c2 << '\n';
	double d = a.dot(b); //  dot product = a.x*b.x + a.y*b.y + a.z*b.z
	cout << d << '\n';

	Vec3d e = a * 2;   //scalar multiplication
	cout << e << '\n';
	Vec3d f = 2 * a;   //scalar multiplication
	cout << f << '\n';
}

