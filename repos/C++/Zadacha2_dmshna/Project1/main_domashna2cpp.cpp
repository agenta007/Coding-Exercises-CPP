#include <iostream>
using namespace std;
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	//X I Y ZADACHI PO C I JAVA ||| Z - TIME
	int xCoef = 1;
	int yCoef = 0;

	//BROIM KOLKO ZADACHI MOJE DA RESHIM NA C / TE SA S PRIORITET!
	while (x * xCoef <= z)
	{
		if (x * xCoef == z)
		{
			cout << xCoef << " " << yCoef << "\n";
			return 0;
		}
		xCoef++;
	}

	//SLED TOVA POCHVAME NA OBRATNO DA OTBROQVAME I DA TURSIM Y, AKO NADVHURLIM VREMETO NAMALQME X S 1, Y=1 I POVTARQME

	xCoef--;
	yCoef++;
	int sum = x * xCoef + y * yCoef;
	while (xCoef != 0)
	{
		sum = x * xCoef + y * yCoef;
		while (sum <= z)
		{
			sum = x * xCoef + y * yCoef;
			if (sum == z)
			{
				cout << xCoef << " " << yCoef << "\n";
				return 0;
			}
			yCoef++;
		}
		yCoef = 1;
		xCoef--;
	}
	cout << "Could't find matchin X and Y" << endl;
	return 0;
}