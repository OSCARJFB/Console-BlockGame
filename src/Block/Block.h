/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

#include <cstdlib>
#include <ctime>
#include "../gameField/gameFieldSize.h"
#include "BlockProperties.h"

#define SPACE_KEY ' '
#define LEFT_KEY 'a'
#define RIGHT_KEY 'd'

class Block : public BlockProperties
{
public:
	Block(const char playField[HEIGHT][WIDTH])
	{
		spawn(playField);
	};
	~Block() = default;

public:
	void spawn(const char playField[HEIGHT][WIDTH]);
	void gravity(Block& block);
	bool direction(const char playField[HEIGHT][WIDTH], const char c, Block& block);
	bool rotate(Block& block, const char playField[HEIGHT][WIDTH], char c);
	bool isBottomCollision(char playField[HEIGHT][WIDTH], const Block& block);
	bool isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[4]);

private:
	void handleByType(const char playField[HEIGHT][WIDTH], Block& block);
	void straightRotation(const char playField[HEIGHT][WIDTH], Block& block);
	void set_1_straight(const char playField[HEIGHT][WIDTH], Block& block);
	void set_2_straight(const char playField[HEIGHT][WIDTH], Block& block);
	void set_3_straight(const char playField[HEIGHT][WIDTH], Block& block);
	void set_4_straight(const char playField[HEIGHT][WIDTH], Block& block);
	void squareRotation(Block& Block);
	void spawnSquare(Block& Block);
	void lockToPlayfied(char playField[HEIGHT][WIDTH], const Block& block);
	bool left(const char playField[HEIGHT][WIDTH], Block& block);
	bool right(const char playField[HEIGHT][WIDTH], Block& block);
};