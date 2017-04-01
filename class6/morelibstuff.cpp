#include <iostream>
#include <iomanip> //print the num of digits you want
#include <random> //this is the best random generator library to use
using namespace std;


int main() {
	mt19937 rnd(0) //always test with a random number generator seeded to a specific 
	//random numbers will always be the same in every run, which is boring
	//when code works, remove the zero and it will seed with the time. rnd;

	normal_distribution<> normal(0,1); //mean 0 var 1
	int hist[100] = {0};
	for (int i = 0; i < 400; i++) {
		double x = normal(rnd);
		//cout << x << '\t';
		//theres a lot more on random in his files
		//look at it if needed

	}
}