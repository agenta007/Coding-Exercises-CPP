// nbuDomashna1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI

using namespace std;

int main()
{
	//cout << pow(3, 1. / 3) << endl;
	//cout << 1.44 * 1.44 * 1.44 << endl;
	//
	//cout << (2 + pow(3, 1. / 3) + pow(4, 1. / 4)) / (pow(5, 1. / 5) + pow(6, 6. / 6) + pow(7, 1. / 7)) << endl;
	//
	//	int x;
	//cin >> x;
	//cout << sin(x) + cos(x) - (pow((tan(x) + 1 / tan(x)), 3)) / log(2 + pow(x, 3));

	int n;
	cin >> n;
	bool trueOrFalse = false;
	if (n % 3 && n % 7 == 0 || n % 2 && n % 7 ==0)
	{
		trueOrFalse = true;
	}
	else
	{
		trueOrFalse = false;
	}

	cout << trueOrFalse << endl;


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
