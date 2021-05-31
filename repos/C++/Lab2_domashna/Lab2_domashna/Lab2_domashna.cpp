#include <iostream>
#include <cmath>
using namespace std;

bool checkComplexOptimized(int n)
{
	int i = 2;
	while (i <= sqrt(n))
	{
		if (n % i == 0)
		{
			return true;
		}
		i++;
	}
	return false;
}

void primityCheckOptimized()
{
	int n;
	cin >> n;

	if (n == 0 or n == 1)
	{
		cout << n << " is not prime nor complex.";
		return;
	}

	bool isItPrime = checkComplexOptimized(n);
	isItPrime ? cout << n << " is complex.\n" : cout << n << " is prime.\n";
}

struct EratostenNumbers
{
	int number;
	bool writeOrNot;
};

void eratosten_resheto(int n)
{
	EratostenNumbers* arr = new EratostenNumbers[n];

	int num = 2;
	int isItComplex;
	for (size_t i = 0; i < n; i++)
	{
		arr[i].number = num;
		isItComplex = checkComplexOptimized(num);
		isItComplex ? arr[i].writeOrNot = false : arr[i].writeOrNot = true;
		num++;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (arr[i].writeOrNot)
		{
			cout << arr[i].number << " ";
		}
	}
	cout << endl;
}

void pyrvaZadacha()
{
	int n;
	cin >> n;

	EratostenNumbers* arr = new EratostenNumbers[n];

	int num = 2;
	int isItComplex;
	for (size_t i = 0; i < n; i++)
	{
		arr[i].number = num;
		isItComplex = checkComplexOptimized(num);
		isItComplex ? arr[i].writeOrNot = false : arr[i].writeOrNot = true;
		num++;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (arr[i].writeOrNot)
		{
			cout << arr[i].number << " ";
		}
	}
	cout << endl;



	int counter = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i].writeOrNot)
		{
			counter++;
		}
	}

	int* primeNumbers = new int[counter];

	int primeNumbersPos = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i].writeOrNot)
		{
			primeNumbers[primeNumbersPos] = arr[i].number;
			primeNumbersPos++;
		}
	}

	int* powers = new int[counter];

	for (size_t i = 0; i < counter; i++)
	{
		powers[i] = 0;
	}

	int tmp;
	for (size_t i = 0; i < counter; i++)
	{
		tmp = n;
		while (tmp % primeNumbers[i] == 0)
		{
			tmp /= primeNumbers[i];
			powers[i]++;
		}

	}

	int cnt = 0;
	for (size_t i = 0; i < counter; i++)
	{
		if (powers[i] != 0)
		{
			cnt++;
		}
	}

	int numbersDisplayed = 0;
	for (size_t i = 0; i < counter; i++)
	{
		if (powers[i] != 0)
		{
			if (i + 1 != counter)
			{
				if (numbersDisplayed + 1 != cnt)
					cout << primeNumbers[i] << " ^ " << powers[i] << " * ";
				else
					cout << primeNumbers[i] << " ^ " << powers[i];
				numbersDisplayed++;
			}
		}

		if (i + 1 == counter)
		{
			cout << " = " << n << "\n";
		}

	}

}

int print_arr(int* arr, int sz, int n)
{
	for (size_t i = 0; i < sz; i++)
	{
		if (arr[i]==0)
		{
			continue;
		}
		else
		{
			if (i + 1 != sz)
				cout << arr[i] << " + ";
			else
				cout << arr[i] << " = " << n << "\n";
		}
	}
	return 0;
}

int sum_of_arr(int* arr, int sz)
{
	int sum = 0;
	for (size_t i = 0; i < sz; i++)
	{
		sum =+ arr[i];
	}
	return sum;
}

int getSum(int a)
{
	int sum = 0;
	while (a!=0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

struct combination
{

};

int main()
{
	int n;
	cin >> n;
	int maxNum = n * pow(10, n-1);
	int sum;
	int tmp;
	int* digitArr = new int[6];
	int** list = new int*[maxNum/2];
	int listPos = 0;
	bool isComboPresent = false;
	int digitArrPos = 0;
	int sameNumbersCnt = 0;
	int digitsCounter = 0;
	int foundCombinationsCnt = 0;
	for (size_t i = 0; i < maxNum; i++)
	{
		sum = getSum(i);
		if (sum == n)
		{
			tmp = i;

			//GET DIGITS IN ARRAY
			for (size_t j = 0; j < 6; j++)
			{
				if (tmp % 10 != 0)
				{
					digitArr[j] = tmp % 10;
					tmp /= 10;
				}
			}

			//DIGITS COUNTER AND SAME NUMBER COUNTER
			for (size_t j = 0; j < listPos; j++)
			{
				for (size_t k = 0; k < 6; k++)
				{

					for (size_t l = 0; l < 6; l++)
					{
						if (list[j][l] != 0)
						{
							digitsCounter++;
						}
					}


					if (digitArr[k] == 0)
						continue;
					for (size_t ll = 0; ll < 6; ll++)
					{
						if (list[j][k] == digitArr[digitArrPos])
						{
							sameNumbersCnt++;
							if (sameNumbersCnt == digitsCounter)
							{
								isComboPresent = true;
								break;
							}
						}
						digitArrPos++;
					}
				}
			}


			if (isComboPresent)
				continue;

			list[listPos] = digitArr;
			listPos++;
			
			tmp = i;
			while (tmp != 0)
			{
				if (tmp / 10 != 0)
				{
					if (tmp % 10 == 0)
					{
						tmp /= 10;
						continue;
					}
					cout << tmp % 10 << " + ";
				}
				else
				{
					if (tmp % 10 == 0)
					{
						continue;
					}
					cout << tmp % 10;
				}
				tmp /= 10;
			}
			cout << " = " << n << "\n";
		}
	}

	delete[] digitArr;
	for (size_t i = 0; i < maxNum/2; i++)
	{
		delete[] list[i];
	}
	delete[] list;
}