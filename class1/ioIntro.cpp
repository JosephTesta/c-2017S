#include <iostream>
using namespace std;

//I/O stuff

int main() {
    cout << "hello";
    cerr << "testing\n\n"; // isn't supposed to write to a file???
    int a;
    float b;
    cin >> a >> b;
    cout << a << b << '\n';
    cout << a +b << '\n';




    return 0;
    //exit(0); is another option
}
