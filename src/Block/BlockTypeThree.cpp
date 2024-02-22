/*
		Writen by: Oscar Bergstr�m
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergstr�m
*/

#include "BlockTypeThree.h"

void BlockTypeThree::rotate(const char playField[HEIGHT][WIDTH], Block& block)
{
	switch (block.m_state)
	{
	case State::first:
		firstState(playField, block);
		break;
	case State::second:
		secondState(playField, block);
		break;
	case State::third:
		thirdState(playField, block);
		break;
	case State::fourth:
		fourthState(playField, block);
		break;
	}
}

inline void BlockTypeThree::setBlock(Block& block, const Vector2 vec[6])
{
	block.m_vector2[0] = vec[0];
	block.m_vector2[1] = vec[1];
	block.m_vector2[2] = vec[2];
	block.m_vector2[3] = vec[3];
	block.m_vector2[4] = vec[4];
	block.m_vector2[5] = vec[5];
}


//  [][][][][]
//    []
void BlockTypeThree::firstState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{x, y},
		{x + 1, y + 1},
		{x + 1, y},
		{x + 2, y},
		{x + 3, y},
		{x + 4, y},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::second;
}

//    []
//  [][]
//	  []
//	  []
//	  []

void BlockTypeThree::secondState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{x, y},
		{x, y + 1},
		{x - 1, y + 1},
		{x, y + 2},
		{x, y + 3},
		{x, y + 4},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::third;
}

//       []
// [][][][][]
void BlockTypeThree::thirdState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{x, y},
		{x - 1, y},
		{x - 1, y - 1},
		{x - 2, y},
		{x - 3, y},
		{x - 4, y},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::fourth;
}
//		 []
//       []
//       []
//       [][]
//       []
void BlockTypeThree::fourthState(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	Vector2 vec[6] = {
		{x, y},
		{x, y - 1},
		{x + 1, y - 1},
		{x, y - 2},
		{x, y - 3},
		{x, y - 4},
	};

	if (block.isCollision(playField, vec))
	{
		return;
	}

	setBlock(block, vec);
	block.m_state = State::first;
}
