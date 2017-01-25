
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//input 3 numbers and it echoes them back
int main() {
	string line;
	double x,y,z;
	while (!cin.eof()) {
		getline(cin, line);
    istringstream thisline(line);
		thisline >> x >> y >> z;
		cout << x << "," << y << "," << z << '\n';
	}
  return 0;
}