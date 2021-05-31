#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#include "CarDealer.h"

void vtoraZad()
{
	int sum, sum2, sum3, n;
	cin >> n;
	sum = sum2 = sum3 = 0;
	for (int i = 1; i != n; ++i) {
		sum += i * i;
		if (i != 1)
			sum2 += (i * i) - 2*i;
		if (i > 2)
			sum3 += (i * i * i) - 2 * i;
	}
	cout << sum << " " << sum2 << " " << sum3 << '\n';

}

void factoriel()
{
	int n, factoriel;
	cin >> n;
	factoriel = 1;
	for(int i = n; i != 1; --i)
	{
		factoriel *= i;
	}
	cout << factoriel << "\n";
}

int main()
{
	/*char carName[]{'a','u','d','i','\0'};
	int arr[]{1,2,3,4,5};
	int* ip = arr;
	while (*ip!=5)
	{
		cout << ip << " - " << *ip << "\n";
		++ip;
	}

	char* pCarName = carName;
	Car a[10];
	int i = 0;
	for (Car car : a)
	{
		Car tmp = Car(pCarName, 4, rand() % 500 + 1, rand() % 2001, 2500. + i);
		car = tmp;
		++i;
	}
	Car* parr = a;
	Car b (carName, 2 , 5 ,7 ,8);
	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(Car) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(a)/4 << endl;
	cout << sizeof(arr) << "\n";
	cout << parr << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;*/
	char carName[]{ 'a','u','d','i','\0' };
	char* pCarName = carName;
	Car a(pCarName, 4, rand() % 500 + 1, rand() % 2001, 2500. + 5);
	//Car kola("Beemve", 5, 250, 13000);
	a.print();
	a++;
	a.print();
	a *= 3;
	a.print();
	char dealername[]{'I,','c','o','\0'};
	char bName[]{'V','W','\0'};
	char* pBName = bName;
	const char* mainDealerName = dealername;
	CarDealer mainDealer(mainDealerName, 1, &a);
	Car b(a);
	Car c;
	b.setBrand(pBName);
	mainDealer.ins(cout);
	mainDealer + b;
	mainDealer.ins(cout);
	//vtoraZad();
	//factoriel();

}