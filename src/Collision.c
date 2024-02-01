#include "Collision.h"

bool isBottomCollision(const char playField[HEIGHT][WIDTH], const Tetromino* tetromino)
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

void handleRotationCollision(const char playField[HEIGHT][WIDTH], const Tetromino* tetromino)
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