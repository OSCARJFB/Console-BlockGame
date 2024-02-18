/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "Block.h"

void Block::spawnSquare(Block& Block)
{
	int x = Block.m_vector2[0].x, y = Block.m_vector2[0].y;
	Block.m_vector2[1].x = x + 1;
	Block.m_vector2[1].y = y;
	Block.m_vector2[2].x = x;
	Block.m_vector2[2].y = y + 1;
	Block.m_vector2[3].x = x + 1;
	Block.m_vector2[3].y = y + 1;
	Block.m_state = second;
}

void Block::squareRotation(Block& Block)
{
	if (Block.m_state == first)
	{
		spawnSquare(Block);
	}
}