
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

    if(!stream1) {
		cout << "While opening a file an error is encountered" << endl;
    }

    else {
                cout << "File is successfully opened" << endl;
    }

    while(!stream1.eof()) {
		stream1 >> a;
		cout << a << endl;
    }
  return 0;
}