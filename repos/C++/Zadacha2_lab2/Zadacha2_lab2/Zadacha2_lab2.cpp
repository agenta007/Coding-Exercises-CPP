#include <iostream>
using namespace std;
int main()
{
	//EUCLIDUS ALGORITHM
	int a, b;
	cin >> a >> b;

	int aTmp = a;
	int bTmp = b;
	int c = a;
	int opCounter = 0;
	while (a % b != 0)
	{
		opCounter++;
		c = a % b;
		a = b;
		b = c;
	}

	a = aTmp;
	b = bTmp;

	int** matrix = new int*[4];

	int matrixCol = opCounter + 2;
	for (size_t i = 0; i < 4; i++)
	{
		matrix[i] = new int[matrixCol];
	}

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < matrixCol; j++)
		{
			matrix[i][j] = 0;
		}
	}


	//SETTING UP CONSTANTS
	matrix[2][0] = 1;
	matrix[2][1] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 1;
	matrix[0][0] = a;
	matrix[0][1] = b;

	//FILLING FIRST LINE
	for (size_t i = 2; i < matrixCol; i++)
	{
		matrix[0][i] = a % b;
		a = b;
		b = matrix[0][i];
	}
	int GCD = matrix[0][opCounter+1];
	if (GCD == 1)
	{
		cout << aTmp << " * " << bTmp << " - " << bTmp << " * " << aTmp << " = 0";
		return 0;
	}
	a = aTmp;
	b = bTmp;

	//for (size_t i = 0; i < matrixCol; i++)
	//{
	//	cout << matrix[0][i] << " ";
	//}
	//cout << "\n";

	//DOTUKA VZEHME PYRVIQ RED ^^

	int times = 1;

	//for (size_t i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < matrixCol; j++)
	//	{
	//		cout << matrix[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	for (size_t i = 1; i < matrixCol; i++)
	{
		while (matrix[0][i] * times < matrix[0][i-1])
		{
			times++;
		}

		if (times * matrix[0][i] == matrix[0][i-1])
		{
			times++;
		}

		matrix[1][i] = times-1;
		times = 1;
	}

	int x, y;

	for (size_t i = 2; i < matrixCol; i++)
	{
		matrix[2][i] = (matrix[2][i - 2] + matrix[2][i - 1]) * matrix[1][i];
		x = matrix[2][i];
	}

	for (size_t i = 2; i < matrixCol; i++)
	{
		matrix[3][i] = (matrix[3][i - 2] + matrix[3][i - 1]) * matrix[2][i];
		y = matrix[3][i];
	}
	
	for (size_t i = 2; i < 10; i++)
	{
		while (x % i == 0 and y % i == 0)
		{
			x /= i;
			y /= i;
		}
	}

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < matrixCol; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	cout << a << " * " << x << " - " << b << " * " << y << " = " << GCD;

	for (size_t i = 0; i < 4; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
