#include <iostream>
using namespace std;

struct element
{
	int value;
	element* pNext;

	element* add_element(element* elementRef, int elToAdd)
	{
		int oldListSz = sizeof(elementRef);
		int newListSz = sizeof(elementRef)+1;
		element* newList = new element[newListSz];

		for (size_t i = 0; i < oldListSz; i++)
		{
			newList[i] = elementRef[i];
		}
		newList[newListSz - 2].pNext = &newList[newListSz - 1];
		newList[newListSz - 1].value = elToAdd;
		newList[newListSz - 1].pNext = nullptr;
		return newList;
	}
};

int main()
{
	int n;
	cin >> n;
	element* list = new element[n];

	for (size_t i = 0; i < n; i++)
	{
		list[i].value = rand() % 100 + 1;
		if (i != n - 1)
			list[i].pNext = &list[i + 1];
		else
			list[i].pNext = nullptr;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << list[i].value << " ";
	}
	cout << "\n";

	int newEl = 0;
	cout << "Add an element and print";
	cin >> newEl;

	element* expandedList = add_element(list, newEl);

	for (size_t i = 0; i < n; i+=2)
	{
		cout << list[i].value << " " << *list[i].pNext;
	}
	cout << "\n";

}

