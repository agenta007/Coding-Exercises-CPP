#include<iostream>
using namespace std;
int main()
{
	int a = 5;
	double b = 11.11;
	cout << (typeid(a) == typeid(b)) ? 1 : 0;
}