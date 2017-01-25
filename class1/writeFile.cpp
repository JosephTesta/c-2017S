#include <iostream>
#include <fstream>
using namespace std;

//this is not working. check his video!!

int main() {
    ofstream f("test.dat");
    f << "hello" << 5 << 2 + 3 << '\n';

    return 0;
}
