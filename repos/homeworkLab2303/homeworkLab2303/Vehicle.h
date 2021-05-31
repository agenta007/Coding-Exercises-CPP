#ifndef VEHICLE
#define VEHICLE
#include <string>
using std::string;
using std::ostream;
class Vehicle
{
private:
	string vehType;
	int tyres, doors;
public:
	Vehicle(string = "noType", int = 0, int = 0);
	Vehicle(const Vehicle&);
	//ne se izpolzva dinamichna pamet => default destructor
	string getVehType()const { return vehType; }
	int getTyres()const { return tyres; }
	int getDoors()const { return doors; }
	void setVehType(string set) { vehType = set; }
	void setDoors(int set) { doors = set; }
	void setTyres(int set) { tyres = set; }
	friend ostream& operator<<(ostream&, const Vehicle&);
	void operator=(const Vehicle&);
};
#endif
