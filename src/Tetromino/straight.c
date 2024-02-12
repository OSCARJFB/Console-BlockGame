#include "Tetromino.h"

static void set_1_straight(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	int x = tetromino->vector2[1].x, y = tetromino->vector2[1].y;
	Vector2 vec[4] = {
		{x, y},
		{x + 1, y},
		{x + 2, y},
		{x + 3, y},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	tetromino->vector2[0] = vec[0];
	tetromino->vector2[1] = vec[1];
	tetromino->vector2[2] = vec[2];
	tetromino->vector2[3] = vec[3];
	tetromino->state = second;
}

static void set_2_straight(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	int x = tetromino->vector2[2].x, y = tetromino->vector2[2].y - 1;
	Vector2 vec[4] = {
		{x, y},
		{x, y + 1},
		{x, y + 2},
		{x, y + 3},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	tetromino->vector2[0] = vec[0];
	tetromino->vector2[1] = vec[1];
	tetromino->vector2[2] = vec[2];
	tetromino->vector2[3] = vec[3];
	tetromino->state = third;
}

static void set_3_straight(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	int x = tetromino->vector2[2].x - 3;
	int y = tetromino->vector2[2].y;
	Vector2 vec[4] = {
		{x, y},
		{x + 1, y},
		{x + 2, y},
		{x + 3, y},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	tetromino->vector2[0] = vec[0];
	tetromino->vector2[1] = vec[1];
	tetromino->vector2[2] = vec[2];
	tetromino->vector2[3] = vec[3];
	tetromino->state = fourth;
}

static void set_4_straight(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	int x = tetromino->vector2[1].x;
	int y = tetromino->vector2[1].y - 2;
	Vector2 vec[4] = {
	{x, y},
	{x, y + 1},
	{x, y + 2},
	{x, y + 3},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	tetromino->vector2[0] = vec[0];
	tetromino->vector2[1] = vec[1];
	tetromino->vector2[2] = vec[2];
	tetromino->vector2[3] = vec[3];
	tetromino->state = first;
}

void straightRotation(const char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	switch (tetromino->state)
	{
	case first:
		set_1_straight(playField, tetromino);
		break;
	case second:
		set_2_straight(playField, tetromino);
		break;
	case third:
		set_3_straight(playField, tetromino);
		break;
	case fourth:
		set_4_straight(playField, tetromino);
		break;
	}
}
