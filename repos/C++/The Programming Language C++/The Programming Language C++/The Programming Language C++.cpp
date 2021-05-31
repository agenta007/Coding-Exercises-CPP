#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void copy_fct() 
{
	int v1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int v2[10]; // t o b e c o m e a c o py o f v 1
	for (auto i = 0; i != 10; ++i) 
		//c o py ele m e n t s
		v2[i] = v1[i];
	//	...
}

void print() 
{
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto x : v) //		fo r e a c h x in v
		cout << x << '\n';
	for (auto x : { 10,21,32,43,54,65 }) cout << x << '\n'; // ...
}

struct Vector
{
	int size;
	double* elem;
};

void vector_init(Vector& v, int size)
{
	v.elem = new double[size];
	v.size = size;
}

int main()
{
	Vector firstVector;
	
	void* operator new (size_t size);
}