#include <iostream>
#include <windows.h>
using namespace std;

int step = 0;
int snejinka1Y = 1;
int snejinka2Y = 3;
int snejinka3Y = 19;
int snejinka4Y = 21;
int zero1Y = 10;
int zero2Y = 12;
int zero1Add = 0;
int zero2Add = 0;
int edinichnaNulaY = 11;

int print_kartnika(char** matrix)
{
	for (size_t i = 0; i < 17; i++)
	{
		for (size_t j = 0; j < 24; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}

int picture_clear(char** matrix) 
{
	for (size_t i = 0; i < 17; i++)
	{
		for (size_t j = 0; j < 24; j++)
		{
			matrix[i][j] = ' ';
		}
	}
	return 0;
}

int picture_draw(char** matrix)
{
	if (step % 3 == 0)
	{
		//RISUVANE NA SNEJEN CHOVEK S NULI
		for (size_t i = 0; i < 17; i++)
		{
			//SET ADD VALUES FOR ZEROS POSITIONS
			if (i < 4 || (i < 10 && i > 5))
			{
				zero1Add = -1;
				zero2Add = 1;
			}
			else
			{
				zero1Add = 1;
				zero2Add = -1;
			}

			//PROVERKA ZA EDINICHNI NULI I RISUVANE NA NULI I LICE
			if (i == 0 || i == 6 || i == 16)
			{
				matrix[i][edinichnaNulaY] = '0';
			}
			else
			{
				if (i == 2)
				{
					zero1Y = 9;
					zero2Y = 13;
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
					matrix[i][10] = '1';
					matrix[i][12] = '1';
				}
				else if (i == 3)
				{
					zero1Y = 8;
					zero2Y = 14;
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
					matrix[i][10] = '|';
					matrix[i][12] = '|';
					matrix[i][11] = '_';
				}
				else if (i == 11)
				{
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
				}
				else
				{
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
					zero1Y += zero1Add;
					zero2Y += zero2Add;
				}
			}
		}

		//RISUVANE NA SNEJINKI
		matrix[step][snejinka1Y] = '*';
		matrix[step][snejinka2Y] = '*';
		matrix[step][snejinka3Y] = '*';
		matrix[step][snejinka4Y] = '*';

		//MESTENE NA SNEJINKI
		if (step % 2 == 0)
		{
			snejinka1Y--;
			snejinka2Y--;
			snejinka3Y++;
			snejinka4Y++;
		}
		else
		{
			snejinka1Y += 2;
			snejinka2Y += 2;
			snejinka3Y -= 2;
			snejinka4Y -= 2;
		}

		//RISUVANE NA RUCE
		matrix[8][5] = '1';
		matrix[8][6] = '1';
		matrix[8][7] = '1';
		matrix[8][8] = '1';
		matrix[8][14] = '1';
		matrix[8][15] = '1';
		matrix[8][16] = '1';
		matrix[8][17] = '1';
	}
	else if (step % 3 == 1)
	{
		//RISUVANE NA SNEJEN CHOVEK S NULI
		for (size_t i = 0; i < 17; i++)
		{
			//SET ADD VALUES FOR ZEROS POSITIONS
			if (i < 4 || (i < 10 && i > 5))
			{
				zero1Add = -1;
				zero2Add = 1;
			}
			else
			{
				zero1Add = 1;
				zero2Add = -1;
			}

			//PROVERKA ZA EDINICHNI NULI I RISUVANE NA NULI I LICE
			if (i == 0 || i == 6 || i == 16)
			{
				matrix[i][edinichnaNulaY] = '0';
			}
			else
			{
				if (i == 2)
				{
					zero1Y = 9;
					zero2Y = 13;
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
					matrix[i][10] = '1';
					matrix[i][12] = '1';
				}
				else if (i == 3)
				{
					zero1Y = 8;
					zero2Y = 14;
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
					matrix[i][10] = '|';
					matrix[i][12] = '|';
					matrix[i][11] = '_';
				}
				else if (i == 11)
				{
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
				}
				else
				{
					matrix[i][zero1Y] = '0';
					matrix[i][zero2Y] = '0';
					zero1Y += zero1Add;
					zero2Y += zero2Add;
				}
			}
		}

		//RISUVANE NA SNEJINKI
		matrix[step][snejinka1Y] = '*';
		matrix[step][snejinka2Y] = '*';
		matrix[step][snejinka3Y] = '*';
		matrix[step][snejinka4Y] = '*';

		//MESTENE NA SNEJINKI
		if (step % 2 == 0)
		{
			snejinka1Y--;
			snejinka2Y--;
			snejinka3Y++;
			snejinka4Y++;
		}
		else
		{
			snejinka1Y += 2;
			snejinka2Y += 2;
			snejinka3Y -= 2;
			snejinka4Y -= 2;
		}
			matrix[5][5] = '1';
			matrix[6][6] = '1';
			matrix[7][7] = '1';
			matrix[8][8] = '1';
			matrix[8][14] = '1';
			matrix[7][15] = '1';
			matrix[6][16] = '1';
			matrix[5][17] = '1';
		}
	
	
	else if (step % 3 == 2)
	{
	//RISUVANE NA SNEJEN CHOVEK S NULI
	for (size_t i = 0; i < 17; i++)
	{
		//SET ADD VALUES FOR ZEROS POSITIONS
		if (i < 4 || (i < 10 && i > 5))
		{
			zero1Add = -1;
			zero2Add = 1;
		}
		else
		{
			zero1Add = 1;
			zero2Add = -1;
		}

		//PROVERKA ZA EDINICHNI NULI I RISUVANE NA NULI I LICE
		if (i == 0 || i == 6 || i == 16)
		{
			matrix[i][edinichnaNulaY] = '0';
		}
		else
		{
			if (i == 2)
			{
				zero1Y = 9;
				zero2Y = 13;
				matrix[i][zero1Y] = '0';
				matrix[i][zero2Y] = '0';
				matrix[i][10] = '1';
				matrix[i][12] = '1';
			}
			else if (i == 3)
			{
				zero1Y = 8;
				zero2Y = 14;
				matrix[i][zero1Y] = '0';
				matrix[i][zero2Y] = '0';
				matrix[i][10] = '|';
				matrix[i][12] = '|';
				matrix[i][11] = '_';
			}
			else if (i == 11)
			{
				matrix[i][zero1Y] = '0';
				matrix[i][zero2Y] = '0';
			}
			else
			{
				matrix[i][zero1Y] = '0';
				matrix[i][zero2Y] = '0';
				zero1Y += zero1Add;
				zero2Y += zero2Add;
			}
		}
	}

	//RISUVANE NA SNEJINKI
	matrix[step][snejinka1Y] = '*';
	matrix[step][snejinka2Y] = '*';
	matrix[step][snejinka3Y] = '*';
	matrix[step][snejinka4Y] = '*';

	//MESTENE NA SNEJINKI
	if (step % 2 == 0)
	{
		snejinka1Y--;
		snejinka2Y--;
		snejinka3Y++;
		snejinka4Y++;
	}
	else
	{
		snejinka1Y += 2;
		snejinka2Y += 2;
		snejinka3Y -= 2;
		snejinka4Y -= 2;
	}
	//RISUVANE NA RUCE
	matrix[5][7] = '1';
	matrix[6][7] = '1';
	matrix[7][7] = '1';
	matrix[8][8] = '1';
	matrix[8][14] = '1';
	matrix[7][15] = '1';
	matrix[6][15] = '1';
	matrix[5][15] = '1';
	}

	
	
	return 0;
}

int main()
{
	// 50 x 50 kartinka
	char** kartinka = new char* [17];
	for (size_t i = 0; i < 17; i++)
	{
		kartinka[i] = new char[24];
	}

	//risuvane na kartinka v matricata
	picture_clear(kartinka);

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "VESELA KOLEDA!" << endl;

		picture_draw(kartinka);
		print_kartnika(kartinka);
		picture_clear(kartinka);
		step++;

		Sleep(750);
		system("cls");
	}
	

	//DELETE
	for (size_t i = 0; i < 50; i++)
	{
		delete[] kartinka[i];
	}
	delete[] kartinka;
	return 0;
}
