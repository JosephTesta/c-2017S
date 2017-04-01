#include <iostream>
using namespace std;
class A {};

class B {
private:
  int num, den;
};

// 0 1 2 3 4 5 6 7
// 8 9 10 11 12 13 14 15
class C {
private:
  char a;
  int num;
};

class D {
private:
  char a;    //1
  int num;   //4
  short int x; //2
  int y;     //4
  char z;    //1
};

class E {
private:
  char a;    //1
  char z;    //1
  short int x; //2
  int num;   //4
  int y;     //4
};

class F {
private:
  char c;
  double x;
  char d;
};

int main() {
  A a1;
  cout << sizeof(A) << ' ' << sizeof a1 << '\n';
  cout << sizeof(B) << '\n';
  cout << sizeof(C) << '\n';
  cout << sizeof(D) << '\n';
  cout << sizeof(E) << '\n';
  E e1[10];
  cout << sizeof(e1) << '\n';
  cout << sizeof(F) << '\n';
}
