#include <iostream>

char letterPascalRecursive(char startingLetter, char endingLetter)
{
	if (startingLetter == endingLetter) return 0;
	std::cout << letterPascalRecursive(startingLetter + 1, endingLetter) << std::endl;
}

int main()
{
	letterPascalRecursive('A', 'E');
}