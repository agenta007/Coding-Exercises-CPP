#include "Vehicle.h"
Vehicle::Vehicle(string vehType, int tyres, int doors)
{
	this->vehType = vehType;
	this->tyres = tyres;
	this->doors = doors;
}
Vehicle::Vehicle(const Vehicle& objRef)
{
	vehType = objRef.vehType;
	tyres = objRef.tyres;
	doors = objRef.doors;
}
void Vehicle::operator=(const Vehicle& rhs)
{
	vehType = rhs.vehType;
	tyres = rhs.tyres;
	doors = rhs.doors;
}
ostream& operator<<(ostream& out, const Vehicle& rhs)
{
	out << "Vehicle Type: " << rhs.vehType << " Tyres: " << rhs.tyres << " Doors: " << rhs.doors;
}