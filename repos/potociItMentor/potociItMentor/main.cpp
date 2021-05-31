#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
	fstream yourFile;
	yourFile.open("txt.txt", ios::in | ios::binary | ios::out);
	
	if (!yourFile.is_open())
	{
		return -1;
	}
	yourFile.seekg(0);
	yourFile.seekg(0, ios::end);
	int yourFileSzBytes = yourFile.tellg();
	yourFile.seekg(0, ios::beg);
	char carr[2];
	carr[1] = '\0';

	for (size_t i = 0; i < yourFileSzBytes; i++)
	{
		yourFile.read(carr, 1);
		cout << carr;
	}
	cout << "writing\n";
	yourFile.seekp(0, ios::beg);
	for (size_t i = 0; i < yourFileSzBytes; i++)
	{
		const char carrr[1]{'1'};

		yourFile.seekp(ios::cur, 1);
		yourFile.write(carrr,1);
	}
	cout << "end\n";
	yourFile.seekg(0, ios::beg);
	for (size_t i = 0; i < yourFileSzBytes; i++)
	{
		yourFile.read(carr, 1);
		cout << carr;
	}
	yourFile.close();
	//myFile.read

	;;;;;;

}