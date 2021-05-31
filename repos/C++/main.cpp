/*
* 10 zadacha - otkriite greshkite
* A)
* Klas pishem s glavna bukva i camel case - Dumb_hell
* v maina na vtori red trqbva da se utochni obekta i da se polzva definiraniq constructor - bar.setWeigth(10) ;
* na treti red v main nqma dostup do bar.weight zashtoto e private by default, trqbva da se definira i polzva accessor func
* int getWeight() const;
* {return weight}
* B)
* po-dobre poletata da sa private
* Change trqbva da vrushta tip ili void
* deklaraciqta i definiciqta na Change se razminavat - change does not take 4 arguments
* ne mojem da assign-vame vuv ()
* 
* zadacha 11 - bez greshki
* include <iostream.h>
class A
{ 
public:
void A(int, int);
void print();
int f_Ax() const;
int f_Ay() const;
private:
int x, y;
}
void A::A(int a, int b)
{ 
x = a;
y = b;
}
void A::print()
( 
cout << x << " " << y << endl;
int A::f_Ax()
( return x;
l
int A::f_Ay()
{ return y;

class B
{ public:
B(double, A);
void print() const;
double f Bx();
A f_Ba() const;
private:
double x;
A a;

B=:B(double d, A e)
{ X = d;
a = e;
l
void B::print() const
l cout << x << endl;
1 a-Print();
* 
*/

#include <iostream>
#include <stdio.h>
#include "Card.h"
#include "Dictionary.h"
#include "Calculator.h"
#include "MilitaryTime.h"
#include <vector>
#include <string>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;

void Card::cardCreate(char* title, char* author, unsigned quantity)
{
	this->quantity = quantity;
	this->title = title;
	authorName = author;
}

void Card::printCard()
{
	cout << "Title: " << this->title << "\nAuthor: " << this->authorName << "\nQuantity: " << this->quantity << endl;
}

void DictionaryWord::addWord(string en, string bg)
{
	this->english.push_back(en);
	this->bulgarian.push_back(bg);
}

void DictionaryWord::delWord(string word)
{
	for (vector<string>::iterator i = this->bulgarian.begin(); i < this->bulgarian.end(); i++)
	{
		if (*i == word)
		{
			this->bulgarian.erase(i);
			this->english.erase(i);
		}
	}
}

void DictionaryWord::searchWord(string word)
{
	vector<string>::iterator iEn = this->english.begin();
	for (vector<string>::iterator iBul = this->bulgarian.begin(); iBul < this->bulgarian.end(); iBul++)
	{
		if (*iBul == word || *iEn == word)
		{
			cout << *iEn << " | " << *iBul;
			return;
		}
		iEn++;
	}
}

string DictionaryWord::translate(string word)
{
	vector<string>::iterator iEn = this->english.begin();
	for (vector<string>::iterator iBul = this->bulgarian.begin(); iBul < this->bulgarian.end(); iBul++)
	{
		if (*iBul == word)
		{
			return *iEn;
		}
		else if (*iEn == word)
		{
			return *iBul;
		}
		iEn++;
	}
	return "Eror 404: Not found.";
}

void cardProgram()
{
	unsigned N;
	cout << "Enter cards quantity: "; cin >> N;

	std::vector<Card> cardsVec;
	int i = 0;
	Card temp;
	unsigned qTmp;
	char title[100];
	char author[100];

	while (i != N)
	{
		cout << "Enter Title: ";
		cin >> title;
		cout << "Enter Author: ";
		cin >> author;
		cout << "Enter Quantity: ";
		cin >> qTmp;
		temp.cardCreate(title, author, qTmp);
		cardsVec.push_back(temp);
		i++;
		temp.printCard();
	}

	for (Card card : cardsVec)
		card.printCard();

}

void DictionaryWord::printAll()
{
	vector<string>::iterator j = this->bulgarian.begin();
	for (vector<string>::iterator i = this->english.begin(); i < this->english.end(); i++)
	{
		cout << *i << " | " << *j << endl;
		j++;
	}
}

void DictionaryStart()
{
	cout << "OPTIONS: " << endl;
	cout << "Add a word - 1: " << endl;
	cout << "Search a word - 2: " << endl;
	cout << "Delete a word - 3" << endl;
	cout << "Traslate - 4" << endl;
	cout << "Print whole dictionary and terminate - 0" << endl;

	DictionaryWord dictionary;
	unsigned inputN;
	std::string translation;
	std::string word;
	while (1)
	{
		cin >> inputN;
		switch (inputN)
		{
			case 1 :
				cout << "Enter english word" << endl;
				cin >> word;
				cout << "Vyvedete prevod" << endl;
				cin >> translation;
				dictionary.addWord(word, translation);break;
			case 2 : 
				cout << "Word search loaded." << endl;
				cin >> word;
				dictionary.searchWord(word);break;
			case 3 : 
				cout << "Delete module selected." << endl;
				cin >> word;
				dictionary.delWord(word);break;
			case 4 :
				cout << "Translate input: " << endl;
				cin >> word;
				cout << dictionary.translate(word) << endl;
				break;
			case 0:
				dictionary.printAll();
				//std::ofstream dictionaryFile;
				//dictionaryFile.open("Employee.txt", ios::app);
				return;
				break;
		default:
			break;
		}
	}
}

bool Calculator::validateEx(char input[])
{
	return 0;
}

using int_array = int[4];
typedef int int_array[4];

void someArraysAndLoopsEx()
{
	int broq4 = 0;
	int arr[10][20];
	int arr2[]{ 1,2,3,4 };
	int_array typArr[10];
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			arr[i][j] = broq4;
			broq4++;
		}
	}
	broq4 = 0;
	for (int_array& el : typArr)
		for (int& ele : el)
		{
			ele = broq4;
			broq4++;
		}

	for (auto& i : arr)
		for (auto j : i)
			cout << j << endl;

	//q is a pointer to arr2[0]
	for (auto q = arr2; q != arr2 + 4; q++)
	{
		q++;
	}
	for (int i : arr2)
		cout << i << endl;
}

MilitaryTime::MilitaryTime(int aHour, int aMinute, int aSecond) 
{
	if (aHour>23)
		aHour -= 24;
	if (aMinute > 59)
		aMinute -= 60;
	if (aSecond > 59)
		aSecond -= 60;
	theHours = aHour;
	theMinutes = aMinute;
	theSeconds = aSecond;
}
MilitaryTime::MilitaryTime(int aSeconds) 
{
	int hoursCnt = 0;
	int minutesCnt = 0;
	int secondsToHrtmp = aSeconds;
	while (aSeconds >= 3600)
	{
		hoursCnt++;
		secondsToHrtmp /= 3600;
	}
	while (aSeconds >= 60)
	{
		minutesCnt++;
		secondsToHrtmp /= 60;
	}
	theHours = hoursCnt;
	theMinutes = minutesCnt;
	theSeconds = secondsToHrtmp;
}
MilitaryTime::MilitaryTime(const MilitaryTime& timeRef) 
{
	if (timeRef.theHours > 23 || timeRef.theSeconds > 59 || timeRef.theMinutes > 59)
		cout << "Invalid Time object was given." << endl;
	theHours = timeRef.theHours;
	theMinutes = timeRef.theMinutes;
	theSeconds = timeRef.theSeconds;
}

void MilitaryTime::add(const MilitaryTime& ref) 
{
	theSeconds += ref.theSeconds;
	theMinutes += ref.theMinutes;
	theHours += ref.theHours;
	if (theHours > 23)
		theHours -= 24;

	while (theMinutes > 59)
	{
		theHours++;
		theMinutes -= 60;
	}

	while (theSeconds > 59)
	{
		theMinutes++;
		theSeconds -= 60;
	}

}
void MilitaryTime::sub(const MilitaryTime& ref) 
{
	theSeconds -= ref.theSeconds;
	theMinutes -= ref.theMinutes;
	theHours -= ref.theHours;

	while (theSeconds < 0)
	{
		theSeconds += 60;
		theMinutes--;
	}

	while (theMinutes < 0)
	{
		theMinutes += 60;
		theHours--;
	}

	while (theHours < 0)
		theHours++;
}

bool MilitaryTime::different(const MilitaryTime& ref) const
{
	if (theHours == ref.theHours && theSeconds == ref.theSeconds && theMinutes == ref.theMinutes)
		return 1;
	else
		return 0;
}

int MilitaryTime::totalSeconds() const 
{
	return theSeconds + theHours * 3600 + theMinutes * 60; 
}

int MilitaryTime::hours() const 
{ 
	return theHours; 
}

int MilitaryTime::minutes() const 
{
	return theMinutes;
}

int MilitaryTime::seconds() const 
{ 
	return theSeconds; 
}

class triChisla
{
private:
	int a, b, c;
public:
	void setNums(int aA, int bB = 0, int cC = 0) { a = aA; b = bB; c = cC;}
	void printNums() { cout << a << " " << b << " " << c << endl; }
};

void triChislaDemonstrate()
{
	//dokazatelstvo che void setNums(int aA, int bB = 0, int cC = 0) { a = aA; b = bB; c = cC;} bB i cC trqbva da sa nakraq i setvat default values samo
	triChisla troika;
	troika.setNums(3, 1, 2);
	troika.printNums();
	triChisla vtorka;
	vtorka.setNums(1);
	vtorka.printNums();
}

void MilitaryTimeDemo()
{
	//init by seconds constructor
	MilitaryTime time1(7266);
	cout << "Total Seconds: " << time1.totalSeconds() << " Hours only: " << time1.hours() << "Minutes only: " << time1.minutes() << "Seconds only: " << time1.seconds() << endl;
	MilitaryTime time2(15, 26, 30);
	cout << "Second time is " << time2.hours() << ":" << time2.minutes() << ":" << time2.seconds() << endl;
	MilitaryTime time3(0, 0, 0);
	time3.add(time1);
	time3.add(time2);
	cout << "time1 + time2 = " << time3.hours() << ":" << time3.minutes() << ":" << time3.seconds() << " or " << time3.totalSeconds() << endl;
	int n;
	cout << "Enter how many seconds to add to time3: "; cin >> n;
	cout << "time3 = " << time3.hours() << ":" << time3.minutes() << ":" << time3.seconds() << " or " << time3.totalSeconds() << endl;
}

using double_int = int[2];
typedef int double_int[2];

int generateR()
{
	vector<double_int> rVec;
	rVec.push_back(double_int{1,1});
	int start = 2;
	int chislitel;
	int znamenatel;
	while (start != 2100000)
	{
		chislitel = start;
		znamenatel = 1;
		while (chislitel != 0)
		{
			if (chislitel%znamenatel==0 || znamenatel%chislitel==0 && znamenatel != 1)
			{
				chislitel--;
				znamenatel++;
				continue;
			}
			rVec.push_back(double_int{ chislitel, znamenatel });
			chislitel--;
			znamenatel++;
		}
		start++;
	}
	for (auto pair : rVec)
		if (pair[1] != 1)
			cout << pair[0] << " / " << pair[1] << endl;
		else
			cout << pair[0] << endl;
	return 0;
}

int main()
{
	generateR();
	//Dictionary demonstration with menu
	//DictionaryStart();
}