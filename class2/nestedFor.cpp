#include <iostream>
using namespace std;

int main() {
	int a = 1;
	int b = 1;
	int c = a + b;
	for (int i = 0; i < 10; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	for (int i = 0; i < 3; i++) {
		//this for loop executes 3 times i = 0,1,2
		for (int j = 0; j < 2; j++) {
			cout << i << ' ' << j << '\n';
		}
	}

}

// 0 0
// 0 1
// 1 0
// 1 1
// 2 0
// 2 1