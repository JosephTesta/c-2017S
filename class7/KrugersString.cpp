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
	s2 = s2 = s5;
	cout << s2 << endl;

	int x = 2;
	int y = 3;
	int z = 4;
}

#if 0
//my attempt at templating it. seems to work fine

template<typename T>
class String {
private:
	int capacity;
	int len;
	T* p;
public:
	String() : capacity(0), len(0), p(nullptr){
	}

	String(const T a[]) {
		int i = 0;
		for (i; a[i]!= '\0';i++) {
		}
		len = i;
		capacity = i;
		p = new T[capacity];
		for (int j = 0; j < capacity; j++){
			p[j] = a[j];
		}
	}

	~String() {
		delete [] p;
	}

	String(const String& orig) : capacity(orig.capacity), len(orig.len), p(new T[len]) {
		for(int i = 0; i <len;i++)
			p[i] = orig.p[i];
	}

	String& operator =(const String& orig) {
		if(this != &orig) {
			delete [] p;
			len = orig.len;
			capacity = orig.capacity;
			p = new T[len];
			for(int i = 0; i <len;i++)
				p[i] = orig.p[i];
		}
			return *this;
	}

	void set(int x, T a) {
		p[x] = a;
	}

	friend ostream& operator <<(ostream& s, const String<T>& a) {
		for(int i = 0 ; i < a.len; i++)
			s << a.p[i];
		return s;
	}

};

int main() {
	String<char> s1("This is a test");
	String<char> s2;
	cout << s1 << "\n";

	String<char> s3 = s1;
	String<char> s4 (s1);
	s1.set(0, 'x');
	cout << s1 << endl; //changed
	cout << s3 << endl; //unchanged
	cout << s4 << endl; //unchanged

	String<char> s5("Yoho!");
	cout << s5 << endl;
	s3 = s5;
	s3 = s3;
	s2 = s3 = s4;
	s2 = s2 = s5;
	cout << s2 << endl;

	int x = 2;
	int y = 3;
	int z = 4;
}

#endif