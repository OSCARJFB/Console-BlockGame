/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

#include <cstdlib>
#include <ctime>
#include <cmath>
#include "BlockProperties.h"
#include "../GameField/GameFieldSize.h"

#define SPACE_KEY ' '
#define LEFT_KEY 'a'
#define RIGHT_KEY 'd'
#define DOWN_KEY 's'

class Block : public BlockProperties
{
public:
	Block() = default;
	Block(const char playField[HEIGHT][WIDTH]);
	~Block() = default;

public:
	void spawn(const char playField[HEIGHT][WIDTH]);
	void gravity(Block& block);
	bool direction(const char playField[HEIGHT][WIDTH], const char c, Block& block);
	bool rotate(Block& block, const char playField[HEIGHT][WIDTH], char c);
	bool isBottomCollision(char playField[HEIGHT][WIDTH], const Block& block);
	bool isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[6]);

private:
	void blockArrayCpy(Vector2 src[6], Vector2 dest[6]);
	void rotateBlock(const char playField[HEIGHT][WIDTH], Block& block);
	void reshuffleSpawn();
	void spawnByType(const char playField[HEIGHT][WIDTH], Block& block);
	void lockToPlayfied(char playField[HEIGHT][WIDTH], const Block& block);
	bool left(const char playField[HEIGHT][WIDTH], Block& block);
	bool right(const char playField[HEIGHT][WIDTH], Block& block);
	bool down(const char playField[HEIGHT][WIDTH], Block& Block);
};