//see his notes for how to use a private copy function to avoid rewritting a lot during the operator =

template<typename T>
class List {
private:
	//this is a bad implementation. we did better for growArray
	unsigned int capacity;
	T* data;

public:
	List() : capacity(0), data(nullptr) {
	}

	~List() {
		delete [] data;
	}

	void add(const T& v) {
		T* temp = data;
		data = new T[capacity+1];
		for (int i = 0; i < capacity; i++) {
			data[i] = temp[i];
		}
		data[capacity++] = v; //set new value and increment the capacity size
		delete [] temp;
	}

	//copy constructor
	List(const List& orig) : capacity(orig.capacity), data(new T[capacity]) {
		for (int i = 0; i < capacity; i++) {
			data[i] = orig.data[i]; //needs operator = to work for that type T. such as elephants
		}
	}

	//operator =
	List& operator =(const List& orig) {
		if (this != &orig) {
			delete [] data;
			capacity = orig.capacity;
			data = new T[capacity];
			for (int i = 0; i < capacity; i++) {
				data[i] = orig.data[i];
			}
			return *this;
		}
	}

};


int main() {
	List<int> a;
	List<int> b;
	a = b; //works with operator = void or List&
	List<int> c;
	a = b = c; // only works if operator = returns List& rather than void
	List<Elephant> d;
	d.add()
}