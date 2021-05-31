#include <iostream>
#include <cmath>
using namespace std;

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int main()
{
	cout << "Vyvedete broi redove i koloni\n";
	int rows, columns;
	cin >> rows >> columns;

	int** matrix = new int*[rows];

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}

	//zapylvane
	double r;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			r = 2000;
			while (r <= -16.16 || r > 1234.1)
			{
				r = fRand(-16.16, 1234.1);
			}
			matrix[i][j] = r;
		}
	}

	//razpechatvane
	int position = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j+=0)
		{
			if (position == 2)
			{
				cout << "\n";
				position = 0;
			}

			if (position == 0)
			{
				cout << matrix[i][j] << ", ";
				position++;
				j++;
			}
			if (position == 1)
			{
				cout << matrix[i][j];
				position++;
				j++;
			}
		}
	}

	cout << endl;
	cout <<"****************************" << endl;


	double average = 0;
	double sum = 0;
	double counter = 0;
	double nechetniSum = 0;
	double negativesSum = 0;
	double naiBlizukOtlqvo = 0;
	double naiBlizukOtdqsno = 10000;



	//stoinostite sa deseticni drobi => subirame stoinostite na elemtnite s nechetni indexi
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			sum += matrix[i][j];
			counter++;

			if (j % 2 != 0)
			{
				nechetniSum += matrix[i][j];
			}

			if (matrix[i][j] < 0)
			{
				negativesSum += matrix[i][j];
			}

			if (matrix[i][j] > naiBlizukOtlqvo && matrix[i][j] < average)
			{
				naiBlizukOtlqvo = matrix[i][j];
			}

			if (matrix[i][j] < naiBlizukOtdqsno && matrix[i][j] > average)
			{
				naiBlizukOtdqsno = matrix[i][j];
			}
		}
	}
	average = sum / counter;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (j % 2 == 0 && j != 0)
			{
				double tmp;
				tmp = matrix[i][j];
				matrix[i][j] = matrix[i][j - 1];
				matrix[i][j - 1] = tmp;
				matrix[i][j-1] += pow(i,2) + pow(j,2);
			}

			if (i % 2 == 0 && i != 0)
			{
				double tmp;
				tmp = matrix[i][j];
				matrix[i][j] = matrix[i - 1][j];
				matrix[i - 1][j] = tmp;
				matrix[i - 1][j] = pow(i, 2) + pow(j, 2);
			}
		}
	}

	position = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j += 0)
		{
			if (position == 2)
			{
				cout << "\n";
				position = 0;
			}

			if (position == 0)
			{
				cout << matrix[i][j] << ", ";
				position++;
				j++;
			}
			if (position == 1)
			{
				cout << matrix[i][j];
				position++;
				j++;
			}
		}
	}

	cout << "Sum of all elements is:" << sum << "\n";
	cout << "Sum of odd elements is:" << nechetniSum << "\n";
	cout << "Sum of negative elements is:" << negativesSum << "\n";
	cout << "Sum of the two elements, that are closest to the average equals: " << naiBlizukOtlqvo + naiBlizukOtdqsno << "\n";

	cout << "The matrix in normal form.\n";

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}



	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}
