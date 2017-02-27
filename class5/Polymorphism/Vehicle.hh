//abstract class
//header file

#ifndef VEHICLE_HH_
#define VEHICLE_HH_
//if statement to define vehicle if it hasn't been already

class Vehicle { //abstract class. one level remove from a class. there's no shuch thing as a vehicle. it's what cars and Busses have in common
private:
	int speed;
public:
	Vehicle(int s) : speed(s) {}
	int getSpeed() const {

	}
	virtual int payToll() const = 0;  //this is the default behavior for a general vehicle. it will override for a specific vehicle. all the children must implement this function
};

#endif