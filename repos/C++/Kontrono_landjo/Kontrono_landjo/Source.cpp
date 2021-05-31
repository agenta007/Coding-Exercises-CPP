#include <iostream>
using namespace std;
int main()
{
	int counter = 0;
	int delimo = 0;

	while (delimo != 400)
	{
		if (delimo % 3 == 0 && delimo % 7 != 0 && delimo % 11 != 0)
		{
			cout << delimo << endl;
			counter++;
			delimo++;
		}
		if (delimo % 3 != 0 && delimo % 7 == 0 && delimo % 11 != 0)
		{
			cout << delimo << endl;
			counter++;
			delimo++;
		}
		if (delimo % 3 != 0 && delimo % 7 != 0 && delimo % 11 == 0)
		{
			cout << delimo << endl;
			counter++;
			delimo++;
		}
		else
		{
			delimo++;
		}
	}
	cout << counter << endl;
}