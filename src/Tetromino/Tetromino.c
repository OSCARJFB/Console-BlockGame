#include "Tetromino.h"

static void handleByType(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	switch (tetromino->type)
	{
	case straight:
		straightRotation(playField, tetromino);
		break;
	case square:
		// squareRotation(playField, tetromino);
		break;
	case tshape:
		// tshapeRotation(playField, tetromino);
		break;
	case lshape:
		// lshapeRotation(playField, tetromino);
		break;
	case skew:
		// skewRotation(playField, tetromino);
		break;
	}
}

static inline void lockToPlayfied(char playField[HEIGHT][WIDTH], const Tetromino* tetromino)
{
	playField[tetromino->vector2[0].y][tetromino->vector2[0].x] = 'X';
	playField[tetromino->vector2[1].y][tetromino->vector2[1].x] = 'X';
	playField[tetromino->vector2[2].y][tetromino->vector2[2].x] = 'X';
	playField[tetromino->vector2[3].y][tetromino->vector2[3].x] = 'X';
	tetromino = NULL;
}

bool isBottomCollision(char playField[HEIGHT][WIDTH], const Tetromino* tetromino)
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

bool isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[4])
{
	bool isCollision = false;
	for (int i = 0; i < 4; ++i)
	{
		if (playField[vec[i].y][vec[i].x] == 'X' || playField[vec[i].y][vec[i].x] == '=' && vec[i].y != 0)
		{
			isCollision = true;
		}
	}

	return isCollision;
}

static inline bool left(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	bool isInPlayField = true;
	isInPlayField = (tetromino->vector2[0].x > 1);
	isInPlayField = (tetromino->vector2[1].x > 1);
	isInPlayField = (tetromino->vector2[2].x > 1);
	isInPlayField = (tetromino->vector2[3].x > 1);

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[4] = {
		tetromino->vector2[0].x - 1, tetromino->vector2[0].y,
		tetromino->vector2[1].x - 1, tetromino->vector2[1].y,
		tetromino->vector2[2].x - 1, tetromino->vector2[2].y,
		tetromino->vector2[3].x - 1, tetromino->vector2[3].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	tetromino->vector2[0].x -= 1;
	tetromino->vector2[1].x -= 1;
	tetromino->vector2[2].x -= 1;
	tetromino->vector2[3].x -= 1;

	return true;
}

static inline bool right(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	bool isInPlayField = true;
	isInPlayField = (tetromino->vector2[0].x < WIDTH - 1);
	isInPlayField = (tetromino->vector2[1].x < WIDTH - 1);
	isInPlayField = (tetromino->vector2[2].x < WIDTH - 1);
	isInPlayField = (tetromino->vector2[3].x < WIDTH - 1);

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[4] = {
		tetromino->vector2[0].x + 1, tetromino->vector2[0].y,
		tetromino->vector2[1].x + 1, tetromino->vector2[1].y,
		tetromino->vector2[2].x + 1, tetromino->vector2[2].y,
		tetromino->vector2[3].x + 1, tetromino->vector2[3].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	tetromino->vector2[0].x += 1;
	tetromino->vector2[1].x += 1;
	tetromino->vector2[2].x += 1;
	tetromino->vector2[3].x += 1;

	return true;
}

bool direction(const char playField[HEIGHT][WIDTH], const char c, Tetromino* tetromino)
{
	bool changeDirection = false;
	switch (c)
	{
	case LEFT_KEY:
		changeDirection = left(playField, tetromino);
		break;
	case RIGHT_KEY:
		changeDirection = right(playField, tetromino);
		break;
	}
	return changeDirection;
}

void gravity(Tetromino* tetromino)
{
	tetromino->vector2[0].y += 1;
	tetromino->vector2[1].y += 1;
	tetromino->vector2[2].y += 1;
	tetromino->vector2[3].y += 1;
}

bool rotate(Tetromino* tetromino, const char playField[HEIGHT][WIDTH], const char c) 
{
 	if (c != SPACE_KEY)
	{
		return false;
	}
	handleByType(playField, tetromino);
	return true;
}

Tetromino spawn(const char playField[HEIGHT][WIDTH])
{
	// Tetromino tetromino = { rand() % 4, first};
	Tetromino tetromino = { straight, first };
	tetromino.vector2[1].y = 1;
	tetromino.vector2[1].x = WIDTH / 2;
	handleByType(playField, &tetromino);
	return tetromino;
}