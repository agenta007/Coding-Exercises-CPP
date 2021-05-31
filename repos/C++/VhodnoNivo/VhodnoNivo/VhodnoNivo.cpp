#include <iostream>
#include <cmath>
using namespace std;

float roundFloat(float numberToRound)
{
	float newFloat = (int)(numberToRound * 100 + .5);
	return (float)newFloat / 100;
}

int main()
{
	float numMin, numMax;
	cout << "Enter minimum random number \n"; cin >> numMin;
	cout << "Enter maximum random number \n"; cin >> numMax;

	float randomNum = numMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (numMax - numMin)));
	randomNum = roundFloat(randomNum);
	bool guessedNumber = false;
	float tryCount = 0;
	float checkNum;
	cout << "C++ picked a random number\n";
	cout << "Try and guess the number \n";
	while (!guessedNumber)
	{
		cin >> checkNum;
		tryCount++;
		if (checkNum == randomNum)
		{
			guessedNumber = true;
		}
		else
		{
			cout << "Try again :)\n";
		}
	}
	cout << "Congratulations you won and it took you only " << tryCount << " tries to guess the number\n";
}