// Car is the base class,
// AKA parent
//He changed a lot of stuff at end of class for this. We will also go over 

class Vehicle { //abstract class. one level remove from a class. there's no shuch thing as a vehicle. it's what cars and Busses have in common

}

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
	SportsCar(int s, const string& c, double h) : Car(s, c) ,horsePower(h) {}
};

class Bus : {
private:
	int speed;
public:
	Vehicle(int s) : speed(s) {}

};

int main() {
	Car c1 ("Red",100); //color and speed
	SportsCar s1("Blue",140,400.0);
	Bus b(55, 14); //speed and number of pasengers
	c1.drive();
	s1.drive();



	return 0;
}