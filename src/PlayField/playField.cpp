/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "playField.h"
#include "../Console/Console.h"

void initPlayField(char playField[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (j == 0 || j == WIDTH - 1 || i == 0 || i == HEIGHT - 1)
			{
				playField[i][j] = '=';
				continue;
			}

			if (j != WIDTH)
			{
				playField[i][j] = ' ';
			}
		}
	}
}

void printPlayField(const char playField[HEIGHT][WIDTH], const Tetromino& tetromino, const Console& console)
{
	int curVec = 0;
	console.clearScreen();
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (tetromino.m_vector2[curVec].y == i && tetromino.m_vector2[curVec].x == j)
			{
				std::printf("%c", 'T');
				++curVec;
				continue;
			}
			std::printf("%c", playField[i][j]);
		}
		std::printf("\n");
	}
}