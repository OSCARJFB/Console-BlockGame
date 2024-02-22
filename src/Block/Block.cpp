/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "Block.h"

Block::Block(const char playField[HEIGHT][WIDTH])
{
	spawn(playField);
	m_blockTypeOne = new BlockTypeOne;
	m_blockTypeTwo = new BlockTypeTwo;
	m_blockTypeThree = new BlockTypeThree;
	m_blockTypeFour = new BlockTypeFour;
};

Block::~Block()
{
	delete m_blockTypeOne;
	m_blockTypeOne = nullptr;
	
	delete m_blockTypeTwo;
	m_blockTypeTwo = nullptr;

	delete m_blockTypeThree;
	m_blockTypeThree = nullptr;

	delete m_blockTypeFour;
	m_blockTypeFour = nullptr;
}

void Block::handleByType(const char playField[HEIGHT][WIDTH], Block& block)
{

	switch (block.m_type)
	{
	case Type::BlockOne:
		m_blockTypeOne->rotate(playField, block);
		break;
	case Type::BlockTwo:
		m_blockTypeTwo->rotate(playField, block);
		break;
	case Type::BlockThree:
		m_blockTypeThree->rotate(playField, block);
		break;
	}
}

void Block::lockToPlayfied(char playField[HEIGHT][WIDTH], const Block& Block)
{
	playField[Block.m_vector2[0].y - 1][Block.m_vector2[0].x] = 'X';
	playField[Block.m_vector2[1].y - 1][Block.m_vector2[1].x] = 'X';
	playField[Block.m_vector2[2].y - 1][Block.m_vector2[2].x] = 'X';
	playField[Block.m_vector2[3].y - 1][Block.m_vector2[3].x] = 'X';
	playField[Block.m_vector2[4].y - 1][Block.m_vector2[4].x] = 'X';
	playField[Block.m_vector2[5].y - 1][Block.m_vector2[5].x] = 'X';
}

bool Block::isBottomCollision(char playField[HEIGHT][WIDTH], const Block& Block)
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			for (int n = 0; n < 6; ++n)
			{
				if (Block.m_vector2[n].y == i && Block.m_vector2[n].x == j)
				{
					if (playField[i][j] == 'X' || playField[i][j] == '=')
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

bool Block::isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[6])
{
	bool isCollision = false;
	for (int i = 0; i < 6; ++i)
	{
		if (vec[i].x >= WIDTH || playField[vec[i].y][vec[i].x] == '=' || playField[vec[i].y][vec[i].x] == 'X')
		{
			isCollision = true;
			break;
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
	isInPlayField = (Block.m_vector2[4].x > 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[5].x > 1) && isInPlayField;

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[6] = {
		Block.m_vector2[0].x - 1, Block.m_vector2[0].y,
		Block.m_vector2[1].x - 1, Block.m_vector2[1].y,
		Block.m_vector2[2].x - 1, Block.m_vector2[2].y,
		Block.m_vector2[3].x - 1, Block.m_vector2[3].y,
		Block.m_vector2[4].x - 1, Block.m_vector2[4].y,
		Block.m_vector2[5].x - 1, Block.m_vector2[5].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	Block.m_vector2[0].x -= 1;
	Block.m_vector2[1].x -= 1;
	Block.m_vector2[2].x -= 1;
	Block.m_vector2[3].x -= 1;
	Block.m_vector2[4].x -= 1;
	Block.m_vector2[5].x -= 1;

	return true;
}

bool Block::right(const char playField[HEIGHT][WIDTH], Block& Block)
{
	bool isInPlayField = true;
	isInPlayField = (Block.m_vector2[0].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[1].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[2].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[3].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[4].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (Block.m_vector2[5].x < WIDTH - 1) && isInPlayField;

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[6] = {
		Block.m_vector2[0].x + 1, Block.m_vector2[0].y, 
		Block.m_vector2[1].x + 1, Block.m_vector2[1].y,
		Block.m_vector2[2].x + 1, Block.m_vector2[2].y, 
		Block.m_vector2[3].x + 1, Block.m_vector2[3].y,
		Block.m_vector2[4].x + 1, Block.m_vector2[4].y, 
		Block.m_vector2[5].x + 1, Block.m_vector2[5].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	Block.m_vector2[0].x += 1;
	Block.m_vector2[1].x += 1;
	Block.m_vector2[2].x += 1;
	Block.m_vector2[3].x += 1;
	Block.m_vector2[4].x += 1;
	Block.m_vector2[5].x += 1;

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
	Block.m_vector2[4].y += 1;
	Block.m_vector2[5].y += 1;
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
 	this->m_type = static_cast<Type>(rand() % 3);
	this->m_state = first;
	this->m_vector2[0].y = 1;
	this->m_vector2[0].x = (WIDTH - 1) / 2;
	handleByType(playField, *this);
}