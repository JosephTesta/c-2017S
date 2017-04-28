//g++ -std=c++11 -pthread multithreading.cpp -o multithreading
#include <iostream>
#include <thread>
#include <unistd.h> //for sleep
using namespace std;


void f() {
	for (;;) {
		cout << "hello" << flush;
		sleep(1);//slow it down so it doesn't fill up the screen
	}
}

void g() {
	for (;;) {
		cout << "bye" << flush;
		sleep(2);
	}
}

int main() {
	thread t1(f); //executes in the background
	thread t2(g);
	t1.join(); //wait until it finished
	t2.join(); //they're never  going to end, so it will keep going
}
