/**
  hw7 - Matrix
  Joe Testa
*/

//g++ -std=c++11 Homework7WithThrow.cpp -o hw7



#include <iostream>
using namespace std;

class BadSize {
private:
	int linenum;
	const string filename;

public:
	BadSize(int linenum, const char filename[]) : linenum(linenum), filename(filename){} //can't just use __LINE__ here or you get this line. old fashion C pointer
	friend ostream& operator <<(ostream& s, const BadSize& e) { //not copying is a lot faster because of the string (which is a pointer)
		return s << "BadSize Error in " << e.filename << ": " << e.linenum;
	}
};

class Matrix {
private:

	double* m; //matrix data. points to a single vector of doubles. doesn't know about 2d 
	// 0 1 2 3
	// 4 5 6 7
	int rows;
	int cols;
public:

	//write constructor, destructor, copy constructor, operator =, 

	//Constructor. defaults to 0 in all rows and cols
	Matrix(int rows, int cols, double value = 0) : rows(rows), cols(cols) {
		int length = rows*cols;
		m = new double[length];
		//cout << m << endl; //print the memory location
		for(int i = 0; i < length; i++) {
			m[i] = value;
			//cout << m[i] << endl; //print the value being stored
		}
	}

	//Desctructor. Get memory back
	~Matrix() {
		delete [] m;
	}


	//Copy constructor. works for Matrix m3 = m4 and Matrix m3(m4)
	Matrix(const Matrix& orig) : m(new double[orig.rows*orig.cols]), rows(orig.rows), cols(orig.cols) {
		for(int i = 0; i < orig.rows*orig.cols; i++)
			m[i] = orig.m[i];
	}


	//printing a matrix
	friend ostream& operator <<(ostream& s, const Matrix& myMatrix) {
		for(int i = 0; i < myMatrix.rows; i++) {
			for(int j = 0; j < myMatrix.cols; j++) {
				s << myMatrix.m[myMatrix.cols*i+j] << ' ';
			}
			s << endl;
		}
		return s;
	}


	//this is for doing m1(0,1) in order to return the double stored in row 0 col 1 of m1
	double operator ()(int i, int j) const {//can take as many parameters as we watn since functions can do that with parentheses
		return m[i*this->cols + j];
	}

	
	double& operator ()(int i, int j) { //this is for doing stuff like m1(0,1) = 5.5
		return m[i*this->cols + j];
	}
	

	//Move constructor
	//don't have to know this. only to be faster. NEED IT FOR TEST THOUGH
	Matrix(Matrix&& orig) { //suppose you have an object which is about to die (like returning Matrix in the operator +)
		m = orig.m;
		rows = orig.rows;
		cols = orig.cols;
		orig.m = nullptr;
	}
	


	//adding matrices into a new matrix
	friend Matrix operator +(const Matrix& a, const Matrix& b) throw(BadSize) {
		//test if they are equal in size
		if(a.rows == b.rows && a.cols == b.cols) {
			Matrix ans(a.rows,a.cols,a.m[0]+b.m[0]);
			for(int i = 0; i < a.rows*a.cols; i++)
				ans.m[i] = a.m[i]+b.m[i];
			return ans;//can't return by reference since you're pointing to something that doesn't exist. so we use friend MAtrix instead of Matrix&
		}
		else {
			throw BadSize(__LINE__,__FILE__);
			//return Matrix(0,0);
		}
	}

	Matrix& operator =(const Matrix& orig) {
		if(this != &orig) {
			delete [] m; 
			m = new double[orig.rows*orig.cols];
			rows = orig.rows;
			cols = orig.cols;
			for(int i = 0; i < orig.rows*orig.cols; i++)
				m[i] = orig.m[i];
		}
		return *this;
	}

};



int main() throw(BadSize) {
	#if 0 //my testing stuff. ignore this
	//write a copy constructor regardless if it seems to be needed
	//need construc, destr, copy construc, operator =, operator << 
	Matrix m1(3, 4); // all zeros
	Matrix m2(2,3,1.5); // fill with 1.5
	cout << m1 << '\n';
	cout << m2 << '\n';
	/* 
	0	0	0	0
	0	0	0	0
	0	0	0	0
	*/
	cout << m1(0, 1) << '\n'; //look at row 0 col 1 and print the number
	m1(0,1) = 5.5; //now we need to do something else
	cout << m1(0,1) << endl;
	Matrix m3 = m1 + m1; //matrix addition
	Matrix m8 = m1 + m2;
	cout << m3 << endl;
	cout << m8 << endl;
	Matrix m4 = m3; // copy constructor. Matrix m4(m3)
	cout << m4 << '\n';
	m4(1,2) = 11.2; 
	m3 = m4; //operator =
	cout << m3 << endl;
	#endif
	Matrix m1(3, 4); // zeros
	Matrix m2(2, 3, 1.5); // fill with 1.5
  	cout << m1 << '\n';
	/*
		0   0   0   0
    0   0   0   0
    0   0   0   0
	*/
	cout << m1(0, 1) << '\n';
	m1(0,1) = 5.5;
	

	#if 1
	try {
		Matrix m3 = m1 + m2;
	}
		catch(const BadSize& e) {
		cout << e << '\n';
	}
	#endif
	//Matrix m3 = m1 + m2;

	Matrix m4 = m1;  //copy constructor
	cout << m4 << '\n';
	m4(1,2) = 11.2;
	//m3 = m4; // operator =
}