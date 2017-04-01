//cleaned up version

//look at KrugerString for the properly compiling version
#include <cstdint>
#include <iostream>
using namespace std;

class String {
private: //order actually matters. the constructor will assign p before len and capacity.
	char* p; // --> "kgjserkj kfjrsdfkj kfskrufe\0" \0 is a hidden null character
	uint32_t len;
	uint32_t capacity;
public: 
	String(const char s[]) { //an array is a pointer so it is always by reference
		//constructor must count size of the string. allocate enough memory
		int count;
		for (count = 0; s[count] != '\0';++count)
			;
		p = new char[count];
		for (int i = 0; i<count;++i)
			p[i] = s[i];
		len = count;
		capacity = count;
	}
	String() : p(nullptr), len(0), capacity(0) {}
	//old way was NULL, or 0. reccommended using nullptr

	~String() {
		//you must set the pointer equal to something in order to delete it.. either set to something with new or set to nullptr
		//can only have one destructor. multiple constructors are fine.
		delete [] p;
	}

	void set(int i,char c) {p[i] = c;}

	//copy constructor
	String(const String& orig) : p(new char[orig.capacity]), len(orig.len), capacity(orig.capacity) {
		//now we copy the letters
		for (int i =0; i < len; ++i)
			p[i] = orig.p[i];

	}

	friend ostream& operator<<(ostream* s, const String& str) {
		for (int i = 0; i < str.len; ++i)
			s << str.p[i];
		return s;
	}

	String& operator =(const String& orig) { //for setting an existing object of String equal to a new value. NOT initliazing it
		if (this != &orig) //check to see if it's the same object first 
		{
		delete [] p;
		p = new char[orig.capacity];
 		len = orig.len;
 		capacity = orig.capapacity
 		for (int i = 0; i < len; ++i)
 			p[i] = orig.p[i];
 		}
 		return *this; //we can return by reference 
	}
};


int main() {

	String s1("This is a test"); //we have to count how many
	String s1;
	cout << s1 << "\n";
	String s3 = s1;
	String s4(s1);
	//String s3 = s1; //both will point to the same thing and delete the same thing(delete the same memory twice will crash)
	s1.set( 0, 'x');
	cout << s3;
	String s5("Yoho!");
	s3 = s5; //wipe out whatever was in s3 and put in it s1. give back memory, then reassign everything
	s3 = s3; //weird case we must account for. can't delete own memory first, then assign itself. be safe an account for this
	int a = 2, b = 3, c = 4;
	a = b = c = 0; // all of them become 0. we expect this to work for 
	s2 = s3 = s4; 
}
