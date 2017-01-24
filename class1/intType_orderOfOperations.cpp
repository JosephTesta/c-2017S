#include <iostream>
#include <cstdint> //C++11 feature to make data types protrable
using namespace std;

int x; //global variables are automatically binary 0. still should initalize


int main() {
    cout << "hello";
    int a = 1;
    short int b = 2; //at least 16 bits
    long c; //random junk here since not initialized variable. variables on the stack (auto) are unitialized RANDOM
    long long d;
    unsigned int e = 2;
    char f = 'x';

    //for (int32_t i = 0; i < 100000; i++)
    //        ;

    cout << 3 * 4 << '\n'; //both * and << are operators, but * is done before. \n is a new line
    cout << 3 + 4 << '\n';
    cout << 3 - 4 << '\n'; //on normal platform int is signed, but sometimes it isnt
    cout << 3 / 4 << '\n'; //integer division in c type languages has no remainder
    cout << 3 % 4 << ' ' << 4 % 4 << 5 % 4 << 6 % 4 << '\n'; //remainder
    cout << -3 % 4 << -4 % 4 << -5 % 4 << -6 % 4 << '\n';
    cout << 2 + 3 * 4 << '\n'; // order of operations 14
    cout << 2 / 3 * 3 + 1 / 2 * 2 << '\n';
    cout << 2 * 3 / 3 + 1 * 2 / 2 << '\n';



}
