#include <iostream>
#include <cmath>


int razbivaneNaSumi(int n)
{
	int maskLength = n * pow(10, n-1);
	int* arr = new int[n];
	int sum = 0;
	int number;
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	for (size_t i = 0; i < maskLength; i++)
	{
		number = arr[i];
		for (int j = n-1; j > -1; j--)
		{
			arr[j] = number % 10;
			number /= 10;
		}

		for (size_t j = 0; j < n; j++)
		{
			sum += arr[j];
		}
		if (sum == n)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (j + 1 != n)
					std::cout << arr[j] << " + ";
				else
					std::cout << arr[j] << " = " << n << "\n";
			}
		}
		sum = 0;
	}
	return 0;
}

int main()
{
	int n;
	std::cin >> n;
	razbivaneNaSumi(n);
}