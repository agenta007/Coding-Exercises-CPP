#ifndef _CALCULATOR_
#define _CALCULCATOR_

class Calculator
{
	char* expression;
	int result;
	public:
	bool validateEx(char []);
	void calculate();
	void setExpr() const;
	void getExpr() const;
};

#endif