#include <iostream>
using namespace std;
//Explaining the HW problem
int main() {
   // sum1 = 1/1 + 1/2 + .. + 1/100 ~ 5.18
    //sum2 = 1/100 + .. + 1/1 ~ 5.18

    /*
     * 1.96
     * .0987
     * .00995
     * ===================
     * 1.96
     * .0987
     * ====================
     * 2.05
     * .00995
     * 2.05
     *
     * .0987
     * .00995
     * ==================
     * .1086
     * 1.96
     * ====================
     * 2.06
     *
     *
     * adding up the smaller terms with themselves is more accurate --> 1/100 + ... + 1/1 is more accurate
     *
     *
     */

    for (int i = 100; i > 2; i/=2+1) // 100
        if (i % 2 ==0)
            cout << i << endl;

    float a = 70.0001;
    float b = 70.0000;
    cout << a-b << endl;
    bool c = true;
    cout << false << c << endl;
    float d = 70.0001;
    cout << d << endl;
}
