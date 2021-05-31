#ifndef TRUCK
#define TRUCK
#include "Vehicle.h"
#include <string>
using std::string;
using std::ostream;
class Truck:public Vehicle
{
private:
	bool teglich;
	int cargoCapacity;
public:
	string getTeglich()const { return teglich?"Ima teglich.":"Nqma teglich."; }
	void setTeglich(bool set) { teglich = set; }
	void setCargoCapacity(int set) { cargoCapacity = set; }
	int getCargoCapacity()const { return cargoCapacity; }
	bool operator<(const Truck& rhs) { return cargoCapacity < rhs.cargoCapacity ? 1 : 0; }
	bool operator>(const Truck& rhs) { return cargoCapacity > rhs.cargoCapacity ? 1 : 0; }
	bool operator==(const Truck& rhs) { return cargoCapacity == rhs.cargoCapacity ? 1 : 0; }
	bool operator<=(const Truck& rhs) { return cargoCapacity <= rhs.cargoCapacity ? 1 : 0; }
	bool operator>=(const Truck& rhs) { return cargoCapacity >= rhs.cargoCapacity ? 1 : 0; }
	friend ostream& operator<< (ostream&, const Truck&);

};

ostream& operator<< (ostream& out, const Truck& objRef)
{
	//cout << "Cargo Capacity: ";
	string imaLiTeglich;
	out << "Cargo Capacity:" << objRef.getCargoCapacity() << "Teglich: ";
	//out << objRef;
	return out;
}

#endif