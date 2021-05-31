#include <iostream>
#include <string>
using namespace std;

int task2(char allSymbols[], int setBitMask[])
{
	int bitmasklength = 10;
	int cntTrues = 0;
	for (size_t i = 0; i < bitmasklength; i++)
	{
		if (setBitMask[i] == 1)
		{
			cntTrues++;
		}
	}

	int broiZaPrintene;
	int broiZaPreskachane;
	if (cntTrues % 2 != 0)
	{
		broiZaPrintene = (cntTrues / 2) + 1;
		broiZaPreskachane = cntTrues / 2;
	}
	else
	{
		broiZaPrintene = cntTrues / 2;
		broiZaPreskachane = cntTrues / 2;

	}

	int edinichkiCount = 0;
	for (int i = 9; i > -1; i--)
	{
		if (setBitMask[i] == 1 && edinichkiCount != broiZaPreskachane)
		{
			edinichkiCount++;
		}
		else if (setBitMask[i] == 1)
		{
			cout << allSymbols[i];
		}
	}
	cout << endl;
	return 0;
}

int task3(char bukvi[], char cStr[])
{
	char highestAsci = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if (highestAsci < bukvi[i])
			highestAsci = bukvi[i];
	}

	int cipherDiff = highestAsci - 'a' ;

	char cStrCoded[18];
	int cStrCodedPos = 0;

	char codedChar;
	int izmestvane;
	for (size_t i = 0; i < 17; i++)
	{
		if (cStr[i] < 91 && cStr[i] > 64 && cStr[i]+cipherDiff > 90)
		{
			izmestvane = -25;
		}
		else if(cStr[i] < 122 && cStr[i] > 96 && cStr[i] + cipherDiff > 122)
		{
			izmestvane = -25;
		}
		else
		{
			izmestvane = 0;
		}
		codedChar = cStr[i] + cipherDiff + izmestvane;
		cStrCoded[cStrCodedPos++] = codedChar;
		if (cStr[i] == ' ' || cStr[i] == '!')
		{
			cStrCoded[--cStrCodedPos] = cStr[i];
			cStrCodedPos++;
		}

	}
	for (size_t i = 0; i < 17; i++)
	{
		cout << cStrCoded[i];
	}
	cout << endl;
	return 0;
}

int main()
{
	int set1[] = {5, 2, 3, 8, 1 ,6 ,4 , 12, 9, 10};
	int set2[] = { 6, 11, 8, 2, 5 };

	int minEl = 2100000;
	int maxEl = 0;

	bool isItIn;
	for (size_t i = 0; i < 10; i++)
	{
		isItIn = false;
		for (size_t j = 0; j < 5; j++)
		{
			if (set1[i] == set2[j])
			{
				isItIn = true;
				break;
			}
		}
		if (!isItIn)
		{
			if (set1[i] > maxEl)
			{
				maxEl = set1[i];
			}
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		isItIn = false;
		for (size_t j = 0; j < 5; j++)
		{
			if (set1[i] == set2[j])
			{
				isItIn = true;
				break;
			}
		}
		if (!isItIn)
		{
			if (set1[i] < minEl)
			{
				minEl = set1[i];
			}
		}
	}
	cout << maxEl << " - " << minEl << " = " << maxEl - minEl << endl;

	//TASK2
	char symbols[] = { 'e', 'U', 'c', 'b', 'B', 'N', 'J', 'x', 'n', 'Z' };
	int subsetBitmask[] = { 0, 1, 0, 0, 1, 1, 1, 0, 1, 1 };
	task2(symbols, subsetBitmask);
	char bukviMnojestvo[] = {'e', 's', 'i', 'g'};
	char cStr[] = "Coding is an art!";
	task3(bukviMnojestvo, cStr);
}