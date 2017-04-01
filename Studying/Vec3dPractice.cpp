#include <iostream>
using namespace std;

class Vector3d {
private:
	double x,y,z;
public:
	Vector3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

	friend ostream& operator <<(ostream& s, Vector3d a) {
		return s << a.x << ' ' << a.y << ' ' << a.z << ' ' << endl;
	}

	friend Vector3d operator -(Vector3d a, Vector3d b) {
		return Vector3d(a.x-b.x, a.y-b.y, a.z-b.z);
	}

	friend Vector3d operator +(Vector3d a, Vector3d b) {
		return Vector3d(a.x+b.x, a.y+b.y, a.z+b.z);
	}

	friend Vector3d operator *(Vector3d a, double b) {
		return Vector3d(a.x*b, a.y*b, a.z*b);
	}

	friend double dot(Vector3d a, Vector3d b) {
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

	static double dot(Vector3d a, Vector3d b) {
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

	friend istream& operator >>(istream& s, Vector3d& a) {
		return s >> a.x >> a.y >> a.z;
	}


};


int main() {
	Vector3d v1(1.5,2.0);
	Vector3d v2 = v1 * 3;
	Vector3d v3 = v2 - v1;
	double d1 = dot(v1,v2);
	double d2 = Vector3d::dot(v1,v2);
	cout << v1 << '\n';
	cout << d1 << '\n';
	cout << d2 << '\n';
	cout << v2 << '\n';
	cout << v3 << '\n';

	cin >> v3;
	cout << v3 + v1;
}