#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool checkPrime(int a)
{
	if (a==2 || a==1)
	{
		return true;
	}
	int n = 2;
	while (n!=a)
	{
		if (a % n == 0)
			return false;
		n++;
	}
	return true;
}

void sumOfPowers()
{
	int N;
	cout << "Enter N" << endl;
	cin >> N;

	int N2 = N;

	//Algoritymyt raboti i bez granici
	//try if(true)
	if (N > 9 && N < 1011)
	{
		int iterator = 0;
		int arr[32];
		while (N != 0)
		{
			int counter = 0;
			int dvoikata = 2;
			while (dvoikata <= N)
			{
				dvoikata *= 2;
				counter++;
			}
			N -= pow(2, counter);
			arr[iterator] = counter;
			iterator++;
		}
		for (size_t i = 0; i < iterator; i++)
		{
			if (i + 1 == iterator)
			{
				cout << "2 * " << arr[i] << " = " << N2;
				return void();
			}
			else
			{
				cout << "2 * " << arr[i] << " + ";
			}
		}
	}
	else
	{
		cout << "Invalid N, [10...1010]" << endl;
	}

}

void guessTheNumber()
{
	cout << "Think of a number between 1-100." << endl;
	int r = rand() % 100 + 1;

	int i = 0;
	bool allNumbers[101];
	for (auto& x : allNumbers)
		x = false;
	while (true)
	{
		while (r < 0)
			r += rand() % 100 + 1;
		while(r > 100)
			r -= rand() % 100 + 1;

		while (allNumbers[r]==true)
		{
			r = rand() % 100 + 1;
		}

		allNumbers[r] = true;

		cout << r << endl;
		int input;
		cin >> input;
		if (input == 0) 
		{
			cout << "I gueessed the number, yaay. Tries: " << i<< endl; break;
		}
		else if (input == -1)
			r -= rand() % 100 + 1;
		else if (input == 1)
			r += rand() % 100 + 1;

		i++;
	}
}

void kanonichnoRazlagane()
{
	int N, M;
	cin >> N;
	cin >> M;
	int originalN = N;
	
	unsigned int sum = 0;
	while (N!=M)
	{
		sum += N;
		N++;
	}

	unsigned int origSum = sum;

	int multipliers[64];
	int i = 0;
		for (size_t j = 2; j < sum; j++)//vurvi po prostite msumojiteli
		{
			while (!checkPrime(j))
				j++;
			while (sum % j == 0)
			{
				multipliers[i] = j;
				i++;
				sum /= j;
			}
			if (sum == 1)
				break;
		}

		for (size_t j = 0; j < i; j++)
		{
			if(j+1==i)
			{
				cout << multipliers[j] << " = " << origSum << endl;
				break;
			}
			cout << multipliers[j] << " * ";
		}
}

void zadacha4()
{
	string n;
	cin >> n;

	char a0 = n[0];
	char a1 = n[1];
	char a2 = n[2];

	int a = a0 - 48;
	int b = a1 - 48;
	int c = a2 - 48;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int main()
{
	//cout << "Zadacha 1" << endl;
	//sumOfPowers();
	//cout << "Zadacha 2" << endl;
	guessTheNumber();
	//kanonichnoRazlagane();
	//zadacha4();
}
