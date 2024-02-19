/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "BlockTypeOne.h"

BlockTypeOne::BlockTypeOne(const char playField[HEIGHT][WIDTH], Block& block)
{
	switch (block.m_state)
	{
	case State::first:
		firstState(playField, block);
		break;
	case State::second:
		break;
		secondState(playField, block);
	case State::third:
		break;
		thirdState(playField, block);
	case State::fourth:
		fourthState(playField, block);
		break;
	}
}

inline void BlockTypeOne::setBlock(Block& block, const Vector2 vec[6])
{
	block.m_vector2[0] = vec[0];
	block.m_vector2[1] = vec[1];
	block.m_vector2[2] = vec[2];
	block.m_vector2[3] = vec[3];
	block.m_vector2[4] = vec[4];
	block.m_vector2[5] = vec[5];
}


//	[]	  []
//  [][][][]
void BlockTypeOne::firstState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{block.m_vector2[0].x, block.m_vector2[0].y},
		{block.m_vector2[1].x, block.m_vector2[1].y = y + 1},
		{block.m_vector2[2].x = x + 1, block.m_vector2[2].y = y + 1},
		{block.m_vector2[3].x = x + 2, block.m_vector2[3].y = y + 1},
		{block.m_vector2[4].x = x + 3, block.m_vector2[4].y = y + 1},
		{block.m_vector2[5].x = x + 3, block.m_vector2[5].y},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::second;
}

//	[][]
//  []
//  []
//	[][]
void BlockTypeOne::secondState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{block.m_vector2[0].x, block.m_vector2[0].y},
		{block.m_vector2[1].x = x + 1, block.m_vector2[1].y},
		{block.m_vector2[2].x, block.m_vector2[2].y = y + 1},
		{block.m_vector2[3].x, block.m_vector2[3].y = y + 2},
		{block.m_vector2[4].x, block.m_vector2[4].y = y + 3},
		{block.m_vector2[5].x = x + 1, block.m_vector2[5].y = y + 3},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::second;
}

//	[][][][]
//  []    []
void BlockTypeOne::thirdState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{block.m_vector2[0].x, block.m_vector2[0].y},
		{block.m_vector2[1].x, block.m_vector2[1].y = y + 1},
		{block.m_vector2[2].x = x + 1, block.m_vector2[2].y = y + 1},
		{block.m_vector2[3].x = x + 2, block.m_vector2[3].y},
		{block.m_vector2[4].x = x + 3, block.m_vector2[4].y},
		{block.m_vector2[5].x = x + 3, block.m_vector2[5].y = y + 1},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::second;
}

//	[][]
//    []
//	  []
//  [][]
void BlockTypeOne::fourthState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{block.m_vector2[0].x, block.m_vector2[0].y},
		{block.m_vector2[1].x = x + 1, block.m_vector2[1].y},
		{block.m_vector2[2].x = x + 1, block.m_vector2[2].y = y + 1},
		{block.m_vector2[3].x = x + 1, block.m_vector2[3].y = y + 2},
		{block.m_vector2[4].x = x + 1, block.m_vector2[4].y = y + 3},
		{block.m_vector2[5].x, block.m_vector2[5].y = y + 3},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::second;
}
