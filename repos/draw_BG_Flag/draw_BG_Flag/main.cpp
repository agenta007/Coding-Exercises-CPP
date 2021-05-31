#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a = 1920;
	cout << (char*)1920;

	ifstream bin("input.tga", ios::in | ios::binary);
	if (!bin)
	{
		cerr << "Could not open file\n";
	}
	//tga have 18-bytes headers
	char metadataHeader[18];
	for (size_t i = 0; i < 18; i++)
	{
		bin.read(metadataHeader, 1);
	}
	
	//for (char ch : metadataHeader)
	//	cout << ch;
	uint16_t width, heigth;
	bin.seekg(12, ios::beg);
	bin.read((char*)&width, sizeof(uint16_t));
	bin.read((char*)&heigth, sizeof(uint16_t));
	//cout << "width: " << width << " x heigth: " << heigth;

	while (!bin.eof())
	{
		char ch[1];
		bin.read((char*)&ch, 1);
		cout << ch;
	}
	bin.close();
	ofstream bout("flag.tga", ios::out | ios::binary);
	bout.seekp(12, ios::beg);
	char widthToWrite[]{'1','9','2','0'};
	bout.write((char*)&widthToWrite,4);
	bout.write((char*)1080, 1);
	uint16_t boutW, boutH;
	
	//bout.write();
	bout.close();
	return 0;
}