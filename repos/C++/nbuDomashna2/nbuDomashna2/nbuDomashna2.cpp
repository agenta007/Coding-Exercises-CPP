// nbuDomashna2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long int x;
	cin >> x;
	int stepen = 1;
	while (stepen <= 63)
	{
		if (pow(2, stepen) == x)
		{
			switch (stepen)
			{
			case 1:
				cout << "x is the first power of 2" << endl;
				return 0;
			case 2:
				cout << "x is the second power of 2" << endl;
				return 0;
			case 3:
				cout << "x is the third power of 2" << endl;
				return 0;
			default:
				cout << "x is the " << stepen << "-th power of 2" << endl;
				return 0;
			}
		}
		stepen++;
	}
	cout << "X is not a power among the first 32 powers of 2 or is not a power" << endl;
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
