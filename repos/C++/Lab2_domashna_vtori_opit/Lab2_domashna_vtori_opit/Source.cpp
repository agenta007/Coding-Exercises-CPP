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

bool isNumberInArr(int* arr, int l, int searched)
{
	for (size_t i = 0; i < l; i++)
	{
		if (arr[i]==searched)
		{
			return true;
		}
	}
	return false;
}

bool canSearchedBeSummed(int* arr, int l, int searched)
{
	int counter = 0;
	for (size_t i = 0; i < l; i++)
	{
		if (arr[i] == searched)
		{
			counter++;
		}
	}

	if (counter > 1)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];
	int reversedPosArr = n-1;
	int arrPos = 0;

	for (size_t i = 0; i < n; i++)
	{
		arr[i] = 1;
	}

	int currrentSearchedNum = 1;
	int i = 0;
	while (isNumberInArr(arr, n , currrentSearchedNum))
	{
		//PRINTING ALL IN ARRAY
		for (size_t i = 0; i < n; i++)
		{
			if (i + arrPos+1 != n)
			{
				if(arr[i] != 0)
					cout << arr[i] << " + ";
			}
			else
			{
				if (arr[i] != 0)
					cout << arr[i] << " = " << n << "\n";
				else
					cout << " = " << n << "\n";
			}
		}


		if (arr[i] == currrentSearchedNum && arr[i + 1] == currrentSearchedNum)
		{
			arr[arrPos] = currrentSearchedNum + currrentSearchedNum;
			arrPos++;
			arr[reversedPosArr] = 0;
			reversedPosArr--;
		}
		i++;
		if (!canSearchedBeSummed(arr, n, currrentSearchedNum))
		{
			currrentSearchedNum++;
			i = 0;
		}
	}

}

