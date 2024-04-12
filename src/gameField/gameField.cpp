/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "gameField.h"
#include "../Console/Console.h"

GameField::GameField(char playField[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (j == 0 || j == WIDTH - 1 || i == HEIGHT - 1) {
				playField[i][j] = '=';
				continue;
			}
			if (j != WIDTH)
				playField[i][j] = '.';
		}
	}
}

void GameField::printGameField(char playField[HEIGHT][WIDTH], const Block& Block, Console& console)
{
	int i = sizeof(Block.m_vector2) / sizeof(Block::Vector2);
	for (int i = 0; i < sizeof(Block.m_vector2) / sizeof(Block::Vector2); ++i) {
		playField[Block.m_vector2[i].y][Block.m_vector2[i].x] = BLOCK;
	}

	console.ClearScreen();
	int color = std::rand() % 4 + 1;
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (playField[i][j] == BLOCK) {
				console.Print(playField[i][j], j, i, color);
				continue;
			}
			if (playField[i][j] == 'X') {
				console.Print(playField[i][j], j, i, color);
				continue;
			}
			console.Print(playField[i][j], j, i);
		}
		std::printf("\n");
	}

	for (int i = 0; i < sizeof(Block.m_vector2) / sizeof(Block::Vector2); ++i)
		playField[Block.m_vector2[i].y][Block.m_vector2[i].x] = '.';
}

void GameField::deleteLine(char playField[HEIGHT][WIDTH], int row)
{
	for (int i = 1; i < WIDTH - 1; ++i)
		playField[row][i] = '.';
}

void GameField::pullBlocksToBottom(char playField[HEIGHT][WIDTH], int row)
{
	for (int i = row + 1; i > 1; --i) {
		for (int j = 1; j < WIDTH - 1; ++j) {
			if (playField[i][j] != 'X')
				continue;
			playField[i][j] = '.';
			int y = j;
			for (; y < HEIGHT - 2 && playField[y + 1][j] != 'X'; ++y);
			playField[y][j] = 'X';
		}
	}
}

void GameField::scoreCheck(char playField[HEIGHT][WIDTH])
{
	for (int i = HEIGHT - 1; i > 1; --i) {
		for (int j = 1; j < WIDTH - 1 && playField[i][j] == 'X'; ++j) {
 			if (j == WIDTH - 2) {
				deleteLine(playField, i);
				pullBlocksToBottom(playField, i);
			}
		}
	}
}

bool GameField::isGameOver(char playField[HEIGHT][WIDTH])
{
	for (int i = 0; i < WIDTH; ++i) {
		if (playField[1][i] == 'X')
			return true;
	}
	return false;
}