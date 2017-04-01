#ifndef STRING_HH_
#define STRING_HH_
#include <iostream>
#include <cstdint>

class String {
private:	//order actually matters. the constructor will assign p before len and capacity.
	char* p; // --> "kgjserkj kfjrsdfkj kfskrufe\0" \0 is a hidden null character
	std::uint32_t len;
  std::uint32_t capacity;
public:
	String(const char s[]);

	String(int initialCapacity, char c);

	String() : p(nullptr), len(0), capacity(0) {}
	//old way was NULL, or 0. reccommended using nullptr

	//you must set the pointer equal to something in order to delete it.. either set to something with new or set to nullptr
	//can only have one destructor. multiple constructors are fine.
	~String() {
		delete [] p;
	}

	//copy constructor
	String(const String& orig);
	String& operator =(const String& orig);

	//	String(String&& orig);
	void set(int i, char c) { p[i] = c; }
	friend std::ostream& operator<<(std::ostream& s, const String& str);
};

String f();
#endif