#include <iostream>
#include <iomanip>
#include <vector> //list
#include <map>
#include <random>
#include <algorithm> //for next_permutation
#include <string> 

using namespace std;


int main() {
	double d = 5.5 + 2.75;
	cout << d << '\n';
	//setprecision and setw are  iomanip 
	//cout << fixed << setprecision(15) << d << '\n';
	cout << setw(10) << setprecision(8) << d << '\n';

	//vector is a template. part of include <vector>
	vector<int> a;
	for (int i = 0; i < 10; i++) //fill with 0 to 9
		a.push_back(i);
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';//if you go out of bounds, you will crash. there is another way to 
	cout << endl;
	auto x = 5; //this is pointless since x will automatically be int 
	auto y = 5.2; //useless sinsce y will automatically be double
	for (auto z : a) //c++ 11 feature. works for 
		cout << z; 
	cout << endl;
	for (auto& z : a)
		z *= 2;

	for (auto z : a) //c++ 11 feature. works for any type
		cout << z; 
	cout << endl;	

	int perm[] = {1, 2, 3, 4};
	do {
		for (auto p : perm)
			cout << p << ' ';
		cout << '\n';
	} while (std::next_permutation(&perm[0], &perm[4])); // pass the perm start location and the end location which is perm + 4


	//string s = "123 9876 12345";
	//istringstream f(s);
	//int r,s,t;
	//f >> r >> s >> t;

}