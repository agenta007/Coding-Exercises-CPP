#include <iostream>
#include <random>
using namespace std;
class Prog
{
	double k, m;
	double a[1000];
public:
	Prog(double a0 = 0,double a1 = 0, double k = 0, double m = 0);
	double operator[](int index);
	double operator()(int);
	int calc();
};
Prog::Prog(double a0, double a1, double k, double m)
{
	a[0] = a0;
	a[1] = a1;
	this->k = k;
	this->m = m;
}
double Prog::operator[](int index)
{
	if (index >99 || index <0)
	{
		cout << "Array index out of bound, exiting.\n";
		exit(1);
	}
	return a[index];
}
double Prog::operator()(int index)
{
	double sum = 0;
	for (size_t i = 0; i <= index; i++)
	{
		sum += a[i];
	}
	return sum;
}
int Prog::calc()
{

	for (size_t i = 2; i < k; i++)
	{
		a[i] = a[i - 1] + a[i - 2] + pow(i - 1, 2) + k / m;
	}
	return 0;
}
class Randomizer
{
	int arr[50];
public:
	Randomizer();
	friend ostream& operator<<(ostream&, const Randomizer&);
	int sort();
	Randomizer& operator*(const Randomizer&);
	void elemSetter(int, int);
	bool operator=(const Randomizer&);
};
int Randomizer::sort()
{
	int tmp[50];
	int flag;
	int max = 0;
	int min = 0;
	for (size_t i = 0; i < 50; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}

	tmp[49] = max;
	min = max;
	for (size_t i = 0; i < 49; i++)
	{
		for (size_t j = 0; j < 50; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				flag = j;
			}
		}
		tmp[i] = min;
		arr[flag] = max;
		min = max;
	}
	for (size_t i = 0; i < 50; i++)
	{
		arr[i] = tmp[i];
	}
	return 0;
}
ostream& operator<<(ostream& out, const Randomizer& obj)
{
	for (size_t i = 0; i < 50; i++)
	{
		out << obj.arr[i] << " ";
	}
	return out;
}
Randomizer::Randomizer()
{
	for (size_t i = 0; i < 50; i++)
	{
		arr[i] = rand() % 500 + 9;
	}
}
Randomizer& Randomizer::operator*(const Randomizer& rhs)
{
	Randomizer m;
	for (size_t i = 0; i < 50; i++)
	{
		int el = arr[i] * rhs.arr[i];
		m.arr[i] = el;
		//m.elemSetter(i, )
	}
	return m;
}
void Randomizer::elemSetter(int index, int value)
{
	arr[index] = value;
}
bool Randomizer::operator=(const Randomizer& rhs)
{
	for (size_t i = 0; i < 50; i++)
	{
		int sravnenie = arr[i];
		bool imaLiGo = false;
		for (size_t j = 0; j < 50; j++)
		{
			if (sravnenie == rhs.arr[i])
			{
				imaLiGo = true;
				continue;
			}
		}
		if (imaLiGo==false)
		{

			return false;
		}
	}
	return true;
}
class CntExpression
{
	double val;
public:
	int counterOfExpr = 0;
};
int main()
{
	Prog redica(15, 20, 100, 5);
	redica.calc();
	cout << redica(5) << endl;
	cout << redica(99) << endl;
	cout << redica(8) << endl;
	

	Randomizer arrOfRands;
	cout << arrOfRands << endl;
	arrOfRands.sort();
	cout << arrOfRands << endl;
	Randomizer arrOfRands2;
	cout << arrOfRands2 << endl;
	arrOfRands.sort();
	cout << arrOfRands2 << endl;
	//Randomizer mul = arrOfRands * arrOfRands2;
	//cout << mul << endl;
	//mul.sort();
	//cout << mul << endl;

	return 0;
}