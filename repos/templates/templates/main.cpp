#include <iostream>
using namespace std;
template<typename T, int sz>
T* createArr()
{
	//ako e v stacka shte se unishtoji
	T* arr = new T[sz];
	for (size_t i = 0; i < sz; i++)
	{
		cin >> *(arr+i);
	}
	return arr;
}
template<typename T>
T findMin(T* arrP, int arrSz)
{
	T min = 2119616;
	for (int i = 0; i < arrSz; i++)
	{
		if (min > *(arrP+i))
		{
			min = *(arrP + i);
		}
	}
	return min;
}
int zadacha2()
{
	int* arr = createArr<int, 5>();
	cout << findMin <int>(arr, 5);
	delete[] arr;
	arr = nullptr;
	return 0;
}
template<typename T>
class Calculator
{
	T a, b, res;
	char arithmeticOperation;
public:
	Calculator(T a, T b, char op) : a(a), b(b), arithmeticOperation(op) {}
	T sum(){ return a + b; };
	T subtract(){ return a - b; };
	T multiply(){ return a * b; };
	T divide(){ return a / b; };
	void calc()
	{
		switch (arithmeticOperation)
		{
		case '+': res = sum(); break;
		case '-': res = subtract(); break;
		case '*': res = multiply(); break;
		case '/': res = divide(); break;
		default:
			break;
		}
	};
	void printRes()const { cout << res << endl; };
};
int zadacha4()
{
	Calculator<int> obj(1500, 2, '/');
	obj.calc();
	obj.printRes();
	return 0;
}
/*
3 zadacha
int& top() const
{
	try{
		if(isEmpty())
		{
			cerr >> "Trying to access"
			throw out_of_range;
		}
		else
		{
			return arr[t];
		}
	}
	catch(out_of_range)
	{
		cout << "\nYou need to an element first.";
		exit();
	}
}
*/
int main()
{
	zadacha2();
	cout << endl;
	zadacha4();
	return 0;
}