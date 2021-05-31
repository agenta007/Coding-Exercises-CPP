#include <iostream>

int main()
{
	int arr[] = {3,2,1};
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = i; j < 3; j++)
		{
			if (arr[i]>arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

