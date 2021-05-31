#include <iostream>
using namespace std;
int main()
{
	int arr[]{9,8,7,6,5,4,3,2,1};
	int arrSz = sizeof(arr) / sizeof(int);
	int inversions[sizeof(arr) / sizeof(int)];
	for (int& num : inversions)
		num = 0;
	for (size_t i = 0; i < arrSz; i++)
	{
		for (size_t j = 0; j < arrSz; j++)
		{
			if (arr[j] < arr[i])
			{
				++inversions[i];
			}
		}
	}
	int sum = 0;
	for (size_t i = 0; i < arrSz; i++)
	{
		cout << "Index[" << i << "] had " << inversions[i] << " inversions.\n";
		sum += inversions[i];
	}
	cout << "Summed up the inversions are " << sum << ".\n";
	cout << "The sum of inversions in arrays with inversed order can be calculated with the theorem n*(n-1)/2 = " << arrSz * (arrSz - 1) / 2 << "\n";
	return 0;
}