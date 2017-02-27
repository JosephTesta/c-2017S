class Bitmap {
private:
	int m[1024][1024]; //if you copy one of these instead of by reference it's a lot slower
public:
	friend operator +(const Bitmap& a, const Bitmap& b) { //pass by reference speeds this up a lot compared to by value

	}


};