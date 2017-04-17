#include <iostream>
#include <cstdint>
using namespace std;


#if 0
char* the_string : I can change the char to which the_string points, and I can modify the char at which it points.

const char* the_string : I can change the char to which the_string points, but I cannot modify the char at which it points.

char* const the_string : I cannot change the char to which the_string points, but I can modify the char at which it points.

const char* const the_string : I cannot change the char to which the_string points, nor can I modify the char at which it points.
#endif

class String {
private:	
	char* p;
	uint32_t len;
  uint32_t capacity;
public:
	String(const char s[]) {
		int count;
    for (count = 0; s[count] != '\0'; ++count)
			;
		p = new char[count];
		for (int i = 0; i < count; ++i)
			p[i] = s[i];
		len = count;
		capacity = count;
	}
	String() : p(nullptr), len(0), capacity(0) {}
	~String() {
		delete [] p;
	}

	String(const String& orig) : p(new char[orig.capacity]), len(orig.len), capacity(orig.capacity) {
		for (int i = 0; i < len; ++i)
			p[i] = orig.p[i];
	}


	String& operator =(const String& orig) {
    if (this != &orig) {
			delete [] p;
			p = new char[orig.capacity];
			len = orig.len;
			capacity = orig.capacity;
			for (int i = 0; i < len; ++i)
				p[i] = orig.p[i];
		}
	  return *this;	
	}
	
	void set(int i, char c) { p[i] = c; }

	friend ostream& operator<<(ostream& s, const String& str) {
    for (int i = 0; i < str.len; ++i)
			s << str.p[i];
		return s;
	}
};

int main() {
	String s1("This is a test");
	String s2;
	cout << s1 << "\n";

	String s3 = s1;
	String s4 (s1);
	s1.set(0, 'x');
	cout << s1 << endl; //changed
	cout << s3 << endl; //unchanged
	cout << s4 << endl; //unchanged

	String s5("Yoho!");
	cout << s5 << endl;
	s3 = s5;
	s3 = s3;
	s2 = s3 = s4;

	int x = 2;
	int y = 3;
	int z = 4;


}