//int*const p = ...; //this is what an array is

//bubble sort
// 8 7 6 5 4 3 2 1
// 7 6 5 4 3 2 1 8
#include <iostream>
using namespace std;


void sort(int* const items, int n) { //subtle difference between int items[] and int* items. the array method is a constant. can only point to 1 spot. int* const items works like an array
	for (int j = 0; j < n-1; j++){
		for (int i = 0; i < n-1; i++) {
			if (items[i] > items[i+1]) {
				int temp = items[i];
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
}v

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
	int a[] = {3,2,1};
	sort(a,3);
	print(a,3);

	int b[] = {5,2,4,1,6};
	sort(b, sizeof(b)/sizeof(int));
	print (b,sizeof(b)/sizeof(b[0]));
}