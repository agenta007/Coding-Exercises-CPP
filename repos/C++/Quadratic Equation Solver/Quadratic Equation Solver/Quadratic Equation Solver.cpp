#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	cout << "Quadratic equation solver\n";
	cout << "Enter a b c separated by space:\n";
	int a, b, c;
	string line;
	cin;
	getline(cin, line);

	a = line[0] - '0';
	b = line[2] - '0';
	c = line[4] - '0';

	int D = pow(b, 2) - 4 * a * c;
	int x1 = -b + sqrt(D);
	int x2 = -b - sqrt(D);

	cout << "x1 = " << x1 << "\n";
	cout << "x2 = " << x2 << "\n";
}
