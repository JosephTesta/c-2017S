#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream f("file.dat");
	int n;
	f >> n;
	int x[n]; //dynamically allocates memory int* x = new int[n]; ... delete [] x;

	for ...
		 f >> x[i]
}