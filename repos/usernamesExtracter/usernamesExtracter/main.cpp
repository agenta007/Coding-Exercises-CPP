#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
bool strContain(string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i]=='\'' && input[i+1]=='s')
		{
			return 0;
		}
		if (input[i]<0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	fstream seed;
	vector<string> strVec;
	ofstream edit;
	edit.open(("C:\\Users\\agenta\\Documents\\edit.txt"));
	seed.open(("C:\\Users\\agenta\\Documents\\ig-following-l1nus_t0rvalds.txt"));
	if (seed.is_open())
	{
		string tp;
		while (getline(seed, tp))
		{
			//cout << "\n";
			//cout << tp << endl;
			if (strContain(tp))
			{
				strVec.push_back(tp);
			}
		}
	}
	for (auto& str : strVec)
	{
		cout << str << endl;
		edit.write(str.c_str(), strVec.size());
	}
	seed.close();
	edit.close();
	return 0;
}