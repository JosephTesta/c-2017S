#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i< 10; i++)
		cout << i << ' ';
	cout << '\n';
	for (int i = 1; i >= 10; i++)
		cout << i << ' ';
	cout << '\n';
	for (int i = 3; i<= 10; i += 2)
		cout << i << ' ';
	cout << '\n';
	for (int i = 1; i< 100; i+=i)
		cout << i << ' ';
	cout << '\n';


	int a = 3;
	int b = 2;
	cout << float(b)/a << '\n';			
}
