/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "Tetromino.h"

void Tetromino::handleByType(const char playField[HEIGHT][WIDTH], Tetromino& tetromino)
{
	switch (tetromino.m_type)
	{
	case straight:
		straightRotation(playField, tetromino);
		break;
	case square:
		squareRotation(tetromino);
		break;
	case tshape:
		// tshapeRotation(playField, tetromino);
		break;
	case lshape:
		// lshapeRotation(playField, tetromino);
		break;
	case skew:
		// skewRotation(playField, tetromino);
		break;
	}
}

void Tetromino::lockToPlayfied(char playField[HEIGHT][WIDTH], const Tetromino& tetromino)
{
	playField[tetromino.m_vector2[0].y][tetromino.m_vector2[0].x] = 'X';
	playField[tetromino.m_vector2[1].y][tetromino.m_vector2[1].x] = 'X';
	playField[tetromino.m_vector2[2].y][tetromino.m_vector2[2].x] = 'X';
	playField[tetromino.m_vector2[3].y][tetromino.m_vector2[3].x] = 'X';
}

bool Tetromino::isBottomCollision(char playField[HEIGHT][WIDTH], const Tetromino& tetromino)
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			for (int n = 0; n < 4; ++n)
			{
				if (tetromino.m_vector2[n].y == i && tetromino.m_vector2[n].x == j)
				{
					if (playField[i + 1][j] == 'X' || playField[i + 1][j] == '=')
					{
						lockToPlayfied(playField, tetromino);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Tetromino::isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[4])
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

bool Tetromino::left(const char playField[HEIGHT][WIDTH], Tetromino& tetromino)
{
	bool isInPlayField = true;
	isInPlayField = (tetromino.m_vector2[0].x > 1) && isInPlayField;
	isInPlayField = (tetromino.m_vector2[1].x > 1) && isInPlayField;
	isInPlayField = (tetromino.m_vector2[2].x > 1) && isInPlayField;
	isInPlayField = (tetromino.m_vector2[3].x > 1) && isInPlayField;

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[4] = {
		tetromino.m_vector2[0].x - 1, tetromino.m_vector2[0].y,
		tetromino.m_vector2[1].x - 1, tetromino.m_vector2[1].y,
		tetromino.m_vector2[2].x - 1, tetromino.m_vector2[2].y,
		tetromino.m_vector2[3].x - 1, tetromino.m_vector2[3].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	tetromino.m_vector2[0].x -= 1;
	tetromino.m_vector2[1].x -= 1;
	tetromino.m_vector2[2].x -= 1;
	tetromino.m_vector2[3].x -= 1;

	return true;
}

bool Tetromino::right(const char playField[HEIGHT][WIDTH], Tetromino& tetromino)
{
	bool isInPlayField = true;
	isInPlayField = (tetromino.m_vector2[0].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (tetromino.m_vector2[1].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (tetromino.m_vector2[2].x < WIDTH - 1) && isInPlayField;
	isInPlayField = (tetromino.m_vector2[3].x < WIDTH - 1) && isInPlayField;

	if (!isInPlayField)
	{
		return false;
	}

	Vector2 vec[4] = {
		tetromino.m_vector2[0].x + 1, tetromino.m_vector2[0].y,
		tetromino.m_vector2[1].x + 1, tetromino.m_vector2[1].y,
		tetromino.m_vector2[2].x + 1, tetromino.m_vector2[2].y,
		tetromino.m_vector2[3].x + 1, tetromino.m_vector2[3].y,
	};

	if (isCollision(playField, vec))
	{
		return false;
	}

	tetromino.m_vector2[0].x += 1;
	tetromino.m_vector2[1].x += 1;
	tetromino.m_vector2[2].x += 1;
	tetromino.m_vector2[3].x += 1;

	return true;
}

bool Tetromino::direction(const char playField[HEIGHT][WIDTH], const char c, Tetromino& tetromino)
{
	bool changeDirection = false;
	switch (c)
	{
	case LEFT_KEY:
		changeDirection = left(playField, tetromino);
		break;
	case RIGHT_KEY:
		changeDirection = right(playField, tetromino);
		break;
	}
	return changeDirection;
}

void Tetromino::gravity(Tetromino& tetromino)
{
	tetromino.m_vector2[0].y += 1;
	tetromino.m_vector2[1].y += 1;
	tetromino.m_vector2[2].y += 1;
	tetromino.m_vector2[3].y += 1;
}

bool Tetromino::rotate(Tetromino& tetromino, const char playField[HEIGHT][WIDTH], const char c)
{
 	if (c != SPACE_KEY)
	{
		return false;
	}
	handleByType(playField, tetromino);
	return true;
}

void Tetromino::spawn(const char playField[HEIGHT][WIDTH])
{
	this->m_type = static_cast<Type>(rand() % 2);
	this->m_state = first;
	
	switch (this->m_type)
	{
	case straight:
		this->m_vector2[1].y = 1;
		this->m_vector2[1].x = WIDTH / 2;
		break;
	case square:
		this->m_vector2[0].y = 1;
		this->m_vector2[0].x = WIDTH / 2;
		break;
	}

	handleByType(playField, *this);
}