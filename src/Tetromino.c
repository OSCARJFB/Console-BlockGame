#include "Tetromino.h"

static void set_1_straight(Tetromino* tetromino, unsigned int x, unsigned int y)
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

static void set_2_straight(Tetromino* tetromino)
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

static void set_3_straight(Tetromino* tetromino)
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

static void set_4_straight(Tetromino* tetromino)
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

static void straightRotation(Tetromino* tetromino)
{
	switch (tetromino->state)
	{
	case first:
		set_1_straight(tetromino, 3, 3);
		tetromino->state = second;
		break;
	case second:
		set_2_straight(tetromino);
		tetromino->state = third;
		break;
	case third:
		set_3_straight(tetromino);
		tetromino->state = fourth;
		break;
	case fourth:
		set_4_straight(tetromino);
		tetromino->state = first;
		break;
	}
}

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

Tetromino spawn(void)
{
	// Tetromino tetromino = { rand() % 4, first};
	Tetromino tetromino = { straight, first };
	handleByType(&tetromino);
	return tetromino;
}

void reverseState(Tetromino* tetromino)
{
	switch (tetromino->state)
	{
	case first:
		tetromino->state = fourth;
	case second:
		tetromino->state = first;
	case third:
		tetromino->state = second;
	case fourth:
		tetromino->state = third;
	}
	handleByType(tetromino);
}

bool rotate(Tetromino* tetromino, char c) 
{
	if (c != 32)
	{
		return false;
	}
	handleByType(tetromino);
	return true;
}