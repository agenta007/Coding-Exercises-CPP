#include <iostream>
#include <string>
//toupper() and so on
#include <cctype>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

typedef double wages; // wages is a synonym for double
typedef wages base, * p; // base is a synonym for double, p for double*

//alias de
typedef double zaplati;
typedef zaplati baza, *pZaplata;

struct Kola {
	string nomerRama;
	//in-class-init cant be in () NB! this is the so called "list initiliazation"
	int hp{0};
	double price{0.0};
	public:
	Kola sumTwoCars(Kola car1, Kola car2)
	{
		Kola newCar;
		if (car1.nomerRama == car2.nomerRama)
		{
			newCar.nomerRama == car1.nomerRama;
		}
		else
		{
			cout << "Ramite sa razlichni, vzimame pyrvata rama." << endl;
		}
		newCar.hp = car1.hp + car2.hp;
		newCar.price = (car1.price + car2.price) * 0.75;
		return newCar;
	}
};

string rmPunc(string input)
{
	string newString("");
	for (auto& c : input)
	{
		if (!ispunct(c))
		{
			newString += c;
		}
	}
	return newString;
}

void logInt(int x)
{
	cout << x << endl;
}

//default initialization
const int arrSz = 10;
int iarr[arrSz];

int main()
{
	//can print them now, but when declared in a scope objects must be initializied
	for (auto n : iarr)
		cout << n << endl;


	string text("");
	string input;
	//while (cin>>input)
	//{
		//at least one operand at the sides of the + operator when working on text must be of string type
	//	text += " " + input;
	//}
	//cout << text << endl;
	zaplati zaplata = 1200.25;
	cout << zaplata << endl;
	cout << "\??\a\n";
	double moitaZaplata = 5555.55;
	pZaplata pKymMoitaZaplata = &moitaZaplata;
	cout << "Moita zaplata kato programist e == " << *pKymMoitaZaplata << endl;

	int i = 0;
	while (i != 100)
	{
		//alarm
		cout << "\a";
		i++;
	}
	cout << "\n";
	wchar_t myWchar = L'a';
	cout << (char)myWchar << endl;

	int month = 9, day = 7;
	int month1 = 9, day1 = 07;
	cout << month << month1 << day << day1 << "\n";
	int PiTekst = 3.14e1;
	cout << PiTekst << endl;
	int a(52);
	cout << a << endl;
	//cant lose information when initializing with {}
	int arr[10]{ 0,1,2,3,4,5,6,7,8,9 };
	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//conversion loss use {} to not lose
	int u(3.14);
	double  wage;
	double salary = wage = 999.99;
	cout << u << endl;
	cout << wage << endl;
	cout << salary << endl;
	int chisloZap = 5;
	int* p = &chisloZap;
	cout << p << endl;
	int*& pointerRef = p;
	pointerRef = nullptr;
	cout << pointerRef << endl;
	const int buf = 5;
	//const pointer to cp
	int* const cp = 0;
	const int  ic = 0, & r = ic;
	int myValue = 5;
	int& refMyVal = myValue;
	const int votorimaihuop = 6;
	refMyVal = votorimaihuop;
	cout << refMyVal << endl;
	//constant pointer
	const int const* cp2 = &votorimaihuop;
	constexpr int sumataNaPetIdeset = 5 + 10;
	int const sumataNaPetIDesetIdve = sumataNaPetIdeset + 2;
	//const pointer to const int, can also use constexpr to make cip a constant pointer,
	//but then it will be evaluated at compile time
	const int* const cip = &votorimaihuop;
	cout << cip << endl;
	decltype ('f') bukvaBrat = 'x';
	//put a variable and take its type
	decltype (myValue) izmislenInt = 5;
	cout << izmislenInt << endl;
	//double parentheses mean its expression inside
	decltype ((myValue + 0)) izmislenInt2;
	izmislenInt2 = 25;
	//decltype of parenthesized variable is always a ref
	decltype ((sumataNaPetIdeset)) refToSumataNa = sumataNaPetIdeset;
	//refToSumataNa = 5; reffered variablle is a contstant, so this cannot be
	logInt(izmislenInt);
	logInt(izmislenInt2);
	logInt(refToSumataNa);
	int* arr2 = new int[5]{ 0,1,2,3,4 };
	//remember you lose data with parentheses, but curly braces check
	int chislo{ 2 };
	int chislo2(2);

	Kola audi{ "XXX-333-XXX", 350, 2500.00 };
	logInt(audi.hp);
	Kola audiTDI{ "XXX-333-XXX", 150, 2500.00 };
	//Kola kombo = audi + audiTDI;
	//Kola komboKola = Kola::sumTwoCars(audi, audiTDI);
	//logInt(komboKola.hp);
	void* pToChislo = &chislo;
	cout << pToChislo << endl;
	string duma{ 'd','u','m','a' };
	string tekst = "teskt";
	string curlyString{ "tekst" };
	cout << curlyString << endl;
	for (auto& c : curlyString)
	{
		c = toupper(c);
	}
	for (auto c : curlyString)
	{
		cout << c;
	}
	cout << endl;
	tekst = "Zdraveite, manqci!!! . .. abfkpimf ..0. 00l033....~~???/@@/~!!!!...??2";
	tekst = rmPunc(tekst);
	cout << tekst << endl;

	vector<int> ivec;
	//store 0-99 in vector
	i = 0;
	while (i < 100)
	{
		ivec.push_back(i);
		i++;
	}

	cout << "Vector size is: " << ivec.size() << endl;
	for (auto num : ivec)
		cout << num << endl;
	vector<int> desetChetirsedeitIdve{ 10, 10 };
	for (auto n : desetChetirsedeitIdve)
		cout << n << endl;
	cout << "Enter vector sz" << endl;
	i = 0;
	cin >> i;
	vector<int> exerciseIvec(i);
	for (auto& n : exerciseIvec)
		n = rand() % 10 + 1;
	if (i % 2 != 0)
		++i;
	for (size_t j = 0; j < i / 2; j++)
	{
		if (j == i - j - 1)
			cout << "NOTE: Vector size is odd so I'll sum the middle element with itself." << endl;
		cout << exerciseIvec[j] << " + " << exerciseIvec[i - j - 1] << " = " << exerciseIvec[j] + exerciseIvec[i - j - 1] << endl;;
	}
	auto itExIvecSt = exerciseIvec.begin();
	cout << &itExIvecSt << *itExIvecSt << endl;
	vector<int>::iterator it;
	auto beg = tekst.begin(), end = tekst.end();
	auto tekstSize = tekst.size();
	auto middle = tekst.begin() + tekstSize / 2;
	//beg == [0-37], end == [outOfRange==38]
	//37/2 == 18, mid2 == [19-37]
	auto mid2 = tekst.begin() + tekst.size() / 2;
	//vqrno v uchebnika  greshno tuk? sigurno sum iztupql xDD
	//->auto mid3 = text.begin() + (end - beg) / 2;
	//cout << mid << endl;
	cout << *mid2 << endl;
	cout << ivec[1] << endl;
	p = iarr;
	int* pend = &iarr[arrSz];
	while (p >= 0 && p != pend)
	{
		*p = 1;
		p++;
	}

	for (auto n : iarr)
		cout << n << endl;
	i = 0;
	p = iarr;
	p = 0;
	while (p)
	{
		cout << i++ << endl;
		p++;
	}
	//braces - > 0 4 8  - first column (nadolu), no braces -> 0 4 8 0 - first row
	int matricaStranna[3][4] = { { 0 }, { 4 }, { 8 }};
	int matrixWeird[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << matricaStranna[i][j] << " ";
		}
		cout << "\n";
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << matrixWeird[i][j] << " ";
		}
		cout << "\n";
	}

	string str1, str2;
	str1 = "abrakadrabra";
	str2 = "simsalabin";

	if (str1 != str2)
	{
		throw runtime_error("strings dont match");
	}

	//its all the  same
	//int* ia(iarr);
	//ia = &iarr[0];
	//ia = iarr;
}