#include <iostream>
using namespace std;

char encodeChar(char a)
{
	char b;
	if (a < 65 || a > 122)
		return a;
	else
		b = a + 3;
	return b;
}


int main()
{
	unsigned arrL;
	char tempChars[1000];
	cout << "Enter string:" << "\n";
	cin.getline(tempChars, 1000);

	int strLen;
	for (size_t i = 0; i < 1000; i++)
	{
		if (tempChars[i] == NULL)
		{
			strLen = i;
			break;
		}
	}

	char* arr = new char[strLen];

	for (size_t i = 0; i < strLen; i++)
	{
		arr[i] = tempChars[i];
	}
	
	for (size_t i = 0; i < strLen; i++)
	{
		arr[i] = encodeChar(arr[i]);
	}
	
	for (size_t i = 0; i < strLen; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	delete[] arr;
}