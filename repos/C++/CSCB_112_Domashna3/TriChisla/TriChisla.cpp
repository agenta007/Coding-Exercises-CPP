// TriChisla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	int max, mid, min;

	if (a==b && a>c)
	{
		max = a;
		mid = b;
		min = c;
	}
	else if (a==c && a>b)
	{
		max = a;
		mid = c;
		min = b;
	}
	else if (b==c && b>a)
	{
		max = b;
		mid = c;
		min = a;
	}
	else
	{
		if (a > b && a > c)
		{
			max = a;
			if (b > c)
			{
				mid = b;
				min = c;
			}
			else
			{
				mid = c;
				min = b;
			}
		}
		else if (b > a && b > c)
		{
			max = b;
			if (a > c)
			{
				mid = a;
				min = c;
			}
			else
			{
				mid = c;
				min = a;
			}
		}
		else if (c > a && c > b)
		{
			max = c;
			if (a > b)
			{
				mid = a;
				min = b;
			}
			else
			{
				mid = b;
				min = a;
			}
		}
	}

	cout << max << endl;
	cout << mid << endl;
	cout << min << endl;
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
