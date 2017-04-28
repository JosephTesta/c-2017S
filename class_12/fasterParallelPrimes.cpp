#include <future>
//g++ -std=c++11 -pthread fasterParallelPrimes.cpp -o faster
#include <iostream>
#include <thread>
#include <unistd.h> //for sleep
#include <cmath>
using namespace std;
//count primes up to n = 1,000,000,000



bool isPrime(long long n) {
	for (long long i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return false;
	return true;
}

void countPrimes(promise<int> && p, long long min, long long max)  {
	int count = 0;
	for ( long long i = min; i < max; i += 2) {
		if (isPrime(i))
			count++;
	}
}

void parallelPrimes(long long n) {
	long long unitOfWork = n / 10;
	long long count = 1;
	for (long long i = 3; i < n; i += 2*unitOfWork) {
		promise<int> p; //set up a promise where we will store the answer
		promise<int> p2;
		auto f = p.get_future();
		auto f = p2.get_future();
		thread t1(countPrimes,p,i,i+unitOfWork);
		thread t1(countPrimes,p2,i,i+2*unitOfWork);
		t1.join();
		t2.join();
		count += f.get();
		count += f2.get();
	}
}

int main() {
	
	cout << countPrimesParallel(10) << '\n';
}
