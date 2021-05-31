#ifndef _Building_
#define _Building_
#include <string.h>
class Building
{
private:
	char* adres;
	unsigned planiraniEtaji, 
		planiraniVhodove, 
		zastroeniEtaji, 
		zastroeniVhodove;
public:
	Building();
	Building(char* = nullptr, unsigned = 0, unsigned = 0, unsigned = 0, unsigned = 0);
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
	{ 
		if (adres != nullptr)
		{
			adres = new char[strlen(str + 1)];
			strcpy_s(adres, strlen(str + 1), str);
		}
		else
		{
			strcpy_s(adres, strlen(str+1), str);
		}
	}
	Building& operator+(unsigned);
	Building& operator+(const Building&);
	Building& operator=(const Building&);
	Building operator+=(unsigned);
	//friend ostream& operator<<(ostream& out, const Building& rhs);
	//friend istream& operator>>(istream& in, const Building& rhs);
};
#endif

