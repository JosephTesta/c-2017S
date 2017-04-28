#include <iostream>
#include <string>
using namespace std;


//swap is already in the library

template<typename T>
void ourSwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

#if 0
template<typename T>
void sort(T x[], int n) {
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1; i++) 
			if (x[i]  > x[i+1]) {
				swap(x[i],x[i+1]);
				//T temp = x[i];
				//x[i] = x[i+1];
				//x[i+1] = temp;
			}
	}
}
#endif


template<typename T, typename Key>
void sort(T x[], Key T::*key ,int n) { //key is a pointer to
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1; i++) 
			if (x[i].*key  > x[i+1].*key) {
				swap(x[i],x[i+1]);
				//T temp = x[i];
				//x[i] = x[i+1];
				//x[i+1] = temp;
			}
	}
}

template<typename T>
void print( T x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

class Person {
public:
	string firstName;
	string lastName;
	int age;
public:
	Person(const string& fname, const string& lname, int age) : firstName(fname), lastName(lname), age(age) {

	}
	#if 0 
	friend bool operator >(const Person& p1, const PErson& p2) {
		return p1.firstName > p2.firstName;
	}
	#endif
};

int main() {
	int a[] = {5,1,2,4,3};
	const int n = sizeof(a) / sizeof(int);
	sort(a, n);
	print(a, n);
	string b[] = {"def", "a", "yoho", "testing"};
	sort(b,4);
	print(b,4);

	Person people[] {
		Person("Dov","Kruger",50),
		Person("Moshe","Kruger",15),
		Person("Ellen","Buxbaum",40)
	};

	Person people2[] {
		{"Dov","Kruger",50},
		{"Moshe","Kruger",15},
		{"Ellen","Buxbaum",40}
	};

	sort(people, &Person::age, 3);
	
	sort(people, &Person::firstName, 3);
}