#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "Tetromino.h"
#include "Collision.h"
#include "Console.h"
#include "Keys.h"


#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

static void initPlayField(char playField[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (j == 0 || j == WIDTH - 1 || i == 0 || i == HEIGHT - 1)
			{
				playField[i][j] = '=';
				continue;
			}

			if (j != WIDTH)
			{
				playField[i][j] = ' ';
			}
		}
	}
}

static inline void clearScreen(void)
{
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif
}

static void printPlayField(const char playField[HEIGHT][WIDTH], const Tetromino* tetromino)
{
	unsigned int curVec = 0;
	clearScreen();
	for (unsigned int i = 0; i < HEIGHT; ++i)
	{
		for (unsigned j = 0; j < WIDTH; ++j)
		{
			if (tetromino->vector2[curVec].y == i && tetromino->vector2[curVec].x == j)
			{
				printf("%c", 'T');
				++curVec;
				continue;
			}
			printf("%c", playField[i][j]);
		}
		printf("\n");
	}
}

static bool framelock(void)
{
	static time_t start = 0, end = 0;

	if (start == 0)
	{
		start = time(NULL);
		return false;
	}

	end = time(NULL);
	const double diff = difftime(end, start);
	if (diff >= 1.0)
	{
		start = end = 0;
		return true;
	}

	return false;
}

int main(void)
{
	char c = 0;
	char playField[HEIGHT][WIDTH];

	srand((unsigned int)time(NULL));
	initConsole();
	initPlayField(playField);
	
	Tetromino tetromino = spawn();

	while ((c = kbhit()) != EOF)
	{
		if (rotate(&tetromino, c))
		{
 			handleRotationCollision(playField, &tetromino);
		}
		else
		{
			if (!framelock())
			{
				continue;
			}
			gravity(&tetromino);
		}

		if (isBottomCollision(playField, &tetromino))
		{
			tetromino = spawn();
		}

		printPlayField(playField, &tetromino);
	}

	return 0;
}