#ifndef SPORTSCAR_HH_
#define SPORTSCAR_HH_

#include "Car.hh"

#include <string>

class SportsCar : public Car { //there are three kinds of inheritance in c++. public is most used. public says a SportsCar IS_A kind of Car
private:
	double horsePower;
public:
	SportsCar(int s, const std::string& c, double h) : Car(s, c) ,horsePower(h) {}
};

#endif