/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "Block.h"

void Block::set_1_straight(const char playField[HEIGHT][WIDTH], Block& Block)
{
	int x = Block.m_vector2[1].x, y = Block.m_vector2[1].y;
	Vector2 vec[4] = {
		{x, y},
		{x + 1, y},
		{x + 2, y},
		{x + 3, y},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	Block.m_vector2[0] = vec[0];
	Block.m_vector2[1] = vec[1];
	Block.m_vector2[2] = vec[2];
	Block.m_vector2[3] = vec[3];
	Block.m_state = second;
}

void Block::set_2_straight(const char playField[HEIGHT][WIDTH], Block& Block)
{
	int x = Block.m_vector2[2].x, y = Block.m_vector2[2].y - 1;
	Vector2 vec[4] = {
		{x, y},
		{x, y + 1},
		{x, y + 2},
		{x, y + 3},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	Block.m_vector2[0] = vec[0];
	Block.m_vector2[1] = vec[1];
	Block.m_vector2[2] = vec[2];
	Block.m_vector2[3] = vec[3];
	Block.m_state = third;
}

void Block::set_3_straight(const char playField[HEIGHT][WIDTH], Block& Block)
{
	int x = Block.m_vector2[2].x - 3;
	int y = Block.m_vector2[2].y;
	Vector2 vec[4] = {
		{x, y},
		{x + 1, y},
		{x + 2, y},
		{x + 3, y},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	Block.m_vector2[0] = vec[0];
	Block.m_vector2[1] = vec[1];
	Block.m_vector2[2] = vec[2];
	Block.m_vector2[3] = vec[3];
	Block.m_state = fourth;
}

void Block::set_4_straight(const char playField[HEIGHT][WIDTH], Block& Block)
{
	int x = Block.m_vector2[1].x;
	int y = Block.m_vector2[1].y - 2;
	Vector2 vec[4] = {
	{x, y},
	{x, y + 1},
	{x, y + 2},
	{x, y + 3},
	};

	if (isCollision(playField, vec))
	{
		return;
	}

	Block.m_vector2[0] = vec[0];
	Block.m_vector2[1] = vec[1];
	Block.m_vector2[2] = vec[2];
	Block.m_vector2[3] = vec[3];
	Block.m_state = first;
}

void Block::straightRotation(const char playField[HEIGHT][WIDTH], Block& Block)
{
	switch (Block.m_state)
	{
	case first:
		set_1_straight(playField, Block);
		break;
	case second:
		set_2_straight(playField, Block);
		break;
	case third:
		set_3_straight(playField, Block);
		break;
	case fourth:
		set_4_straight(playField, Block);
		break;
	}
}
