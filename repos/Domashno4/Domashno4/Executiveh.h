#ifndef EXECUTIVE
#define EXECUTIVE
#include "Manager.h"
class Executive:public Manager
{
public:
	void print()const { cout << "Executive " << "Otdel: " << getOtdel() << " Wage: " << getWage() << " Staj: " << getStaj() << std::endl; }
};
#endif
