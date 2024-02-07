#include "Tetromino.h"

static void set_1_straight(Tetromino* tetromino, int x, int y)
{
	while (x < 1)
	{
		++x;
	}

	if (x == WIDTH - 1)
	{
		x -= 4;
	}

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
	int x = tetromino->vector2[2].x;
	int y = tetromino->vector2[2].y - 1;
	
	while (x < 1)
	{
		++x;
	}

	if (x == WIDTH - 1)
	{
		x -= 4;
	}

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
	int x = tetromino->vector2[2].x - 3;
	int y = tetromino->vector2[2].y;

	while (x < 1)
	{
		++x;
	}

	if (x == WIDTH - 1)
	{
		x -= 4;
	}

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
	int x = tetromino->vector2[1].x;
	int y = tetromino->vector2[1].y - 2;

	while (x < 1)
	{
		++x;
	}

	if (x == WIDTH - 1)
	{
		x -= 4;
	}

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
	case first:
		set_1_straight(tetromino, tetromino->vector2[1].x, tetromino->vector2[1].y);
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
