#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <cmath>
#include "Vehicle.h"
void calculatePI()
{
	double sum, znamenatel;
	sum = 0;
	znamenatel = 1;
	for (int i = 1; i != 10001; ++i)
	{
		if (i%2==0)
		{
			sum -= 1. / znamenatel;
		}
		else
		{
			sum += 1. / znamenatel;
		}

		if (i%500==0)
		{
			cout << "i = " << setprecision(15) << i << ", pi = " << sum * 4. << "\n";
		}
		znamenatel += 2;
	}
}

bool checkInts(int &x, int &y)
{
	x /= 10;
	y /= 10;
	if (x==0 || y == 0)
	{
		return false;
	}
	if (x==y)
	{
		return true;
	}
	return false;
}

void calculatePI3()
{
	int i = 1;
	double znamenatel, sum, oldPi, pi;
	znamenatel = 1;
	int razlika;
	sum = oldPi = pi = 0;
	while (1)
	{
		oldPi = pi;
		pi = sum * 4.;
		int conversion1, conv2;
		conversion1 = pow(10, 7) * pi;
		conv2 = pow(10, 7) * oldPi;
		razlika = abs(pow(10, 7) * pi - pow(10, 7) * oldPi);
		if (razlika==1)
		{
			break;
		}
		if (i%2==0)
		{
			sum -= 1. / znamenatel;
		}
		else
		{
			sum += 1. / znamenatel;
		}
		znamenatel += 2;
		++i;
		//cout << setprecision(8) <<"Iteraciq #" << i << " Pi(i) = " << pi << " Pi(i-1) = " << oldPi << "\n";
	}
	cout << setprecision(8) <<"Iteraciq #" << i << " Pi(i) = " << pi << " Pi(i-1) = " << oldPi << "\n";
}

void calculatePI2()
{
	double sum, znamenatel, pi, previousPi;
	int i = 1;
	int conversionOld, conversionNew;
	conversionNew = conversionOld = 0;
	znamenatel = 1;
	pi = sum = 0;
	previousPi = 1;
	while (abs(conversionOld%10 - conversionNew%10) != 1 || !checkInts(conversionNew, conversionOld))
	{
		previousPi = pi;
		if (i%2==0)
		{
			sum -= 1. / znamenatel;
		}
		else
		{
			sum += 1. / znamenatel;
		}
		pi = 4. * sum;
		znamenatel += 2;
		cout << setprecision(8) <<"pi = " << pi << "\n";
		++i;
		conversionOld = previousPi * pow(10, 8);
		conversionNew = pi * pow(10, 8);
	}
}

int factoriel(int n)
{
	int factoriel;
	factoriel = 1;
	for (int i = n; i != 1; --i)
	{
		factoriel *= i;
	}
	return factoriel;
}
void sinus()
{
	int x;
	cin >> x;
	double sum = 0;
	int chislitel, znamenatel;
	for (size_t i = 0; i < 100; i++)
	{
		chislitel = pow(x, (2 * i - 1));
		znamenatel = factoriel(2 * i - 1);
		sum += chislitel / znamenatel;
	}
	cout << sum << endl;
}

int main()
{

	Vehicle *vp = new Vehicle("sports car", 350, 4);
	Vehicle* cars[12];
	for (auto& car : cars)
	{
		Vehicle tmp("arrayCar", 150, 5);
		car = &tmp;
	}

	for (auto& car : cars)
	{
		cout << *car << endl;
	}

	Vehicle *vehiclesOfAllTypes = new Vehicle[5]
	//vp.
	/*double a, b;
	a = 3.14158912;
	b = 3.14158913;
	int a1, b1;
	a1 = a * pow(10, 8);
	b1 = b * pow(10, 8);
	a1 /= 10;
	b1 /= 10;
	a = a1 * pow(10, -7);
	b = b1 * pow(10, -7);*/
	//float f = 3;
	//double a = 3.14166816544128;
	//double b = 3.14166824113378;
	//string a1, b1;
	//a1 = to_string(a);
	//b1 = to_string(b);
	//a = stod(a1);
	//b = stod(b1);
	//calculatePI();
	//calculatePI2();
	//calculatePI();
	//calculatePI3();
	//sinus();
	return 0;
}