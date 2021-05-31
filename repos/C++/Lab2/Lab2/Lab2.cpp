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

void razlagane_find_max_power_that_divides()
{
	int n, p;
	bool pComplexity;
	do
	{
		cout << "Enter n>0 and p - prime." << endl;
		cin >> n >> p;
		pComplexity = checkComplexOptimized(p);
	} while (n < 0 && pComplexity);

	int num = p;
	int power = 1;
	while (n % num == 0)
	{
		num *= num;
		power++;
	}

	cout << power << endl;

}

struct delitel
{
	int chislo;
	int broi;
};

delitel* add_delitel(int d, delitel* arrToAdd)
{
	int oldArrSz = sizeof(arrToAdd);
	int newArrSz = sizeof(arrToAdd) + 1;
	delitel* newArr = new delitel[newArrSz];
	
	if (sizeof(arrToAdd)!=0)
	{
		for (size_t i = 0; i < sizeof(arrToAdd); i++)
		{
			newArr[i] = arrToAdd[i];
		}
	}
	newArr[sizeof(newArr) - 1].chislo = d;
	return newArr;
}

bool checkIfItsInArray(int d, delitel* arr)
{
	for (size_t i = 0; i < sizeof(arr); i++)
	{
		if (arr[i].chislo == d)
		{
			return true;
		}
	}
	return false;
}

//UNFINISHED
void kanonichnoRazlagane_structs()
{
	int n;
	do
	{
		cout << "Enter N>-1" << endl;
		cin >> n;
	} while (n < 0);

	delitel* arr = nullptr;
	int arrElements = 0;

	bool isItInArray;
	while (checkComplexOptimized(n))
	{
		for (size_t i = 2; i < n; i++)
		{
			if (arrElements != 0)
				isItInArray = checkIfItsInArray(i, arr);
			else
				isItInArray = false;
			if (n % i == 0 && !isItInArray)
			{
				arr = add_delitel(i, arr);
				arrElements++;
			}

			while (n % i == 0)
			{
				for (size_t j = 0; j < sizeof(arr); j++)
				{
					if (arr[j].chislo == i)
					{
						arr[j].broi++;
						break;
					}
				}
				n /= i;
			}
		}
	}

	for (size_t i = 0; i < sizeof(arr); i++)
	{
		cout << arr[i].chislo << " ^ " << arr[i].broi << " +";
	}
	cout << "\n";

}

void kanonichnoRazlagane()
{

}

int main()
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

	for (size_t i = 0; i < counter; i++)
	{
		if (powers[i] != 0)
		{
			if (i + 1 != counter)
			{
				cout << primeNumbers[i] << " ^ " << powers[i] << " * ";
			}
		}

		if (i+1 == counter)
		{
			cout << " = " << n << "\n";
		}

	}
}
