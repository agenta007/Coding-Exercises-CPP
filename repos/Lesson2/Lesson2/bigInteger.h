#ifndef _BIG_INTGER_
#define _BIG_INTGER_
#include <string>
#include <vector>
class BigInteger
{
private:
	std::string base;
	std::vector<long long> multiplications;
public:
	BigInteger() {}
	BigInteger(std::string);
	BigInteger operator * (BigInteger &b);
};
#endif