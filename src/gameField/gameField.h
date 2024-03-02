/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

#include <iostream>
#include "gameFieldSize.h"
#include "../Console/Console.h"
#include "../Block/Block.h"

#define BLOCK '#'

class GameField
{
public:
	GameField(char playField[HEIGHT][WIDTH]);
	~GameField() = default;
	void printGameField(char playField[HEIGHT][WIDTH], const Block& Block, const Console& console);
	void scoreCheck(char playField[HEIGHT][WIDTH]);
	bool isGameOver(char playField[HEIGHT][WIDTH]);

private:
	void deleteLine(char playField[HEIGHT][WIDTH], int row);
	void pullBlockToBottom(char playField[HEIGHT][WIDTH], int row);

private:
	char m_playField[HEIGHT][WIDTH];
};