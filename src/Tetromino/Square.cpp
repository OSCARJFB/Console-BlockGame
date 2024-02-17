/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#include "Tetromino.h"

void Tetromino::spawnSquare(Tetromino& tetromino)
{
	int x = tetromino.m_vector2[0].x, y = tetromino.m_vector2[0].y;
	tetromino.m_vector2[1].x = x + 1;
	tetromino.m_vector2[1].y = y;
	tetromino.m_vector2[2].x = x;
	tetromino.m_vector2[2].y = y + 1;
	tetromino.m_vector2[3].x = x + 1;
	tetromino.m_vector2[3].y = y + 1;
	tetromino.m_state = second;
}

void Tetromino::squareRotation(Tetromino& tetromino)
{
	if (tetromino.m_state == first)
	{
		spawnSquare(tetromino);
	}
}