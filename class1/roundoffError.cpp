#include <iostream>
using namespace std;
//roundoff error stuff

int main() {
    for(int i = 1; i<= 10; i++) {
        cout << i;
    }
    cout << '\n';
    for (float x = 0.0; x <= 10.0f; x += 0.1f) //there is roundoff error. floating point is 32 bits
        cout << x << ' ';
    cout << '\n';

    double x;//x is visible outside the loop

    for (x = 0.0; x <= 10000000.0; x += 0.1) { //float only keeps track of 7 digits x + y != x. He messed this up too. changed to double
        }
    cout << x << '\n';


    /*
       1/2 = 0.5
       1/4 = 0.25
       1/10 = 0.1
       1/3 = 0.3333333

       for a computer, sotring in base 2 2^-1, 2^-2, 2^-3, 1/2, 1/4, 1/8, ....
       1/10 = 1/16 + 1/64 + 1/256 + ...
       in binary, 1/10 = 0.0001010101010101010101010101010.... It is a repeating fraction in binary
     */

}
