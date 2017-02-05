#include <iostream>
#include <fstream>
using namespace std;

double mean(int a[], int n) {
	double average = 0;
	for(int i = 0; i < n; i++) {
		average += a[i];
	}
	average /= n;
	return average;
}

void stats(int a[], int n, double& mean, double& var) {
	//this could return a mean and variance
}

void stats(int a[], int n, double& mean, double& var, double& min, double& max) {
	//this could return a mean and variance min and max
}


//given alternation x and y points. n is number of plotted points so we would use 2n
void box(double xy[], int n, double& xMin, double& xMax, double& yMin, double& yMax) {

}

int main() {
	ifstream myFile("2f.dat");
    int size = 0;

    if(!myFile) {
		cout << "While opening a file an error is encountered" << endl;
    }

    else {
    	//sucessfully opened file
    }

    while(!myFile.eof()) {
    	int a = 0;
		myFile >> a;
		size = a;
		int myArray[size];
		int i = 0;
		while(!myFile.eof()) {
			myFile >> a;
			myArray[i] = a;
			i++;
    	}
    	cout << mean(myArray,size) << endl;
    }



	return 0;
}