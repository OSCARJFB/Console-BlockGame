#include "Tetromino.h"

static void handleByType(Tetromino* tetromino)
{
	switch (tetromino->type)
	{
	case straight:
		straightRotation(tetromino);
		break;
	case square:
		// squareRotation(tetromino);
		break;
	case tshape:
		//setBasetshape(tetromino, 1, 0);
		break;
	case lshape:
		//setBaselshape(tetromino, 1, 0);
		break;
	case skew:
		//setBaseLskew(tetromino, 1, 0);
		break;
	}
}

static inline bool left(Tetromino* tetromino)
{
	bool isInPlayField = true;
	isInPlayField = (tetromino->vector2[0].x > 1 ? isInPlayField = isInPlayField ? true : false : false);
	isInPlayField = (tetromino->vector2[1].x > 1 ? isInPlayField = isInPlayField ? true : false : false);
	isInPlayField = (tetromino->vector2[2].x > 1 ? isInPlayField = isInPlayField ? true : false : false);
	isInPlayField = (tetromino->vector2[3].x > 1 ? isInPlayField = isInPlayField ? true : false : false);

	if (!isInPlayField)
	{
		return isInPlayField;
	}

	tetromino->vector2[0].x -= 1;
	tetromino->vector2[1].x -= 1;
	tetromino->vector2[2].x -= 1;
	tetromino->vector2[3].x -= 1;

	return isInPlayField;
}

static inline bool right(Tetromino* tetromino)
{
	bool isInPlayField = true;
	isInPlayField = (tetromino->vector2[0].x < HEIGHT - 2 ? isInPlayField = isInPlayField ? true : false : false);
	isInPlayField = (tetromino->vector2[1].x < HEIGHT - 2 ? isInPlayField = isInPlayField ? true : false : false);
	isInPlayField = (tetromino->vector2[2].x < HEIGHT - 2 ? isInPlayField = isInPlayField ? true : false : false);
	isInPlayField = (tetromino->vector2[3].x < HEIGHT - 2 ? isInPlayField = isInPlayField ? true : false : false);

	if (!isInPlayField)
	{
		return isInPlayField;
	}

	tetromino->vector2[0].x += 1;
	tetromino->vector2[1].x += 1;
	tetromino->vector2[2].x += 1;
	tetromino->vector2[3].x += 1;

	return isInPlayField;
}

bool direction(Tetromino* tetromino, const char c)
{
	bool changeDirection = false;
	switch (c)
	{
	case LEFT_KEY:
		changeDirection = left(tetromino);
		break;	
	case RIGHT_KEY:
		changeDirection = right(tetromino);
		break;
	}
	return changeDirection;
}

bool rotate(Tetromino* tetromino, const char playField[HEIGHT][WIDTH], const char c) 
{
 	if (c != SPACE_KEY)
	{
		return false;
	}
	handleByType(tetromino);
	return true;
}

void gravity(Tetromino* tetromino)
{
	tetromino->vector2[0].y += 1; 
	tetromino->vector2[1].y += 1;
	tetromino->vector2[2].y += 1;
	tetromino->vector2[3].y += 1;
}

Tetromino spawn(void)
{
	// Tetromino tetromino = { rand() % 4, first};
	Tetromino tetromino = { straight, first };
	tetromino.vector2[1].y = 1;
	tetromino.vector2[1].x = WIDTH / 2;
	handleByType(&tetromino);
	return tetromino;
}
