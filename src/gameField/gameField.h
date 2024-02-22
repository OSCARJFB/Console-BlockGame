/*
		Writen by: Oscar Bergstr�m
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergstr�m
*/

#pragma once

#include <iostream>
#include "gameFieldSize.h"
#include "../Console/Console.h"
#include "../Block/Block.h"

#define BLOCK '#'

void initPlayField(char playField[HEIGHT][WIDTH]);
void printPlayField(char playField[HEIGHT][WIDTH], const Block& Block, const Console& console);
void scoreCheck(char playField[HEIGHT][WIDTH]);