#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <string>
#include <vector>
using std::string;
using std::vector;
class DictionaryWord
{
private:
	vector<string> bulgarian, english;
public:
	void addWord(string, string);
	void delWord(string);
	void searchWord(string);
	std::string translate(string);
	void printAll();
};
#endif // !_DICTIONARY_H_
