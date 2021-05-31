#ifndef AUTOMOBILE
#define AUTOMOBILE
#include "Vehicle.h"
#include <assert.h>
using std::string;
string stringReturner(int n)
{
	int digits = 0;
	int tmpN = n;
	while (tmpN / 10 != 0)
	{
		++digits;
	}
	char* buffer = new char[digits+1];
	for (int i = 0; i != digits-1; ++i)
	{
		buffer[i] = '0';
	}

	_itoa_s(n, buffer, digits, 10);
	buffer[digits] = '\0';
	return buffer;
}
class Automobile:public Vehicle
{
private:
	int topSpeed, hp, torque;
	bool diesel;
	string brandAndModel;
public:
	//getters
	int getHp()const { return hp; }
	string getTopSpeed()const { return stringReturner(topSpeed) + " km\\h"; }
	string getBrandAndModel()const { return brandAndModel; }
	string getTorque()const { return stringReturner(torque) + " N⋅m"; }
	bool getDiesel()const { assert(brandAndModel != "unknown"); return diesel; }
	void setHp(int n) { hp = n; }
	void setTorque(int n) { torque = n; }
	void setDiesel(bool set) { diesel = set; }
	void setTopSpeed(int set) { topSpeed = set; }
	void setBrandAndModel(string set) { brandAndModel = set; }
	Automobile(string = "uknown", int = 0, int = 0, int = 0, bool = 0);
	Automobile(const Automobile&);
};
#endif