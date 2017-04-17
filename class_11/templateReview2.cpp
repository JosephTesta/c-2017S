//swap is a good way to avoid writting the code multiple times
//my elephant part doesn't compile. see his
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class List {
private:
	//this is a bad implementation. we did better for growArray
	unsigned int capacity;
	T* data;
	void swap(List& orig) {
		unsigned int temp = capacity;
		capacity = orig.capacity;
		orig.capacity = temp;

		T* temp2 = data;
		data = orig.data;
		orig.data = temp2;
	}
public:
	List() : capacity(0), data(nullptr) {
	}

	~List() {
		delete [] data;
	}

	void add(const T& v) {
		T* temp = data;
		data = new T[capacity+1]; //intrinsically calls T(). this is empty elephants if T is Elephant. 
		for (int i = 0; i < capacity; i++) {
			data[i] = temp[i];
		}
		data[capacity++] = v; //set new value and increment the capacity size
		delete [] temp; //calls destructor on every element. Elephant must have destructor if it allocates memory
	}

	//copy constructor
	List(const List& orig) : capacity(orig.capacity), data(new T[capacity]) {
		for (int i = 0; i < capacity; i++) {
			data[i] = orig.data[i]; //needs operator = to work for that type T. such as elephants
		}
	}

	//operator =
	List& operator =(List orig) { //change to copy instead of by reference 
		swap(orig); //orig will be deleted already since its a copy, we want it's data, but not our current data
		return *this;
	}

	friend ostream& operator <<(ostream& s, const List<T>& list) { //this works without List<T>, but it wasn't in the past
		for (int i = 0; i < list.capacity; i++)
			s << list.data[i];
		return s;
	}

};

class Elephant {
private:
	char* name;
public:
	//constructor
	Elephant() : name(nullptr) {

	}

	Elephant(const char* name) : name(new char[strlen(name)+1]) { //+1 to hold null at the end of string
		int i;
		//'\0' is ASCII NUL
		for (i = 0; name[i] != '\0'; i++) {
			this->name[i] = name[i];
		}
		this->name[i] = '\0';

	}

	//copy constructor
	// H E N R Y '\0'
	Elephant(const Elephant& orig) : name(new char[strlen(orig.name)]+1) {
		int i; //declare i before loop so you have the length for later
		for (int i = 0; orig.name[i] != '\0'; i++) {
			name[i] = orig.name[i];
		}
		name[i] = '\0';

	}

	//operator =
	Elephant& operator =(Elephant orig) { //using swap method
		swap(name,orig.name); //we use a swap from the header file here instead of making our own
		return *this;
	}


	//destructor
	~Elephant() {
		delete [] name;
	}




};

int main() {
	List<int> a;
	a.add(5);
	a.add(1);
	List<int> b;
	b = a; //works with operator = void or List&
	cout << a << '\n';
	cout << b << '\n';
	List<int> c;
	a = b = c; // only works if operator = returns List& rather than void
	List<Elephant> d;
	Elephant x("Henry");
	d.add(x);
	//cout << d << '\n'; //wont work since we didnt make an operator << for elephants
}