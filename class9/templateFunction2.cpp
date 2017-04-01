//int*const p = ...; //this is what an array is

//bubble sort
// 8 7 6 5 4 3 2 1
// 7 6 5 4 3 2 1 8
#include <iostream>
using namespace std;

template<typename T>
void sort(T* const items, int n) { //subtle difference between int items[] and int* items. the array method is a constant. can only point to 1 spot. int* const items works like an array
	for (int j = 0; j < n-1; j++){
		for (int i = 0; i < n-1; i++) {
			if (items[i] > items[i+1]) {
				T temp = items[i];
				items[i] = items[i+1];
				items[i+1] = temp;


				#if 0
				//5, 6 for example
				//swap 2 variables without a temp 
				items[i] = items[i] + items[i+1]; //11
				items[i+1] = items[i] - items[i+1]; //11-6 = 5
				items[i] = items[i] - items[i+1]; 11-5 = 6
				#endif

			}
		}
	}
}

template<typename T, typename Key>
void sort(T* const items, int n, Key T::*key) { //relative pointer. key is a pointer to members to T that are of type Key
	for (int j = 0; j < n-1; j++){
		for (int i = 0; i < n-1; i++) {
			if (items[i].*key > items[i+1]) {
				T temp = items[i];
				items[i] = items[i+1];
				items[i+1] = temp;

			}
		}
	}
}

template<typename T>
void print(T a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

class Person {
public:
	string name;
	int age;
	double height;
	Person(const string& name, int age) : name(name), age(age) {}


};


int main() {
	int a[] = {3,2,1};
	sort(a,3);
	print(a,3);

	int b[] = {5,2,4,1,6};
	sort(b, sizeof(b)/sizeof(int));
	print (b,sizeof(b)/sizeof(b[0]));

	float c[] = {1.5, 2.5, 0.5};
	sort(c,3);
	print(c,3);

	string s[] = {"yoho" , "bye", "Test", "food"};
	sort(s,4);
	print(s,4);

	Person p[] = { Person("Dov",50), Person("Dillon", 20), Person("Moshe",15) };
	sort(p,3, &Person::name);
	sort(p,3, &Person::age);

	//print(p,3, &Person::name); //next time

}