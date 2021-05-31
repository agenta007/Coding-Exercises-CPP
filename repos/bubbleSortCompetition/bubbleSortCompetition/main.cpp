#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;
int bubbleSortNaive()
{
	//int arr[]{ 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464 };
	int arr[]{41, 6334, 11478, 15724, 18467, 24464, 26500, 26962, 29358};
	int arrSz = sizeof(arr) / sizeof(int);

	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < arrSz; i++)
	{
		for (size_t j = 0; j < arrSz - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "\nTime: " << duration.count();
	return 0;
}

int bubbleSortNonNaive()
{
	//int arr[]{ 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464 };
	int arr[]{ 41, 6334, 11478, 15724, 18467, 24464, 26500, 26962, 29358 };
	int arrSz = sizeof(arr) / sizeof(int);
	auto start = chrono::high_resolution_clock::now();

	for (size_t i = 0; i < arrSz; i++)
	{
		int currentInversions = 1;
		for (size_t j = 0; j < arrSz - 1; j++)
		{
			if (currentInversions != 0)
			{
				currentInversions = 0;
			}
			else
			{
				i += arrSz;
				break;
			}
			if (arr[j + 1] < arr[j])
			{
				++currentInversions;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "\nTime: " << duration.count();



	return 0;
}

int main()
{
	cout << "Testing on same array |41, 6334, 11478, 15724, 18467, 24464, 26500, 26962, 29358|\n";
	cout << "Naive\n";
	bubbleSortNaive();
	cout << "\nNon-naive\n";
	bubbleSortNonNaive();
	return 0;
}