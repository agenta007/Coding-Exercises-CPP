#include <random>
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

void pechatane()
{
	int arrLength;
	std::cin >> arrLength;

	//int* arr = new int[arrLength];
	int arr[10];
	for (size_t i = 0; i < arrLength; i++)
	{
		arr[i] = i;
	}

	for (size_t i = 0; i < arrLength; i += 3)
	{
		if (!(i + 3 > arrLength - 1))
			std::cout << arr[i] << ", " << arr[i + 1] << ", " << arr[i + 2] << "\n";
		else
		{
			int ostavashtiElementi = arrLength - i - 1;
			switch (ostavashtiElementi)
			{
			case 0: break;
			case 1: std::cout << arr[i] << std::endl; break;
			case 2: std::cout << arr[i] << ", " << arr[i + 1] << std::endl; break;
			}
		}
	}
}

void ocenkiTable()
{
	int N;
	std::cin >> N;
	int* predmetA = new int[N];
	int* predmetB = new int[N];
	int* predmetC = new int[N];
	int* predmetD = new int[N];
	double* uspeh = new double[N];
	int bezDvoiki = 0;
	double max = 0;
	int studentNumber;

	for (size_t i = 0; i < N; i++)
	{
		int randNotes[4];
		randNotes[0] = rand() % 6 + 2;
		randNotes[1] = rand() % 6 + 2;
		randNotes[2] = rand() % 6 + 2;
		randNotes[3] = rand() % 6 + 2;
		for (size_t j = 0; j < 4; j++)
		{
			while (randNotes[j] < 2)
			{
				randNotes[j]++;
			}
			while (randNotes[j] > 6)
			{
				randNotes[j]--;
			}
		}
		predmetA[i] = randNotes[0];
		predmetB[i] = randNotes[1];
		predmetC[i] = randNotes[2];
		predmetD[i] = randNotes[3];
	}

	for (size_t i = 0; i < N; i++)
	{
		uspeh[i] = (predmetA[i] + predmetB[i] + predmetC[i] + predmetD[i]) / 4.;
		if (predmetA[i] != 2 && predmetB[i] != 2 && predmetC[i] != 2 && predmetD[i] != 2)
			bezDvoiki++;
	}

	for (size_t i = 0; i < N; i++)
	{
		if (uspeh[i] > max)
			max = uspeh[i];
	}

	for (size_t i = 0; i < N; i++)
	{
		if (uspeh[i] == max)
			studentNumber = i;
	}

	std::cout << "Student Number with score " << max << " is NBU F-" << studentNumber << "\n" << "And the score table looks like:\n";

	for (size_t i = 0; i < N; i++)
	{
		if (i != N - 1)
			std::cout << predmetA[i] << ", ";
		else
			std::cout << predmetA[i] << "\n";
	}

	for (size_t i = 0; i < N; i++)
	{
		if (i != N - 1)
			std::cout << predmetB[i] << ", ";
		else
			std::cout << predmetB[i] << "\n";
	}

	for (size_t i = 0; i < N; i++)
	{
		if (i != N - 1)
			std::cout << predmetC[i] << ", ";
		else
			std::cout << predmetC[i] << "\n";
	}

	for (size_t i = 0; i < N; i++)
	{
		if (i != N - 1)
			std::cout << predmetD[i] << ", ";
		else
			std::cout << predmetD[i] << "\n";
	}

	delete[] predmetA;
	delete[] predmetB;
	delete[] predmetC;
	delete[] predmetD;
	delete[] uspeh;

}

void umnojenieNaMatrici()
{
	//MATRIX MULTIPLIER
	
	//SETUP VARIABLES AND TWO ENTRY MATRIX
	int m, n, k, l;
	cin >> m >> n >> k >> l;
	int** matrix1 = new int* [m];
	int** matrix2 = new int* [k];

	//ALLLOCATING ARRAY FOR EVERY LINE IN THE TWO MATRIX
	for (size_t i = 0; i < m; i++)
	{
		matrix1[i] = new int[n];
	}

	for (size_t i = 0; i < k; i++)
	{
		matrix2[i] = new int[l];
	}

	//CHECK IF MATRIX ARE VALID, IF THEY CAN BE MULTIPLIED
	if (m != l || n != k)
	{
		cout << "Can't multipy these matrix" << endl;
		return;
	}

	//GETTING INPUT COEFFICENTS IN MATRIX
	cout << "Enter numbers in first matrix line by line" << endl;

	for (size_t i = 0; i < m; i++)
	{
		int currentLine;
		int* currentLineArr;
		currentLineArr = new int[n];
		cin >> currentLine;

		for (size_t j = 0; j < n; j++)
		{
			if (j == 0)
			{
				currentLineArr[j] = currentLine % 10;
			}
			else
			{
				currentLine /= 10;
				currentLineArr[j] = currentLine % 10;
			}
		}

		int matrixLinePos = 0;
		for (int j = n - 1; j != -1; j--)
		{
			matrix1[i][matrixLinePos] = currentLineArr[j];
			matrixLinePos++;
		}
	}

	cout << "Enter numbers in second matrix line by line" << endl;


	for (size_t i = 0; i < m; i++)
	{
		int currentLine;
		int* currentLineArr;
		currentLineArr = new int[n];
		cin >> currentLine;

		for (size_t j = 0; j < n; j++)
		{
			if (j == 0)
			{
				currentLineArr[j] = currentLine % 10;
			}
			else
			{
				currentLine /= 10;
				currentLineArr[j] = currentLine % 10;
			}
		}

		int matrixLinePos = 0;
		for (int j = n - 1; j != -1; j--)
		{
			matrix1[i][matrixLinePos] = currentLineArr[j];
			matrixLinePos++;
		}
	}


	//ALLOCATING RESULT MATRIX
	int** matrix3 = new int* [m];

	for (size_t i = 0; i < m; i++)
	{
		matrix3[i] = new int[n];
	}

	//MULTIPLIFICATION

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			int sum = 0;

			int* coefficients = new int[m];
			for (size_t k = 0; k < m; k++)
			{
				coefficients[k] = matrix1[i][k] * matrix2[k][0];
			}

			for (size_t j = 0; j < m; j++)
			{
				sum += coefficients[j];
			}

			matrix3[i][j] = sum;
		}
	}

	//PRINTING RESULT MATRIX
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if(j+1 != n)
				cout << matrix3[i][j] << ", ";
		}
		cout << "\n";
	}

	//DELETE GARBAGE
	for (size_t i = 0; i < m; i++)
	{
		delete[] matrix3[i];
	}
	delete[] matrix3;

	for (size_t i = 0; i < m; i++)
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;

	for (size_t i = 0; i < k; i++)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
}

void dynamicArrTest() 
{

}

int main()
{
	//MATRIX MULTIPLIER

	//SETUP VARIABLES AND TWO ENTRY MATRIX
	cout << "Enter dimensions of matrices. First dimension that is given must be shorter. ex: 4 6 6 4 \nBe careful not every two matrices can be multiplied!\n";
	int m, n, k, l;
	cin >> m >> n >> k >> l;
	int** matrix1 = new int* [m];
	int** matrix2 = new int* [k];

	//ALLLOCATING ARRAY OF INTS FOR EVERY LINE IN THE TWO MATRICES
	for (size_t i = 0; i < m; i++)
	{
		matrix1[i] = new int[n];
	}

	for (size_t i = 0; i < k; i++)
	{
		matrix2[i] = new int[l];
	}

	//CHECK IF MATRIX ARE VALID, IF THEY CAN BE MULTIPLIED
	if (m != l)
	{
		cout << "Can't multipy these matrces" << endl;
		return 0;
	}

	//GETTING INPUT COEFFICENTS IN MATRIX
	cout << "Enter every line of first matrix :" << endl;

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> matrix1[i][j];
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << matrix1[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "Enter lines of second matrix:\n";

	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < l; j++)
		{
			cin >> matrix2[i][j];
		}
	}

	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < l; j++)
		{
			cout << matrix2[i][j] << " ";
		}
		cout << "\n";
	}

	//ALLOCATING RESULT MATRIX
	int** matrix3 = new int* [m];

	for (size_t i = 0; i < m; i++)
	{
		matrix3[i] = new int[l];
	}

	//MULTIPLIFICATION

	for (size_t red = 0; red < m; red++)
	{
		int izmestvane = 0;
		for (size_t kolona = 0; kolona < l; kolona++)
		{
			int sum = 0;
			int a, b, currentMultiplication;
			for (size_t currentLineMember = 0; currentLineMember < n; currentLineMember++)
			{
				a = matrix1[red][currentLineMember];
				b = matrix2[currentLineMember][izmestvane];
				currentMultiplication = a*b;
				sum += currentMultiplication;
			}
			izmestvane++;
			matrix3[red][kolona] = sum;
		}
	}

	//PRINTING RESULT MATRIX
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < l; j++)
		{
			if (j+1  != l)
				cout << matrix3[i][j] << " ";
			else
				cout << matrix3[i][j];
		}
		cout << "\n";
	}

	//DELETE GARBAGE
	for (size_t i = 0; i < m; i++)
	{
		delete[] matrix3[i];
	}
	delete[] matrix3;

	for (size_t i = 0; i < m; i++)
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;

	for (size_t i = 0; i < k; i++)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
	return 0;
}
