#ifndef _CardHeader
#define _CardHeader_
class Card
{
private:
	char* title = nullptr;
	char* authorName = nullptr;
	unsigned quantity = 0;
public:
	void cardCreate(char*, char*, unsigned);
	void printCard();
};
#endif
