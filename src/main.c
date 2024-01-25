#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "Tetromino.h"
#include "Console.h"
#include "Keys.h"

#define HEIGHT 24 // 16 or 24 cells in height
#define WIDTH 11 // 10 cells width + newline

static void initPlayField(char playField[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (j != WIDTH - 1)
			{
				playField[i][j] = ' ';
				continue;
			}
			playField[i][j] = '\n';
		}
	}
}

static void printPlayField(char playField[HEIGHT][WIDTH], Tetromino* tetromino)
{
	int curVec = 0;
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			printf("%c", playField[i][j]);
			if (tetromino->vector2[curVec].y == i && tetromino->vector2[curVec].x == j)
			{
				printf("%c", 'X');
				++curVec;
			}
		}
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
	double diff = difftime(end, start);
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
		if (!framelock() && !rotate(&tetromino, c))
		{
			continue;
		}

		system("cls");
		printPlayField(playField, &tetromino);
	}

	return 0;
}