class Matrix4 {
private:
	double m[4][4];
public:


};


//this is frowned on to do this
class VariableSizeObject {
private:
	int rows, col;
	int x[1];
public:
	VariableSizeObject(int r, int c) : rows(r), cols(c) {
		for(int i=0; i< r*c; i++)
			x[i] = 0;
	}

};

//dont do this VariableSizeObject a(50,50);

//this is how you would want to do it
new char[sizeof(VaraibleSizeObject) + rows * cols*sizeof(int)]

//stuff like this will never be on a test!