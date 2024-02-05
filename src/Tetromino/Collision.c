#include "Tetromino.h"


static void lockToPlayfied(char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	playField[tetromino->vector2[0].y][tetromino->vector2[0].x] = 'X';
	playField[tetromino->vector2[1].y][tetromino->vector2[1].x] = 'X';
	playField[tetromino->vector2[2].y][tetromino->vector2[2].x] = 'X';
	playField[tetromino->vector2[3].y][tetromino->vector2[3].x] = 'X';
}

bool isBottomCollision(char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	for (unsigned int i = 0; i < HEIGHT; ++i)
	{
		for (unsigned int j = 0; j < WIDTH; ++j)
		{
			for (unsigned int n = 0; n < 4; ++n)
			{
				if (tetromino->vector2[n].y == i && tetromino->vector2[n].x == j)
				{
					if (playField[i + 1][j] == 'X' || playField[i + 1][j] == '=')
					{
						lockToPlayfied(playField, tetromino);
						return true;
					}
				}
			}
		}
	}
	return false;
}

void handleRotationCollision(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	unsigned int vecIndex = 0;
	for (unsigned int i = 0; i < HEIGHT; ++i)
	{
		for (unsigned int j = 0; j < WIDTH; ++j)
		{
			if (tetromino->vector2[vecIndex].y == i && tetromino->vector2[vecIndex].x == j)
			{
				if (playField[i][j] == '=')
				{
					reverseState(tetromino);
					break;
				}
			}
		}
	}
}