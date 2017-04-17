#include "Vector3.hh"

int main() {
	Vector3<double> v1(1,2,3);
	Vector3<double> v2(1.5,2);
	Vector3<double> v3 = v1+v2;
	std::cout << v3;
}


//he couldn't get separate compilation to work