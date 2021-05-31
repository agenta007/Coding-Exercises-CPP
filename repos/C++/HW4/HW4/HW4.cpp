#include <iostream>
using namespace std;

//2
int getSum(int Z)
{
	cout << "Zadacha2" << endl;
	int sum = 0;

	while(Z != 0)
	{
		sum += Z % 10;
		Z /= 10;
	}
	return sum;
}

//3
void getZMirrored()
{
	cout << "Zadacha 3" << endl;
	int X;
	cin >> X;
	
	while (X!=0)
	{
		int currentDigit = X % 10;
		cout << currentDigit;
		X /= 10;
	}

	cout << endl;

}

//4
void countDigitsInNumber()
{
	cout << "Zadacha 4" << endl;
	cout << "Enter any number / Z" << endl;
	int Z;
	cin >> Z;
	int digitsCounter [10];

	for (size_t i = 0; i < 10; i++)
	{
		digitsCounter[i] = 0;
	}

	int currentDigit;
	while (Z!=0)
	{
		currentDigit = Z % 10;

		switch (currentDigit)
		{
		case 0: digitsCounter[0]++;break;
		case 1: digitsCounter[1]++;break;
		case 2: digitsCounter[2]++;break;
		case 3: digitsCounter[3]++;break;
		case 4: digitsCounter[4]++;break;
		case 5: digitsCounter[5]++;break;
		case 6: digitsCounter[6]++;break;
		case 7: digitsCounter[7]++;break;
		case 8: digitsCounter[8]++;break;
		case 9: digitsCounter[9]++;break;
		default:
			break;
		}
		Z /= 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cout << i << "/" << digitsCounter[i] << ", ";
	}
	cout << endl;
}
//5
void triangle()
{
	cout << "5 Zadacha: Triagalnik" << endl;
	char character;
	int N;
	cin >> character;
	cin >> N;

	int spaceCount = N-1;
	int starCount = 1;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < spaceCount; j++)
		{
			if (spaceCount < 0)
			{
				break;
			}
			cout << " ";
		}
		for (size_t j = 0; j < starCount; j++)
		{
			cout << character;
		}
		cout << endl;
		spaceCount--;
		starCount += 2;
	}
}
//6
void rectangle()
{
	cout << "Zadacha 6 : Pravoagalnik, vuvedete N" << endl;
	int N;
	cin >> N;
	int count = N * 2;

	for (size_t i = 0; i < count; i++)
	{
		cout << "0";
	}
	cout << endl;

	for (size_t red = 1; red <= N; red++)
	{
		int current = 1;
		while (current!=N+1)
		{
			if (current<=red)
			{
				cout << current;
			}
			else
			{
				cout << 0;
			}
			current++;
		}
		
		current--;
		while (current!=0)
		{
			if (current<=red)
			{
				cout << current;
			}
			else
			{
				cout << 0;
			}
			current--;
		}
		cout << endl;
	}
	if (N>10)
	{
		cout << "N<10!, numbers go out of rectangle" << endl;
	}
}
//7*
void rectangle2()
{
	cout << "Zadacha 6 : Pravoagalnik, vuvedete N" << endl;
	int N;
	cin >> N;
	int count = N * 2;

	for (size_t i = 0; i < count-1; i++)
	{
		cout << "0";
	}
	cout << endl;

	for (size_t red = 1; red <= N; red++)
	{
		int current = 1;
		while (current != N + 1)
		{
			if (current <= red)
			{
				cout << current;
			}
			else
			{
				cout << 0;
			}
			current++;
		}

		current-=2;
		while (current != 0)
		{
			if (current <= red)
			{
				cout << current;
			}
			else
			{
				cout << 0;
			}
			current--;
		}
		cout << endl;
	}
	if (N > 10)
	{
		cout << "N<10!, numbers go out of rectangle" << endl;
	}

}

int main()
{
	cout << "Zadachite se izpulnqvat podred" << endl;
	cout << "Zadacha 1" << endl;
	int Z;
	cin >> Z;
	int Z1 = Z;
	int counter = 0;
	while (Z1!=0)
	{
		Z1 /= 10;
		counter++;
	}

	const auto arrSize = counter;

	cout << counter << endl;

	//2 zadacha getSum(int Z)
	cin >> Z;
	int sum = getSum(Z);
	cout << sum << endl;
	getZMirrored();
	countDigitsInNumber();
	triangle();
	rectangle();
	rectangle2();
}