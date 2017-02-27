#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	vector<int> a;//this is a template
	for (int i =0; i < 10 i++)
		a.push_back(i);
	for (int i =0; i < 10 i++)
		cout << a[i] << ' ';
	cout << a << '\n';

	vector<double> b;
	//vector<Elephant> e;//if you defined what an elephant is
	for(int i = 0; i <100; i++)
		b.push_back(i+.5);


	map<string, double> prices;
	prices["AAPL"] = 137.11;
	prices["IBM"] = 181.15;

	cout << prices["AAPL"] << '\n';
	//cout << prices["X"] << "\n"; //will probably crash 

		
}
