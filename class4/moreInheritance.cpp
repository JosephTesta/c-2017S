// Car is the base class,
// AKA parent

class Car {
private:
	string color;
	int speed;
protected:
	//only the children can see this
public:
	Car(const string& c, int s) : color(c), speed(s) {} //only copies once right now since const string&. string can be long
	

//we get to see private stuff. friends also can, but children can't
};




//Derived class
//AKA child
class SportsCar : public Car { //there are three kinds of inheritance in c++. public is most used. public says a SportsCar IS_A kind of Car
private:
	double horsePower;
public:
	SportsCar(const string& c, int s, double h): Car(c, s), horsePower(h) {}
};

int main() {
	Car c1 ("Red",100); //color and speed
	SportsCar s1("Blue",140,400.0);
	c1.drive();
	s1.drive();



	return 0;
}