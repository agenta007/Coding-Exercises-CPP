#include <iostream>

int neo_matrix() {
	int n;
	std::cin >> n;
	int** matrix = new int* [n];

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

	for (size_t i = 0; i < n; i++)
	{
		matrix[i][i] = 0;
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int neo_matrix_reversed()
{
	int N;
	std::cin >> N;

	int** matrix = new int* [N];

	for (size_t i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			matrix[i][j] = 1;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (j != i)
				matrix[i][j] = 0;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < N; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
	return 0;
}

int main()
{
	if (false);
		std::cout << 1 << std::endl;
}

