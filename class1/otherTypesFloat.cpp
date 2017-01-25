#include <iostream>
using namespace std;
//types
int x = 0; // global variables are always init to binary 0

int main() {
    float f = 1.5f; // 1.500000 needs f
    double d = 1.5; // 1.5000000000000000000
    long double e = 1.5000000000000000000000000000000000000000000000000L; //30 or so digits. it depends, not standard. watch video
    double Na = 6.022e+23; // exponential notation of avogadro's number
    double d1 = 1 + 1.5; //left is int, right is double. Type promotion automatically takes smaller type. 1--> double(1.0)
    double d2 = 3 / 2; //both types are integer. first compute integer 3/2 (1), then convert to 1.0
    double d3 = 1.5f * 3; // left is float right is int. promote 3--> float(3.0f) -> convert to double
    //subtle quetion, does it do the arithmetic at full double precision? Don't know!

    cout << d1 << '\n' << d2 << '\n' << d3 << '\n';

}
