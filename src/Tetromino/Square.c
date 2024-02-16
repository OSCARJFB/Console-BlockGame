#include "Tetromino.h"

static inline void spawnSquare(Tetromino* tetromino)
{
	int x = tetromino->vector2[0].x, y = tetromino->vector2[0].y;
	tetromino->vector2[1].x = x + 1;
	tetromino->vector2[1].y = y;
	tetromino->vector2[2].x = x;
	tetromino->vector2[2].y = y + 1;
	tetromino->vector2[3].x = x + 1;
	tetromino->vector2[3].y = y + 1;
	tetromino->state = second;
}

void squareRotation(Tetromino* tetromino)
{
	if (tetromino->state == first)
	{
		spawnSquare(tetromino);
	}
}