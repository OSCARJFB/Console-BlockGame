#include "Collision.h"

void handleCollision(char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	unsigned int vecIndex = 0;
	for (unsigned int i = 0; i < HEIGHT; ++i)
	{
		for (unsigned int j = 0; j < WIDTH; ++j)
		{
			if (tetromino->vector2[vecIndex].y == i && tetromino->vector2[vecIndex].x == j)
			{
				if (playField[i][j] == 'B')
				{
					reverseState(tetromino);
				}
				else if (playField[i][j] == 'D')
				{
					reverseState(tetromino);
				}
			}
		}
	}
}