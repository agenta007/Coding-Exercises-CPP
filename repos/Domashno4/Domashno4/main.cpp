#include "Manager.h"
#include <random>
using namespace std;
int main()
{
	int n, r;
	cout << "Enter number of employees: " << endl;
	cin >> n;
	char* pc1 = "test string";
	Employee** staff = new Employee * [n];
	for (size_t i = 0; i < n; i++)
	{
		r = rand() % 3 + 1;
		switch (r)
		{
		case 1:
			staff[i] = new Employee("Basic Employee");
		default:
			break;
		}
		staff[i] = 
	}
	return 0;
}