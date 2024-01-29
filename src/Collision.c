#include "Collision.h"

void handleBottomCollision(char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	unsigned int vecIndex = 0;
	for (unsigned int i = 0; i < HEIGHT; ++i)
	{
		for (unsigned int j = 0; j < WIDTH; ++j)
		{
			if (tetromino->vector2[vecIndex].y == i && tetromino->vector2[vecIndex].x == j)
			{
				if (playField[i + 1][j] == 'X' || playField[i + 1][j] == '=')
				{
					setToStatic(playField, tetromino);
					break;
				}
			}
		}
	}
}

void handleRotationCollision(char playField[HEIGHT][WIDTH], Tetromino* tetromino)
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