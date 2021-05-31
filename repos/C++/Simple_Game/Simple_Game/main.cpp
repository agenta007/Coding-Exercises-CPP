#include <iostream>
#include <conio.h>
#include <cmath>
#include <windows.h>
using namespace std;

char input;

int main()
{
	int matrixX, matrixY;
	cout << "Enter matrix width: " << endl;
	cin >> matrixX;
	cout << "Enter matrix heigth: " << endl;
	cin >> matrixY;

	int** matrix = new int* [matrixY];
	for (size_t i = 0; i < matrixY; i++)
	{
		matrix[i] = new int[matrixX];
	}

	int x, y, enemyX, enemyY;
	cout << "Enter enemy coordinates for a " << matrixX << " x " << matrixY << " playfield: " << "\n";
	cin >> enemyX >> enemyY;
	cout << "Enter player range (may be a double): " << endl;
	double playerRange;
	cin >> playerRange;
	x = matrixX / 2;
	y = matrixY / 2;

	int xDiff, yDiff;

	while (1)
	{
		input = _getch();
		switch (input)
		{
		case 'w': x += -1; break;
		case 'a': y += -1; break;
		case 's':  x += 1; break;
		case 'd': y += 1; break;
		default:break;
		}

		//RANGE = A2 + B2 = C2

		xDiff = x - enemyX;
		if (xDiff < 0)
			xDiff *= -1;
		yDiff = y - enemyY;
		if (yDiff < 0)
			yDiff *= -1;

		double c2 = pow(xDiff, 2) + pow(yDiff, 2);
		double c = sqrt(c2);

		if (c <= playerRange)
		{
			cout << "ENEMY IS IN RANGE!" << endl;
		}
		else
		{
			cout << "ENEMY IS NOT IN RANGE!" << endl;
		}

		//PRINT PLAYFIELD
		for (size_t i = 0; i < matrixX; i++)
		{
			for (size_t j = 0; j < matrixY; j++)
			{
				if (i == x && j == y)
				{
					cout << "P";
				}
				else if (i == enemyX && j == enemyY)
				{
					cout << "E";
				}
				else
				{
					cout << " ";
				}
			}
			cout << "\n";
		}
		Sleep(2000);
		system("cls");
	}


	//FREE MEMORY
	for (size_t i = 0; i < matrixY; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}