/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "Block.h"

void Block::handleByType(const char playField[HEIGHT][WIDTH], Block& block)
{
	switch (block.m_type)
	{
	case straightBlock:
		straightRotation(playField, block);
		break;
	case squareBlock:
		squareRotation(block);
		break;
		break;
	}
}

void Block::lockToPlayfied(char playField[HEIGHT][WIDTH], const Block& Block)
{
	playField[Block.m_vector2[0].y][Block.m_vector2[0].x] = 'X';
	playField[Block.m_vector2[1].y][Block.m_vector2[1].x] = 'X';
	playField[Block.m_vector2[2].y][Block.m_vector2[2].x] = 'X';
	playField[Block.m_vector2[3].y][Block.m_vector2[3].x] = 'X';
}

bool Block::isBottomCollision(char playField[HEIGHT][WIDTH], const Block& Block)
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			for (int n = 0; n < 4; ++n)
			{
				if (Block.m_vector2[n].y == i && Block.m_vector2[n].x == j)
				{
					if (playField[i + 1][j] == 'X' || playField[i + 1][j] == '=')
					{
						lockToPlayfied(playField, Block);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Block::isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[4])
{
	bool isCollision = false;
	for (int i = 0; i < 4; ++i)
	{
		if (playField[vec[i].y][vec[i].x] == 'X' || playField[vec[i].y][vec[i].x] == '=' && vec[i].y != 0)
		{
			isCollision = true;
		}
	}

	return isCollision;
}

bool Block::left(const char playField[HEIGHT][WIDTH], Block& Block)
{
	bool isInPlayField = true;
	isInPlayField = (Block.m_vector2[0].x > 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[1].x > 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[2].x > 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[3].x > 1) && isInPlayField;

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[4] = {
		Block.m_vector2[0].x - 1, Block.m_vector2[0].y,
		Block.m_vector2[1].x - 1, Block.m_vector2[1].y,
		Block.m_vector2[2].x - 1, Block.m_vector2[2].y,
		Block.m_vector2[3].x - 1, Block.m_vector2[3].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	Block.m_vector2[0].x -= 1;
	Block.m_vector2[1].x -= 1;
	Block.m_vector2[2].x -= 1;
	Block.m_vector2[3].x -= 1;

	return true;
}

bool Block::right(const char playField[HEIGHT][WIDTH], Block& Block)
{
	bool isInPlayField = true;
	isInPlayField = (Block.m_vector2[0].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[1].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[2].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[3].x < WIDTH - 1) && isInPlayField;

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[4] = {
		Block.m_vector2[0].x + 1, Block.m_vector2[0].y,
		Block.m_vector2[1].x + 1, Block.m_vector2[1].y,
		Block.m_vector2[2].x + 1, Block.m_vector2[2].y,
		Block.m_vector2[3].x + 1, Block.m_vector2[3].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	Block.m_vector2[0].x += 1;
	Block.m_vector2[1].x += 1;
	Block.m_vector2[2].x += 1;
	Block.m_vector2[3].x += 1;

	return true;
}

bool Block::direction(const char playField[HEIGHT][WIDTH], const char c, Block& Block)
{
	bool changeDirection = false;
	switch (c)
	{
	case LEFT_KEY:
		changeDirection = left(playField, Block);
		break;
	case RIGHT_KEY:
		changeDirection = right(playField, Block);
		break;
	}
	return changeDirection;
}

void Block::gravity(Block& Block)
{
	Block.m_vector2[0].y += 1;
	Block.m_vector2[1].y += 1;
	Block.m_vector2[2].y += 1;
	Block.m_vector2[3].y += 1;
}

bool Block::rotate(Block& Block, const char playField[HEIGHT][WIDTH], const char c)
{
 	if (c != SPACE_KEY)
	{
		return false;
	}
	handleByType(playField, Block);
	return true;
}

void Block::spawn(const char playField[HEIGHT][WIDTH])
{
	this->m_type = static_cast<Type>(rand() % 2);
	this->m_state = first;
	
	switch (this->m_type)
	{
	case straightBlock:
		this->m_vector2[1].y = 1;
		this->m_vector2[1].x = WIDTH / 2;
		break;
	case squareBlock:
		this->m_vector2[0].y = 1;
		this->m_vector2[0].x = WIDTH / 2;
		break;
	}

	handleByType(playField, *this);
}