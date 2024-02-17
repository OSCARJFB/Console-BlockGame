/*
		Writen by: Oscar Bergstr�m
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergstr�m
*/

#pragma once

#include <iostream>
#include "../Console/Console.h"
#include "../Tetromino/Tetromino.h"

#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

void initPlayField(char playField[HEIGHT][WIDTH]);
void printPlayField(const char playField[HEIGHT][WIDTH], const Tetromino& tetromino, const Console& console);
void scoreCheck(char playField[HEIGHT][WIDTH]);