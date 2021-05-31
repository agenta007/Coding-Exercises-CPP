#include <iostream>
#include <new>
using namespace std;

int main()
{
	int a, b;
	int* ap,* bp;
	cin >> a;
	cin >> b;
	ap = &a;
	bp = &b;
	int sum = *ap + *bp;

	int* darr = nullptr;
	darr = new int[a];
	int diff = *ap - *bp;
	cout << sum << endl;
	cout << abs(diff) << endl;
}