#include "Building.h"
/*
* 	Building(char* = nullptr, int = 0, int = 0, int = 0, int = 0);
	~Building();
	Building(const Building&);
	unsigned getPlEt ()const { return planiraniEtaji; }
	unsigned getPlVh ()const {return planiraniVhodove;}
	unsigned getZsEt ()const {return zastroeniEtaji;}
	unsigned getZsVh ()const {return zastroeniVhodove;}
	char& getAdres ()const {return *adres;}
	void setPlEt(unsigned n) { planiraniEtaji = n; }
	void setPlVh(unsigned n) { planiraniVhodove = n; }
	void setZsEt(unsigned n) { zastroeniEtaji = n; }
	void setZsVh(unsigned n) { zastroeniVhodove = n; }
	void setAdres(char* str) 
	Building& operator+(unsigned);
	Building& operator=(const Building&);
	Building& operator+=(unsigned);
*/
Building::Building(char* adres, unsigned plEt, unsigned plVh, unsigned zsEt, unsigned zsVh)
{
	this->adres = new char[strlen(adres)+1];
	strcpy_s(this->adres, strlen(adres)+1, adres);
	planiraniEtaji = plEt;
	planiraniVhodove = plVh;
	zastroeniEtaji = zsEt;
	zastroeniVhodove = zsVh;
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