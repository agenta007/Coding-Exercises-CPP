#include <iostream>
#include <cstdint>
#include <string.h>
#include <conio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;


class Snake
{
public:
	int xPos;
	int yPos;
	int snakeLength;
	string direction = "";
	void changeDirection(Snake&, string dirCh)
	{
	}
};

class Food
{
public:
	int xPos;
	int yPos;
	
};

int main()
{
	cout << "Hello world!\n";
	Sleep(3000);
	printf("\033c");
	//int c = 0;
	//while (true)
	//{
	//	c = getch();
	//
	//}
}