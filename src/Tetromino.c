#include "Tetromino.h"

static void set_1_Straight(Tetromino* tetromino, unsigned int x, unsigned int y)
{
	tetromino->vector2[0].y = y;
	tetromino->vector2[0].x = x;

	tetromino->vector2[1].y = y;
	tetromino->vector2[1].x = x + 1;

	tetromino->vector2[2].y = y;
	tetromino->vector2[2].x = x + 2;

	tetromino->vector2[3].y = y;
	tetromino->vector2[3].x = x + 3;
}

static void set_2_Straight(Tetromino* tetromino)
{
	unsigned int x = tetromino->vector2[3].x;
	unsigned int y = tetromino->vector2[3].y - 1;

	tetromino->vector2[0].y = y;
	tetromino->vector2[0].x = x;

	tetromino->vector2[1].y = y + 1;
	tetromino->vector2[1].x = x;

	tetromino->vector2[2].y = y + 2;
	tetromino->vector2[2].x = x;

	tetromino->vector2[3].y = y + 3;
	tetromino->vector2[3].x = x;
}

static void set_3_Straight(Tetromino* tetromino)
{
	unsigned int x = tetromino->vector2[2].x - 3;
	unsigned int y = tetromino->vector2[2].y;

	tetromino->vector2[0].y = y;
	tetromino->vector2[0].x = x;

	tetromino->vector2[1].y = y;
	tetromino->vector2[1].x = x + 1;

	tetromino->vector2[2].y = y;
	tetromino->vector2[2].x = x + 2;

	tetromino->vector2[3].y = y;
	tetromino->vector2[3].x = x + 3;
}

static void set_4_Straight(Tetromino* tetromino)
{
	unsigned int x = tetromino->vector2[1].x;
	unsigned int y = tetromino->vector2[1].y - 2;

	tetromino->vector2[0].y = y;
	tetromino->vector2[0].x = x;

	tetromino->vector2[1].y = y + 1;
	tetromino->vector2[1].x = x;

	tetromino->vector2[2].y = y + 2;
	tetromino->vector2[2].x = x;

	tetromino->vector2[3].y = y + 3;
	tetromino->vector2[3].x = x;
}

void straightRotation(Tetromino* tetromino)
{
	switch (tetromino->state)
	{
	case FIRST:
		set_1_Straight(tetromino, 3, 3);
		tetromino->state = SECOND;
		break;
	case SECOND:
		set_2_Straight(tetromino);
		tetromino->state = THIRD;
		break;
	case THIRD:
		set_3_Straight(tetromino);
		tetromino->state = FOURTH;
		break;
	case FOURTH:
		set_4_Straight(tetromino);
		tetromino->state = FIRST;
		break;
	}
}

void rotate(Tetromino* tetromino)
{
	switch (tetromino->type)
	{
	case STRAIGHT:
		straightRotation(tetromino);
		break;
	case SQUARE:
		// squareRotation(tetromino);
		break;
	case TSHAPE:
		//setBaseTShape(tetromino, 1, 0);
		break;
	case LSHAPE:
		//setBaseLShape(tetromino, 1, 0);
		break;
	case SKEW:
		//setBaseLSkew(tetromino, 1, 0);
		break;
	}
}