//#include "Vehicle.hh"
#ifndef CAR_HH_
#define CAR_HH_

#include "Vehicle.hh"
#include <string>

class Car : public Vehicle {
private:
	std::string color;
public:
	Car(int s, const std::string& c) : Vehicle(s), color(c) {} //only copies once right now since const string&. string can be long
	
	int payToll() const {
		return 12;
	}
//we get to see private stuff. friends also can, but children can't
};

#endif