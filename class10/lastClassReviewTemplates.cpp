#include <iostream>
#include <string>
using namespace std;

#if 0
int add(int a, int b) {
	return a+b;
}
#endif

template<typename T>
T add(T a, T b) {
	return a + b;
}

int main() {
	cout << add(5.4,4.4) << '\n';
	cout << add(5,4) << '\n';
	//cout << add("5","4") << '\n'; //ILLEGAL can't add two pointers to characters
	const string s = "5", s2 = "6";
	cout << add(s1,s2) << '\n'
	//cout << add(5.5,4) << '\n'; //it doesn't really like this. use the same type
	//cout << add(4,5.4) << '\n';

}