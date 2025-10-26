#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
static int game(char temp[ROWS][COLS])
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			printf("%c",temp[i][j]);
		}
	}
}