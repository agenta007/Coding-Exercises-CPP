#include <iostream>
using namespace std;
int main()
{
	const int rows = 4, cols = 4;
	int* matrica = new int[rows*cols];
	for (int i = 0; i < 16; i++)
	{
		matrica[i] = i+1;
		//matrica[i + (i * cols)] = i;

	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrica[j + (i * cols)] << " ";
		}
		cout << "\n";
	}
	printf("msg\n");
	return 0;
}