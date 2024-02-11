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
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			for (int n = 0; n < 4; ++n)
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

int preventWallCollision(int x)
{
	while (x < 1)
	{
		++x;
	}

	if (x == WIDTH - 1)
	{
		x -= 4;
	}

	return x;
}

bool isCollisionAtRotation(const char playField[HEIGHT][WIDTH], const Vector2 vec[4])
{
	bool isCollision = false;
	isCollision = playField[vec[0].y][vec[0].x] == 'X' || playField[vec[0].y][vec[0].x] == '=';
	isCollision = playField[vec[1].y][vec[1].x] == 'X' || playField[vec[1].y][vec[1].x] == '=';
	isCollision = playField[vec[2].y][vec[2].x] == 'X' || playField[vec[2].y][vec[2].x] == '=';
	isCollision = playField[vec[3].y][vec[3].x] == 'X' || playField[vec[3].y][vec[3].x] == '=';
	return isCollision;
}