#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

using namespace std;
void arabToRom(unsigned int a)
{
	unsigned int number = a;

	char romanNumber[32];

	int digitsReversed[4];

	for (size_t i = 0; i < 4; i++)
	{
		digitsReversed[i] = number % 10;
		number /= 10;
	}

	int digits[4];

	int j = 0;
	for (int i = 3; i >= 0; i--)
	{
		digits[j] = digitsReversed[i];
		j++;
	}

	int positionArr = 0;
	switch (digits[0])
	{
	case 0: break;
	case 3: romanNumber[positionArr] = 'M'; digits[0]--; positionArr++;
	case 2: romanNumber[positionArr] = 'M'; digits[0]--; positionArr++;
	case 1: romanNumber[positionArr] = 'M'; digits[0]--; positionArr++; break;
	case 4: romanNumber[positionArr] = 'C'; romanNumber[positionArr + 1] = 'M'; positionArr += 2; break;
	default:
		break;
	}

	switch (digits[1])
	{
	case 0: break;
	case 9: romanNumber[positionArr] = 'C'; romanNumber[positionArr + 1] = 'M'; positionArr += 2; break;
	case 4: romanNumber[positionArr] = 'C'; romanNumber[positionArr + 1] = 'D'; positionArr += 2; break;

	case 3: romanNumber[positionArr] = 'C'; digits[1]--; positionArr++;
	case 2: romanNumber[positionArr] = 'C'; digits[1]--; positionArr++;
	case 1: romanNumber[positionArr] = 'C'; digits[1]--; positionArr++; break;

	case 8: romanNumber[positionArr] = 'D'; romanNumber[positionArr + 1] = 'C'; romanNumber[positionArr + 2] = 'C'; romanNumber[positionArr + 3] = 'C'; break;
	case 7: romanNumber[positionArr] = 'D'; romanNumber[positionArr + 1] = 'C'; romanNumber[positionArr + 2] = 'C'; break;
	case 6: romanNumber[positionArr] = 'D'; romanNumber[positionArr + 1] = 'C'; break;
	case 5: romanNumber[positionArr] = 'D'; break;
	default:
		break;
	}

	switch (digits[2])
	{
	case 0: break;
	case 9: romanNumber[positionArr] = 'X'; romanNumber[positionArr + 1] = 'C'; positionArr += 2; break;
	case 4: romanNumber[positionArr] = 'X'; romanNumber[positionArr + 1] = 'L'; positionArr += 2; break;

	case 3: romanNumber[positionArr] = 'X'; digits[2]--; positionArr++;
	case 2: romanNumber[positionArr] = 'X'; digits[2]--; positionArr++;
	case 1: romanNumber[positionArr] = 'X'; digits[2]--; positionArr++; break;

	case 8: romanNumber[positionArr] = 'L'; romanNumber[positionArr + 1] = 'I'; romanNumber[positionArr + 2] = 'I'; romanNumber[positionArr + 3] = 'I'; positionArr += 4; break;
	case 7: romanNumber[positionArr] = 'L'; romanNumber[positionArr + 1] = 'I'; romanNumber[positionArr + 2] = 'I'; positionArr += 3; break;
	case 6: romanNumber[positionArr] = 'L'; romanNumber[positionArr + 1] = 'I'; positionArr+=2; break;
	case 5: romanNumber[positionArr] = 'L'; positionArr++; break;
	default:
		break;
	}

	switch (digits[3])
	{
	case 0: break;
	case 9: romanNumber[positionArr] = 'I'; romanNumber[positionArr + 1] = 'X'; positionArr += 2; break;
	case 4: romanNumber[positionArr] = 'I'; romanNumber[positionArr + 1] = 'V'; positionArr += 2; break;

	case 3: romanNumber[positionArr] = 'I'; digits[3]--; positionArr++;
	case 2: romanNumber[positionArr] = 'I'; digits[3]--; positionArr++;
	case 1: romanNumber[positionArr] = 'I'; digits[3]--; positionArr++; break;

	case 8: romanNumber[positionArr] = 'V'; romanNumber[positionArr + 1] = 'I'; romanNumber[positionArr + 2] = 'I'; romanNumber[positionArr + 3] = 'I'; positionArr += 4; break;
	case 7: romanNumber[positionArr] = 'V'; romanNumber[positionArr + 1] = 'I'; romanNumber[positionArr + 2] = 'I'; positionArr += 3; break;
	case 6: romanNumber[positionArr] = 'V'; romanNumber[positionArr + 1] = 'I'; positionArr+=2; break;
	case 5: romanNumber[positionArr] = 'V'; positionArr++; break;
	default:
		break;
	}

	for (size_t i = 0; i < positionArr; i++)
	{
		cout << romanNumber[i];
	}
}

int main()
{
	cin.ignore();
	cout << "Welcome to Arabic to Roman Number Converter" << endl;
	Sleep(3000);
	cout << "Credits - Stati Kosev" << endl;
	Sleep(3000);
	cout << "Press ENTER to Start" << endl;
	cin.ignore();

	for (size_t i = 1; i < 4000; i++)
	{
		arabToRom(i);
		cout << " - " << i << endl;
	}
}
