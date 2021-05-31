#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Point
{
private:
	double x, y, z;
public:
	//constructor
	void init_Point(double, double, double);
	void scalePoint(double, double, double);
	void scaleAndTraslationByVector(double, int*);
	void init_point(double, double, double);
	void visualizePoint2D();
	double getX();
	double getY();

};

double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}


void Point::init_point(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void visualizePoint2D(Point p)
{
	int xCoord = p.getX();
	int yCoord = p.getY();

	//101 -> -50 0 50
	int upperRuler[101];
	int sideRuler[101];

	int num = -50;
	for (size_t i = 0; i < 102; i++)
	{
		upperRuler[i] = num;
		sideRuler[i] = num;
		num++;
	}

	char dekartMatrix[99][99];

	for (size_t i = 0; i < 100; i++)
	{
		dekartMatrix[i][48] = '|';
		dekartMatrix[i][49] = '|';
		dekartMatrix[48][i] = '-';
		dekartMatrix[49][i] = '-';
	}

	int xPos, yPos;
	xPos = xCoord + 48;
	yPos = xCoord + 48;
	dekartMatrix[xPos][yPos] = 'X';
	dekartMatrix[xPos+1][yPos] = 'X';
	dekartMatrix[xPos][yPos+1] = 'X';
	dekartMatrix[xPos + 1][yPos+1] = 'X';

	for (int n : upperRuler)
		cout << n;
	cout << endl;

	for (size_t i = 0; i < 102; i++)
	{
		cout << sideRuler[i];
		for (size_t j = 0; j < 100; j++)
		{
			cout << dekartMatrix[i][j];
		}
		cout << endl;
	}
}

void init_pont(double a, double b, double c)
{

}

int mainPoints()
{
	cout << "Enter N: ";
	unsigned N;
	cin >> N;
	int i = 0;
	double x, y, z;
	std::vector<Point> pVec;
	Point currentPoint;
	while (i != N)
	{
		cout << "Enter X Y Z: ";
		cin >> x >> y >> z;
		cout << endl;
		currentPoint.init_point(x, y, z);
		pVec.push_back(currentPoint);
		i++;
	}

	for (auto p : pVec)
		visualizePoint2D(p);
	return 0;
}