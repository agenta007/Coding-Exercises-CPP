#ifndef _Auto_
#define _Auto_
#include <string>
using std::string;
class Auto
{
private:
	int hp;
	string brand;
public:
	bool operator==(const Auto& right);
	Auto operator++(int);
	Auto& operator++();
	Auto& operator()();
	inline string getBrand() { return brand; }
	inline int getHp() { return hp; }
	void setHp(int hp) { this->hp = hp; }
	void setBrand(string brand) { this->brand = brand; }
	Auto(int hp = 0, string brand = "");
	Auto(const Auto& Auto);
	~Auto();
};
#endif
