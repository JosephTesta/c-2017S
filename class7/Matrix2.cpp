class Matrix {
private:

	double* m; //matrix data. points to a single vector of doubles. doesn't know about 2d 
	// 0 1 2 3
	// 4 5 6 7

public:
	//write constructor, destructor, copy constructor, operator =, 
	Matrix(int rows, int cols) : {

	}

	double operator ()(int i, int j) const {//can take as many parameters as we watn since functions can do that with parentheses
		return m[   ];
	}

	double& operator ()(int i, int j) { //this is for doing stuff like m1(0,1) = 5.5
		return m[   ];
	}

	//Move constructor
	//don't have to know this. only to be faster. NEED IT FOR TEST THOUGH
	Matrix(Matrix&& orig) { //suppose you have an object which is about to die (like returning Matrix in the operator +)
		m = orig.m;
		rows = orig.rows;
		cols = orig.cols;
		orig.m = nullptr;
	}
	friend Matrix operator +(const Matrix& a, const Matrix& b) {
		//test if they are equal in size
		Matrix ans(...);
		return ans;//can't return by reference since you're pointing to something that doesn't exist. so we use friend MAtrix instead of Matrix&

	}
};



int main() {
	//write a copy constructor regardless if it seems to be needed
	//need construc, destr, copy construc, operator =, operator << 
	Matrix m1(3, 4); // all zeros
	Matrix m2(2,3,1.5) // fill with 1.5
	cout << m1 << '\n'
	/* 
	0	0	0	0
	0	0	0	0
	0	0	0	0
	*/
	cout << m1(0, 1) << '\n'; //look at row 0 col 1 and print the number
	m1(0,1) = 5.5; //now we need to do something else
	Matrix m3 = m1 + m1; //matrix addition
	Matrix m4 = m3;
	cout << m4 << '\n';
	m4(1,2) = 11.2; 
	m3 = m4; //operator =
}