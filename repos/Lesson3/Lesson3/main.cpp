#include <iostream>
#include "Building.h"

using namespace std;

Building::Building(char* adres, unsigned plEt, unsigned plVh, unsigned zsEt, unsigned zsVh)
{
	this->adres = new char[strlen(adres) + 1];
	strcpy_s(this->adres, strlen(adres) + 1, adres);
	planiraniEtaji = plEt;
	planiraniVhodove = plVh;
	zastroeniEtaji = zsEt;
	zastroeniVhodove = zsVh;
}
Building::Building(const Building& r)
{
	if (strlen(r.adres) > strlen(adres))
		strcpy_s(adres, strlen(r.adres), r.adres);
	else {
		delete[] adres;
		adres = new char[strlen(r.adres)+1];
		strcpy_s(adres, strlen(r.adres) + 1,r.adres);
	}
	zastroeniEtaji = r.zastroeniEtaji;
	zastroeniVhodove = r.zastroeniVhodove;
	planiraniEtaji = r.planiraniEtaji;
	planiraniVhodove = r.planiraniVhodove;
}
Building::~Building()
{
	delete[] adres;
}
Building& Building::operator+(unsigned inc)
{
	zastroeniEtaji += inc;
	return *this;
}
Building& Building::operator=(const Building& obj)
{
	zastroeniEtaji = obj.zastroeniEtaji;
	zastroeniVhodove = obj.zastroeniVhodove;
	planiraniEtaji = obj.planiraniEtaji;
	planiraniVhodove = obj.planiraniVhodove;
	return *this;
}
Building Building::operator+=(unsigned inc)
{
	Building tmp = *this;
	tmp.zastroeniEtaji += inc;
	return tmp;
}

Building& Building::operator+(const Building& objR)
{
	zastroeniEtaji += objR.zastroeniEtaji;
	return *this;
}

Building& operator+(unsigned inc, const Building& objR)
{
	return inc + objR;
}

unsigned operator+=(unsigned inc, const Building& objR)
{
	return inc += objR.getZsEt();
}

//friend ostream& operator<<(ostream& out, const Building& rhs)
//{
//	return out << rhs.getAdres() << "Zastroeni etaji: " << rhs.getZsEt() << "\n";
//}
//
//friend istream& operator>>(istream& in, Building& rhs)
//{
//	return in >> rhs;
//}

int main()
{
	return 0;
}