/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
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
	GameField gameField = GameField(playField);

	Console console = Console();
	Block block = Block(playField);

	while ((c = console.kbhit()) != EOF)
	{
		if (!block.rotate(block, playField, c) && !block.direction(playField, c, block))
		{
			TICK_FRAME(framelock())
				block.gravity(block);
		}

		if (block.isBottomCollision(playField, block))
		{
			block.spawn(playField);
		}
		gameField.printGameField(playField, block, console);
		gameField.scoreCheck(playField);
	}
}