#ifndef MANAGER
#define MANAGER
#include "Employee.h"
#include <iostream>
using std::cout;
class Manager:public Employee
{
private:
	string otdel;
public:
	void print() { cout << "Ime: " << getName() << " Otdel: " << otdel << " Zaplata: " << getWage() << "\n"; }
	string getOtdel()const { return otdel; }
};
#endif
