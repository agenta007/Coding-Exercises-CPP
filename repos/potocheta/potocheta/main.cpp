#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//fstream workFile("C:\\Users\\agenta\\Documents\\text.txt");
	ofstream outputFile("C:\\Users\\agenta\\Documents\\created.txt");
	for (size_t i = 0; i < 100; i++)
	{
		outputFile << i+1 << " red\n";
	}
	outputFile.close();
	return 0;
}