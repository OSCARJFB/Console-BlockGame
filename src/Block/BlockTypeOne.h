/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

#include "BlockProperties.h"
#include "Block.h"
#include "../gameField/gameField.h"

class BlockTypeOne : public BlockProperties
{
public:
	BlockTypeOne() = default;
	void rotate(const char playField[HEIGHT][WIDTH], Block& block);

private:
	void setBlock(Block& block, const Vector2 vec[6]);
	void firstState(const char playField[HEIGHT][WIDTH], Block& block);
	void secondState(const char playField[HEIGHT][WIDTH], Block& block);
	void thirdState(const char playField[HEIGHT][WIDTH], Block& block);
	void fourthState(const char playField[HEIGHT][WIDTH], Block& block);
};