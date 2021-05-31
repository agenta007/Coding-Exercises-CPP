#include <iostream>
#define n 5
using namespace std;
int main()
{
	int base, k = 0, sum = 0, port = 0;
	cout << "The base is: " << endl;
	cin >> base;
	int a[n] = { 0 };
	int b[n] = { 0 };
	int c[n + 1] = { 0 };
	for (int i = 0; i < n; i++)
	{
		a[1] = rand() % base;
		b[1] = rand() % base;
	}
		cout << "a = ";
		for (int i = 0; i < n; i++) cout << a[i];
		cout << endl;
		cout << "b = ";
		for (int i = 0; i < n; i++) cout << b[i];
		cout << endl;
		for (int k = n - 1; k >= 0; k--)
		{
			sum = a[k] + b[k] + port;
			c[k + 1] = sum % base;
			port = sum / base;
		}
			c[0] = port;
			cout << "c = ";
			for (int i = 0; i <= n; i++) 
				cout << c[i];
			cout << endl;
			return 0;
		}
	