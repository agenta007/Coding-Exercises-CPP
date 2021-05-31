#include <iostream>
#include <string.h>
typedef unsigned int cqlo;

using namespace std;

typedef struct Bomba
{
	int timer;
	string type;
	int explosionPower;
}naDqdoBombata;
void zad1()
{
		int n;
	cin >> n;

	int arr[32];
	for (size_t i = 0; i < n; i++)
		cin >> arr[i];

	int sum = 0;
	for (size_t i = 0; i < n; i++)
		sum += arr[i];

	double average = sum / n;

	for (int i = 0; i < n; i++)
		if (arr[i] < average)
			arr[i] = -858993460;

	for (auto& x : arr)
		if (x != -858993460)
			cout << x << " ";
	cout << endl;


}

void zad2()
{
	cout << "Enter count of random numbers [1-100]" << endl;
	int sz;
	cin >> sz;
	int arr[1000];

	for (size_t i = 0; i < sz; i++)
	{
		arr[i] = rand() % 90 + 10;
	}
	
	int arr2[1000];
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 5;
	arr[3] = 7;
	int arr2pos = 0;
	for (size_t i = 0; i < sz; i++)
	{
		int remainders[1000];
		int counter = 0;
		while (arr[i] != 0)
		{
			remainders[counter] = arr[i] % 2;
			arr[i] /= 2;
			counter++;
		}
		if (counter < 4)
		{
			for (size_t k = 0; k < 4; k++)
			{
				if (remainders[k] != 1 && remainders[k] != 0)
				{
					remainders[k] = 0;
					counter++;
				}
			}
		}
		for (int j = counter-1; j > -1; j--)
		{
			arr2[arr2pos] = remainders[j];
			arr2pos++;
		}
		for (auto& x : remainders)
			x = -858993460;
	}
	int decimal = 0;
	int power = arr2pos-1;
	for (size_t i = 0; i < arr2pos; i++)
	{
		decimal += arr2[i] * pow(2, power);
		power--;
		cout << arr2[i];
	}
	cout << endl;
	cout << decimal;
}

int dividersCounter(int N)
{
	int i = 1;
	int arrpos= 0;
	int arr[32];
	int counter = 0;
	while (i!=N+1)
	{
		if (N % i == 0)
		{
			arr[arrpos] = i;
			arrpos++;
			counter++;
		}
		i++;
	}
	//cout vsichki deliteli
	//for (int i = 0; i < arrpos; i++)
	//{
	//	if(arr[i]!= -858993460)
	//	cout << arr[i] << ", ";
	//}
	return counter;
}

void divideBy3ButNotBy5()
{
	int number = 1;
	int arr[1000];
	
	int arrpos = 0;
	int counter = 0;
	while (number<1001)
	{
		if (number % 3 == 0 && number % 5 != 0)
		{
			arr[arrpos] = number;
			arrpos++;
			counter++;
		}
		number++;
	}

	cout << counter << endl;
	//for (int i = 0; i < arrpos; i++)
	//{
	//	cout << arr[i] <<", ";
	//}
}

void zad3()
{
	int arr[32];

	//getting Permutation(0-31)
	int usedNums[32];
	int usedNumsPos = 0;
	for (size_t i = 0; i < 32; i++)
	{
		int r = rand() % 31;
		for (size_t j = 0; j < 32; j++)
		{
			if (usedNums[j] == r)
			{
				j = 0;
				r = rand() % 32 + 1;
			}
		}

		arr[i] = r;
		usedNums[usedNumsPos] = r;
		usedNumsPos++;
	}

	cout << "Permutation of 0-31" << endl;
	for (auto& N : arr)
		cout << N << ", ";
	cout << endl;

	cout << "Swapped pos" << endl;
	//swapping positions First>>Last Last>>First and so on
	for (size_t i = 0; i < 16; i++)
	{
		int temp = arr[32 - i - 1];
		arr[32 - i - 1] = arr[i];
		arr[i] = temp;
	}

	for (auto& N : arr)
		cout << N << ", ";
	cout << endl;

	for (auto& N : arr)
	{
		int temp = N;
		int digitCounter = 0;
		while (N/10!=0)
		{
			N /= 10;
			digitCounter++;
		}
		digitCounter++;
		int firstDigit = N;
		temp = temp + pow(10, digitCounter) * firstDigit;
		N = temp;
	}

	cout << "First digit gets doubled" << endl;
	for (auto& N : arr)
		cout << N << ", ";
	cout << endl;
}

void zad4Ploshtadka()
{
	int arr[32];

	for (auto& N : arr)
	{
		int r = rand() % 10 + 1;
		int multiplier = rand() % 9 + 2;

		int power = 1;
		int firstDigit = r;
		while (multiplier!=1)
		{
			r = r + firstDigit * pow(10, power);
			power++;
			multiplier--;
		}
		N = r;

	}
}

void strcopy()
{
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy_s(str2, str1);
	strcpy_s(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
}

int main()
{
	strcopy();
	cqlo chishlo = 5;
	int a = 15;
	int* p = &a;
	cout << p << endl;
	cout << *p << endl;

	Bomba moitaBomba;
	moitaBomba.explosionPower = 15;
	int x = 15;
	for (size_t i = 1; i <= x; i+=2)
	{
		if (i == x)
			cout << i;
		else
			cout << i << ", ";
	}
	cout << endl;
	//0==false
	//(!0)==true
	int i = 0;
	while (0)
	{
		if (i == x)
			cout << i;
		else
			cout << i << ", ";
		i++;
	}
	//-1
	//do X
	int arr[10];
	for (size_t i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		if(temp % 2 == 0)
			temp *= -1;
		arr[i] = temp;
	}

}
