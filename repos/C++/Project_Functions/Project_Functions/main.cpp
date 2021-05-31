#include <iostream>
using namespace std;
int	main() 
{
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand();
		cout << r << endl;
		r = r % 25 + 15;
		cout << r << endl;
	}

	char a = 0;
	int aInt = a - '0';

	for (size_t i = 0; i < 100; i++)
	{
		a = i;
		cout << a << endl;
	}
	cout << a << aInt << endl;
}