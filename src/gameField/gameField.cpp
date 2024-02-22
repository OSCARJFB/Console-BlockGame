/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "gameField.h"
#include "../Console/Console.h"

void initPlayField(char playField[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (j == 0 || j == WIDTH - 1 || i == HEIGHT - 1)
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

void printPlayField(char playField[HEIGHT][WIDTH], const Block& Block, const Console& console)
{
	playField[Block.m_vector2[0].y][Block.m_vector2[0].x] = BLOCK;
	playField[Block.m_vector2[1].y][Block.m_vector2[1].x] = BLOCK;
	playField[Block.m_vector2[2].y][Block.m_vector2[2].x] = BLOCK;
	playField[Block.m_vector2[3].y][Block.m_vector2[3].x] = BLOCK;
	playField[Block.m_vector2[4].y][Block.m_vector2[4].x] = BLOCK;
	playField[Block.m_vector2[5].y][Block.m_vector2[5].x] = BLOCK;

	console.clearScreen();
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			std::printf("%c", playField[i][j]);
		}
		std::printf("\n");
	}

	playField[Block.m_vector2[0].y][Block.m_vector2[0].x] = '.';
	playField[Block.m_vector2[1].y][Block.m_vector2[1].x] = '.';
	playField[Block.m_vector2[2].y][Block.m_vector2[2].x] = '.';
	playField[Block.m_vector2[3].y][Block.m_vector2[3].x] = '.';
	playField[Block.m_vector2[4].y][Block.m_vector2[4].x] = '.';
	playField[Block.m_vector2[5].y][Block.m_vector2[5].x] = '.';
}

static void deleteLine(char playField[HEIGHT][WIDTH], int row)
{
	for (int i = 1; i < WIDTH - 1; ++i)
	{
		playField[row][i] = '.';
	}
}

static void pullToButtom(char playField[HEIGHT][WIDTH], int row)
{
	for (int i = row + 1; i > 1; --i)
	{
		for (int j = 1; j < WIDTH - 1; ++j)
		{
			if (playField[i][j] != 'X')
			{
				continue;
			}

			playField[i][j] = '.';

			int y = j;
			for (; y < HEIGHT - 2 && playField[y + 1][j] != 'X'; ++y)
			{
				
			}

			playField[y][j] = 'X';
		}
	}
}

void scoreCheck(char playField[HEIGHT][WIDTH])
{
	for (int i = HEIGHT - 1; i > 1; --i)
	{
		for (int j = 1; j < WIDTH - 1 && playField[i][j] == 'X'; ++j)
		{
 			if (j == WIDTH - 2)
			{
				deleteLine(playField, i);
				pullToButtom(playField, i);
			}
		}
	}
}
