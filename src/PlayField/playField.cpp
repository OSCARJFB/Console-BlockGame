/*
		Writen by: Oscar Bergstr�m
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergstr�m
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
				playField[i][j] = '.';
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

static void updatePlayFieldOnScore(char playField[HEIGHT][WIDTH], int row)
{
	for (int i = 1; i < WIDTH - 1; ++i)
	{
		playField[row][i] = ' ';
	}

	for (int i = 1; i < HEIGHT - 1; ++i)
	{
		for (int j = 1; j < WIDTH - 1; ++j)
		{
			if (i != HEIGHT - 1 && playField[i][j] == 'X')
			{
				playField[i][j] = ' ';
				playField[i + 1][j] = 'X';
			}
		}
	}
}

void scoreCheck(char playField[HEIGHT][WIDTH])
{
	for (int i = HEIGHT - 1; i > 1; --i)
	{
		for (int j = 1; j < WIDTH - 1 && playField[i][j] == 'X'; ++j)
		{
 			if (j == WIDTH - 1)
			{
				updatePlayFieldOnScore(playField, i);
			}
		}
	}
}
