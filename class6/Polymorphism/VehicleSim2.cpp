#include <iostream>
//#include "Car.hh" //don't need since sports car includes car
#include "SportsCar.hh"
#include "Bus.hh"
#include "Truck.hh"
#include <random>

using namespace std;

//lookup random generator stuff searching for random, not rand.
class TrafficSim {
private:
	vector< Vehicle* > vehicles;
public:
	TrafficSim(int numVehicles) {
		default_random_engine generator;
		uniform_int_distribution<int> dist(0,4);

		for (int i = 0; i<numVehicles; i++) { //check his code for this
			int r = dist(generator); //now we have our random number generator from 0 to 4
			uniform_int_distribution<int> randSpeed(0,120);



			int speed = randSpeed(generator);
			Vehicle * v;
			switch(r) {
			case 0: v = new Car(speed, "red"); //don't forget about it because eventaully you have to delete 
				break; //have to break or it will continue to the next case
			case 1: v = new SportsCar(speed, "red", 400.0);
				break;
			case 2: v = new Bus(speed, 14);
				break;
			case 3: v = new Truck(speed, 18000, 5);
				break;
			//usually you can use polymorphism instead of switches
			}

			vehicles.push_back(v);
		}
	}
	
	~TrafficSim() {
		for (auto z : vehicles) {
			delete z;
		}
	}
	

	void payToll() {
		for (auto z : vehicles) {
			//(*z).payToll() is equiv to z->payToll()
			cout << z->payToll() << '\n';
		}
	}
};

int main() {
	for (int i = 0; i <10 ; i++) { //will start running out of ram if you don't deallocate memory
		TrafficSim sim1(10); //100 vehicles simulation
		sim1.payToll();
	}
		//TrafficSim sim2(100);
		//TrafficSim sim3 = sim3;
		//calls the destructor of sim2...calls the destructor of sim 3 twice?
		//will cover next class
}