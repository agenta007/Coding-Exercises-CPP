#include <iostream>
using namespace std;
int main()
{
	cout << "Enter n:\n";
	int n;
	cin >> n;
	int** matrix = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = i * j;
		}
	}
	cout << "i*j-generated matrix:\n";

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "subdiagonal: \n";

	for (int i = 0; i < n; ++i)
	{
		cout << matrix[i][n-i-1] << " ";
	}
	cout << "\n";
	return 0;
}