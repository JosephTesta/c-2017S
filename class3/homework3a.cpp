#include <iostream>
using namespace std;

int main() {
	const Vec3d a(1.0, 2, 2.5); //2 means 2.0. all double (1.0, 2.0, 2.5) (x,y,z). Everything has to be const because of const Vec3d a
	cout << a << '\n';
	Vec3d b(5.0); // (5.0, 0.0, 0.0)
	Vec3d c = a + b;
	cout << c << '\n';
	Vec3d c = a.add(b); //call a method
	double d = a.dot(b); // dot product = a.x*b.x + a.y*b.y + a.z*b.z
	cout << d << '\n';

	Vec3d e = a * 2; //scalar multiplication
	Vec3d f = 2 * a; // scalar multiplication
	
}