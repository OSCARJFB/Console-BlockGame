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
};

void Block::blockArrayCpy(Vector2 src[6], Vector2 dest[6])
{
	for (int i = 0; i < 6; ++i)
	{
		dest[i].x = src[i].x;
		dest[i].y = src[i].y;
	}
}

void Block::rotateBlock(const char playField[HEIGHT][WIDTH], Block& block)
{
	Vector2 vec[6];
	int y = block.m_vector2[0].y;
	int x = block.m_vector2[0].x;
	int xDiff, yDiff;
	
	blockArrayCpy(block.m_vector2, vec);

	for (int i = 1; i < 6; ++i)
	{
		xDiff = vec[i].x - x;
		yDiff = vec[i].y - y;
		vec[i].y = y + xDiff;
		vec[i].x = x - yDiff;
	}
	
	if (isCollision(playField, vec))
	{
		return;
	}

	blockArrayCpy(vec, block.m_vector2);
}

bool Block::rotate(Block& Block, const char playField[HEIGHT][WIDTH], const char c)
{
	if (c != SPACE_KEY)
	{
		return false;
	}
	rotateBlock(playField, Block);
	return true;
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

bool Block::down(const char playField[HEIGHT][WIDTH], Block& Block)
{
	Vector2 vec[6] = {
		Block.m_vector2[0].y + 1, Block.m_vector2[0].y,
		Block.m_vector2[1].y + 1, Block.m_vector2[1].y,
		Block.m_vector2[2].y + 1, Block.m_vector2[2].y,
		Block.m_vector2[3].y + 1, Block.m_vector2[3].y,
		Block.m_vector2[4].y + 1, Block.m_vector2[4].y,
		Block.m_vector2[5].y + 1, Block.m_vector2[5].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	Block.m_vector2[0].y += 1;
	Block.m_vector2[1].y += 1;
	Block.m_vector2[2].y += 1;
	Block.m_vector2[3].y += 1;
	Block.m_vector2[4].y += 1;
	Block.m_vector2[5].y += 1;
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
	case DOWN_KEY:
		changeDirection = down(playField, Block);
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

void Block::reshuffleSpawn()
{
	int type = static_cast<int>(m_type);
	if (type < Type::BlockFour)
	{
		++type;
		m_type = static_cast<Type>(type);
	}
	else
	{
		m_type = Type::BlockOne;
	}
}

void Block::spawnByType(const char playField[HEIGHT][WIDTH], Block& block)
{
	int x = block.m_vector2[0].x, y = block.m_vector2[0].y;
	switch (block.m_type)
	{
	case Type::BlockOne:
		m_vector2[1].x = x, m_vector2[1].y = y + 1;
		m_vector2[2].x = x + 1, m_vector2[2].y = y + 1;
		m_vector2[3].x = x + 2, m_vector2[3].y = y + 1;
		m_vector2[4].x = x + 3, m_vector2[4].y = y + 1;
		m_vector2[5].x = x + 3, m_vector2[5].y;
		break;
	case Type::BlockTwo:
		m_vector2[1].x = x + 1, m_vector2[1].y = y;
		m_vector2[2].x = x + 2, m_vector2[2].y = y;
		m_vector2[3].x = x + 3, m_vector2[3].y = y;
		m_vector2[4].x = x + 1, m_vector2[4].y = y + 1;
		m_vector2[5].x = x + 2, m_vector2[5].y = y + 1;
		break;
	case Type::BlockThree:
		m_vector2[1].x = x + 1, m_vector2[1].y = y + 1;
		m_vector2[2].x = x + 1, m_vector2[2].y = y;
		m_vector2[3].x = x + 2, m_vector2[3].y = y;
		m_vector2[4].x = x + 3, m_vector2[4].y = y;
		m_vector2[5].x = x + 4, m_vector2[5].y = y;
		break;
	case Type::BlockFour:
		m_vector2[1].x = x + 1, m_vector2[1].y = y;
		m_vector2[1].x = x + 2, m_vector2[1].y = y;
		m_vector2[1].x = x + 3, m_vector2[1].y = y;
		m_vector2[1].x = x + 3, m_vector2[1].y = y + 1;
		m_vector2[1].x = x + 4, m_vector2[1].y = y;
		break;
	}
}

void Block::spawn(const char playField[HEIGHT][WIDTH])
{
	static Type lastType = Type::None;
	static int TypeCount = 0;
 	m_type = static_cast<Type>(rand() % 4);
	
	TypeCount += lastType == m_type ? 1 : 0;
	if (TypeCount == 2)
	{
		reshuffleSpawn();
		TypeCount = 0;
	}
	lastType = m_type;

	m_vector2[0].y = 1;
	m_vector2[0].x = (WIDTH - 1) / 2;
	spawnByType(playField, *this);
}