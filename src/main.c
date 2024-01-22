#include <stdio.h>
#include "Tetromino.h"
#include "Console.h"

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

int main(void)
{
	Tetromino tetromino;
	tetromino.type = STRAIGHT;
	tetromino.state = FIRST;
	char playField[HEIGHT][WIDTH];

	initConsole();
	initPlayField(playField);

	char c;
	rotate(&tetromino);
	while ((c = kbhit()) != EOF)
	{
		if (c == 32)
		{
			rotate(&tetromino);
		}
		printPlayField(playField, &tetromino);
		system("cls");
	}

	return 0;
}