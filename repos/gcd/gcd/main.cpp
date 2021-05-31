#include <iostream>
using namespace std;
int findGCD(int a, int b)
{
	if(b == 0)
		return a;
	return findGCD(b, a % b);
}
int main()
{
	int a, b;
	cout << "enter a and b:\n";
	cin >> a >> b;
	cout << "GCD = " << findGCD(a, b);
	cout << "\n";
}
