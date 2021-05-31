#include <iostream>

using namespace std;

void romb_draw()
{
	int N;
	cin >> N;

	int ediniciCount = 1;
	for (size_t j = 0; j < N; j++)
	{
		for (size_t i = 0; i < N - j - 1; i++)
		{
			cout << "0";
		}

		for (size_t i = 0; i < ediniciCount; i++)
		{
			cout << "1";
		}
		ediniciCount += 2;

		for (size_t i = 0; i < N - j - 1; i++)
		{
			cout << "0";
		}
		cout << "\n";
	}

	int arrSz = N * 2 - 1;

	int* arr = new int[arrSz];

	for (size_t i = 0; i < arrSz; i++)
	{
		arr[i] = 1;
	}

	for (size_t i = 0; i < N - 1; i++)
	{
		arr[i] = 0;
		arr[arrSz - i - 1] = 0;
		for (size_t j = 0; j < arrSz; j++)
		{
			cout << arr[j];
		}
		cout << "\n";
	}

}

int main()
{
	//syzdavane na matrica
	int n;
	cin >> n;
	int** matrix = new int*[n];

	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = 1;
		}
	}

	//grebennovo otpechatvane
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i<= n/7)
			{
				cout << matrix[i][j] << " ";
			}
			else
			{
				if (j % 2 == 0)
				{
					cout << matrix[i][j] << " ";
				}
				else
				{
					cout << "  ";
				}
			}
		}
		cout << "\n";
	}



	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

