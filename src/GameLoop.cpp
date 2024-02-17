/*
		Writen by: Oscar Bergstr�m
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergstr�m
*/

#include "GameLoop.h"

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

void run()
{
	char c = 0;
	char playField[HEIGHT][WIDTH];

	std::srand((unsigned int)std::time(NULL));
	initPlayField(playField);

	Console console = Console();
	Tetromino tetromino = Tetromino(playField);

	while ((c = console.kbhit()) != EOF)
	{
		scoreCheck(playField);
		if (!tetromino.rotate(tetromino, playField, c) && !tetromino.direction(playField, c, tetromino))
		{
			TICK_FRAME(framelock())
				tetromino.gravity(tetromino);
		}

		if (tetromino.isBottomCollision(playField, tetromino))
		{
			tetromino.spawn(playField);
		}
		printPlayField(playField, tetromino, console);
	}
}