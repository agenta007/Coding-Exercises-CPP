#include <iostream>
using namespace std;
int insertionSort()
{
	int arr[]{17,14,4,16,48,11,1,6,7,8};
	int arrSz = sizeof(arr) / sizeof(int);
	for (auto& i : arr)
	{
		i = rand();
	}
	for (auto& i : arr)
	{
		cout << i << " ";
	}
	cout << "\n";
	for (int i = 1; i < sizeof(arr)/sizeof(int); ++i)
	{
		int tmp = arr[i];
		int j = i;
		while (j>0 &&arr[j - 1] > tmp)
		{
			--j;
		}
		int tmp2 = arr[j];
		for (int k = i; k != j; --k)
		{
			arr[k] = arr[k - 1];
		}
		arr[j] = tmp;
		//arr[i] = tmp2;
	}
	for (auto& i : arr)
	{
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}

int bublleSort()
{
	int arr[]{ 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464 };
	char carr[] {'S', 'T', 'A', 'T', 'I', ' ', 'K', 'O', 'S', 'E', 'V', '\0', };
	int arrSz = sizeof(arr) / sizeof(int);
	for (size_t i = 0; i < arrSz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
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
	for (size_t i = 0; i < arrSz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}

int reversionSort(int *arr)
{
	//int arr[]{ 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464 };
	for (size_t i = 0; i < 15; ++i)
	{
		int min = arr[i];
		int flag = i;
		for (size_t j = i; j < 15; ++j)
		{
			if (arr[j]<min)
			{
				min = arr[j];
				flag = j;
			}
		}
		int tmp = arr[i];
		arr[i] = min;
		arr[flag] = tmp;

	}
	for (size_t i = 0; i < 15; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}

int bublleSortChars()
{
	char carr[]{ 'S', 'T', 'A', 'T', 'I', ' ', 'K', 'O', 'S', 'E', 'V', '\0', };
	int arrSz = sizeof(carr) / sizeof(char);
	for (size_t i = 0; i < arrSz; i++)
	{
		cout << carr[i] << " ";
	}
	cout << "\n";
	for (size_t i = 0; i < arrSz; i++)
	{
		for (size_t j = 0; j < arrSz - 1; j++)
		{
			if (carr[j + 1] < carr[j])
			{
				int tmp = carr[j];
				carr[j] = carr[j + 1];
				carr[j + 1] = tmp;
			}
		}
	}
	for (size_t i = 0; i < arrSz; i++)
	{
		cout << carr[i] << " ";
	}
	cout << "\n";
	return 0;
}

int reversionSortV2()
{
	int arr[]{ 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464 ,1668645,543717,123456,98765,151515};
	for (size_t i = 0; i < 15; ++i)
	{
		int sravneniq = 0;
		int min = arr[i];
		int flag = i;
		for (size_t j = i; j < 15; ++j)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				flag = j;
			}
			++sravneniq;
		}
		int tmp = arr[i];
		arr[i] = min;
		arr[flag] = tmp;
		cout << "\nSystoqnie: ";
		for (size_t i = 0; i < 15; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\nObhojdane: " << i + 1 << ", Broi sravneniq: " << sravneniq;
	}
	cout << "\n";
	return 0;
}

int main()
{
	reversionSortV2();
	int arrRev[15];
	int *arrP = arrRev;
	for (size_t i = 0; i < 10; i++)
	{
		for (auto& num : arrRev)
		{
			num = rand();
			cout << num << " ";
		}
		cout << "\n";
		reversionSort(arrP);
		cout << "\n";
	}
	bublleSortChars();
	for (size_t i = 0; i < 10; i++)
	{
		insertionSort();
		cout << "\n";
	}
	int middle, left, right, match, n;
	n = 16;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	cin >> match;
	left = 0;
	right = n - 1;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (arr[middle] == match)
		{
			cout << arr[middle] << " has index " << middle << "\n";
			return 0;
		}
			
		if (arr[middle] > match)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
}