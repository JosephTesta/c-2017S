#include <iostream>
using namespace std;

int a; //a=0 automatically since outside the main function
int main() {
	int x = 2;

	int b[3]; // b[0] b[1] b[2] all values are random garbage
	int c[3] = {1,2,3};
	int d[] = {1,2,3}; //if you use curly brackets, you don't need [3]
	//dont use this #define SIZE xj?4&
	//enum { SIZE = 200}; // this is acceptable
	const int SIZE = 200; //probably best way
	int e[SIZE] = {5}; //this makes e[0]=5 and all others become 0 up to e[199]

	for (int i = 0; i < SIZE; i++)
		e[i] = 3;

	int f[2][3] = {
		{5, 4, 3},
		{2, 1, 6}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << f[i][j] << ' ';
		cout << '\n';
	}

	cout << sizeof(int) << '\n';
	cout << sizeof(char) << '\n'; //always 1 by definition
	cout << sizeof(f) << '\n'; //it has 6 elements each 4 bytes = 24
	cout << sizeof(f[0]) << '\n'; //12 bytes

	int g[2][3][4][5][6]; //720 elements
	cout << sizeof(g) << '\n'; //720*4 = 2880
}