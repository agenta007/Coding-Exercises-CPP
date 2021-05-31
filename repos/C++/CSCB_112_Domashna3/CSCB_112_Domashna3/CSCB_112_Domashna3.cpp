// CSCB_112_Domashna3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int number, countSystem;
	cout << "Enter count system" << endl;
	cin >> countSystem;
	cout << "Enter number" << endl;
	cin >> number;

	int digits[32];

	/*int digitsCount = 0;
	do
	{
		number /= 10;
		digitsCount++;
	} while (number != 0);*/

	int ostatuk;
 	if (countSystem >= 2 && countSystem < 10)
	{
		int j = 0;
		while(number != 0)
		{
			ostatuk = number % countSystem;
			number /= countSystem;
			digits[j] = ostatuk;
			j++;
		}

		for (int i = j-1; i >= 0; i--)
		{
			cout << digits[i];
		}
		cout << endl;
	}
	else
	{
		cout << "Invalid count system. (2-9)" << endl;
	}
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
