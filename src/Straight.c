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
	unsigned int x = tetromino->vector2[2].x;
	unsigned int y = tetromino->vector2[2].y - 1;

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
	unsigned int x = tetromino->vector2[2].x - 2;
	unsigned int y = tetromino->vector2[2].y;

	tetromino->vector2[0].y = y;
	tetromino->vector2[0].x;

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