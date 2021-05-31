#include "Automobile.h"
Automobile::Automobile(string name, int hp, int torque, int topSpeed, bool diesel)
{
	brandAndModel = name;
	this->hp = hp;
	this->torque = torque;
	this->topSpeed = topSpeed;
	this->diesel = diesel;
	if (topSpeed > 200 || torque > 250 || hp>200)
	{
		setVehType("Sports Car");
		setDoors(3);
		setTyres(4);
	}
	else
	{
		setVehType("Car");
		setDoors(5);
		setTyres(4);
	}
}

Automobile::Automobile(const Automobile& autoRef)
{
	brandAndModel = autoRef.brandAndModel;
	hp = autoRef.hp;
	torque = autoRef.torque;
	topSpeed = autoRef.topSpeed;
	diesel = autoRef.diesel;
	setVehType(autoRef.getVehType());
}