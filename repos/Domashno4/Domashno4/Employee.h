#ifndef EMLOYEE
#define EMPLOYEE
#include <string>
using std::string;
class Employee
{
private:
	string name;
	double wage;
	int staj;
public:
	string getName()const { return name; }
	double getWage()const { return  wage; }
	int getStaj()const { return  staj; }
	//void print()const {cout <<}
};
#endif
