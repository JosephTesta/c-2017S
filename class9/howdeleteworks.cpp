
class Elephant {
private:
	int* p; //pretend p gets allocated
public:
	Elephant() { cout << "Elephant born"; }
	~Elephant() { cout<< "Elephant about to die"; }

}

int main() {
/*
			it has a number before p saying 4 for the size
	p --> int

			400
	q --> int int int int ... 

	if you had a pointer problem that changed this number

			131749823
	q --> int int int int ....


		800
	e --> E E E E E E ..

*/


	int* p = new int;
	*p = 5;
	int* q = new int[100]
	delete [] q;

	Elephant* e = new Elephant;
	delete e;

	e = new Elephant[100]; //will call the constructor 100 times. prints Elephant born 100 times
	delete e; //sees a pointer to an elephant but doesn't know there are another 99 elephants. incorrectly deletes only the first
	
	delete [] e; //



}