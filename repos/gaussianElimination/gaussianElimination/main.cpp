#include <iostream>
using namespace std;
int main()
{
	cout << "Enter matrix dimensions m x n: ";
	double m, n;
	cin >> m >> n;
	cout << "\nNow enter a " << m << " x " << n << " matrix to be solved and printed\n";
	double** matrix = new double* [m];
	for (size_t i = 0; i < m; i++)
	{
		matrix[i] = new double[n];
	}
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			double input;
			cin >> input;
			matrix[i][j] = input;
		}
	}

	//tursene na gornotriagalna  Forma(ref)

	for (size_t i = 0; i < m; i++)
	{
		double delitel = matrix[i][i];
		for (size_t j = 0; j < n; j++)
		{
			if (delitel == 0)
			{
				break;
			}
			matrix[i][j] /= delitel;
		}

		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}

		cout << "\n";

		//cout << "Razdelihme reda na " << matrix[i][i] <<"\n";


		for (size_t k = i+1; k < m; k++)
		{
			double coef = matrix[k][i];
			for (size_t l = 0; l < n; l++)
			{
				matrix[k][l] -= matrix[i][l] * coef;
			}
		}

		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		//cout << "Izvadihme gorniq ot dolniq red\n";
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	for (size_t i = 0; i < m; i++)
	{
		delete matrix[i];
	}
	delete[] matrix;
	return 0;
}