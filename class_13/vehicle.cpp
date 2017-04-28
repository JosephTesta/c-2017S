class Vehicle {

public:
	virtual double payToll() const = 0; //
	virtual ~Vehicle() = 0; //virtual destructor
};

class Car : public Vehicle