/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

#include <cstdlib>
#include <ctime>
#include "Properties.h"
#include "../Keys.h"

#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

class Tetromino : public Properties
{
public:
	Tetromino(const char playField[HEIGHT][WIDTH])
	{
		spawn(playField);
	};
	~Tetromino() = default;

public:
	void spawn(const char playField[HEIGHT][WIDTH]);
	void gravity(Tetromino& tetromino);
	bool direction(const char playField[HEIGHT][WIDTH], const char c, Tetromino& tetromino);
	bool rotate(Tetromino& tetromino, const char playField[HEIGHT][WIDTH], char c);
	bool isBottomCollision(char playField[HEIGHT][WIDTH], const Tetromino& tetromino);
	bool isCollision(const char playField[HEIGHT][WIDTH], const Vector2 vec[4]);

private:
	void handleByType(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	void straightRotation(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	void set_1_straight(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	void set_2_straight(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	void set_3_straight(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	void set_4_straight(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	void squareRotation(Tetromino& tetromino);
	void spawnSquare(Tetromino& tetromino);
	void lockToPlayfied(char playField[HEIGHT][WIDTH], const Tetromino& tetromino);
	bool left(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
	bool right(const char playField[HEIGHT][WIDTH], Tetromino& tetromino);
};