#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	std::fstream fstr("C:\\Users\\agenta\\Documents\\edit.txt");
	ofstream edit("C:\\Users\\agenta\\Documents\\edit.txt");
	//edit.open("C:\\Users\\agenta\\Documents\\edit.txt");
	//fstr.open("C:\\Users\\agenta\\Documents\\ig - following - l1nus_t0rvalds.txt");
	cout << fstr.is_open() << endl;
	for (size_t i = 0; i < 1000; i++)
	{
		//fstr.read();
	}
	vector<string> strvec;
	fstr.close();
	edit.close();
	/*cout << (char)0 << endl;
	std::fstream fstr;
	std::ofstream ostr;
	ostr.open("C:\\Users\\agenta\\Desktop\\text2.txt");
	fstr.open("C:\\Users\\agenta\\Desktop\\text.txt");

	if (!fstr.is_open())
	{
		cout << "Cant open\n";
		return 1;
	}
	if (!ostr.is_open())
	{
		cout << "cant create file\n";
		return 2;
	}

	char** lines = new char*[1000];
	int readLines = 0;
	for (size_t i = 0; i < 1000; i++)
	{
		lines[i] = new char[1000];
		fstr.getline(lines[i], 1000);
		int j = 0;
		bool is_empty_line = false;
		if (lines[i] == NULL)
		{
			is_empty_line = true;
			break;
		}
		if (is_empty_line)
		{
			break;
		}
		++readLines;
		cout << lines[i] << "\n";

	}
	for (size_t i = 0; i < 1000; i++)
	{
		ostr.write(lines[1000 - i], 1000);
	}
	*/
}