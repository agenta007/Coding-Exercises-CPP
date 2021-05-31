#include <iostream>
#include <cmath>
using namespace std;

void zadacha1()
{
	int N;
	cin >> N;
	double* darr = new double[N];

	for (size_t i = 0; i < N; i++)
	{
		double pyrviChlen = pow(((i + 1) - 2), 2);
		if (i == 0)
			pyrviChlen = 1;
		double vtoriChlen = N * (i + 1);
		darr[i] = pyrviChlen + vtoriChlen;
	}

	double sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += darr[i];
		if (i + 1 != N)
			cout << darr[i] << ", ";
		else
			cout << darr[i] << "\n";
	}
	cout << sum << "\n";

}

void zadacha2()
{
	int arr[8];
	int x;
	cout << "Enter numbers between 22-50\n";
	for (size_t i = 0; i < 8; i++)
	{
		cin >> x;
		while (x < 22 || x>50)
		{
			cout << "Invaid numbmer. Try again:\n";
			cin >> x;
		}
		arr[i] = x;
	}

	cout << "How many elements to print?\n";
	cin >> x;
	for (size_t i = 0; i < x; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	cout << "Let's find the closest value to arr[0]\n";

	int diff[7];
	int index = 0;
	for (size_t i = 1; i < 8; i++)
	{
		if (arr[i] > arr[0])
		{
			int number = arr[i];
			int counter = 0;
			while (number != arr[0])
			{
				number--;
				counter++;
			}
			diff[i - 1] = counter;
		}
		else if (arr[i] == arr[0])
		{
			index = i;
			break;
		}
		else
		{
			int number = arr[i];
			int counter = 0;
			while (number != arr[0])
			{
				number++;
				counter++;
			}
			diff[i - 1] = counter;
		}
	}

	for (auto& x : diff)
		cout << x << " ";
	cout << "\n";
	int min = 50;
	for (size_t i = 0; i < 7; i++)
	{
		if (diff[i] < min)
		{
			min = diff[i];
		}
	}

	for (size_t i = 0; i < 7; i++)
	{
		if (min == diff[i])
		{
			index = i + 1;
		}
	}

	cout << "Index of closest is: " << index << "\n";


	for (size_t i = 0; i < 8; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arr[i] = i + arr[i] + 8;
		}
		else
		{
			arr[i] *= 2;
			arr[i] -= 3;
		}
	}

	for (auto& x : arr)
		cout << x << " ";
	cout << "\n";

}

bool checkPrime(int a)
{
	int i = 2;
	while (i != a)
	{
		if (a % i == 0)
		{
			return true;
		}
		i++;
	}
	return false;
}

int timesToDivide(int a, int d)
{
	int counter = 0;
	while (a % d == 0)
	{
		a /= d;
		counter++;
	}
	return counter;
}

void zadacha3()
{
	cout << "Enter four digit number: \n";
	int x;
	cin >> x;

	bool isItPrime = false;

	isItPrime = checkPrime(x);

	int arr[8];

	int arrPos = 0;
	for (size_t i = 2; i < 10; i++)
	{
		arr[arrPos] = timesToDivide(x, i);
		arrPos++;
	}

	isItPrime ? cout << "Number is not prime.\n" : cout << "Number is prime.";
	for (auto& y : arr)
		cout << y << " ";
	cout << "\n";

}

int main()
{
	zadacha1();
	zadacha2();
	zadacha3();
}

