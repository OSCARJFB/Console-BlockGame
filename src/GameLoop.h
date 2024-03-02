/*
		Writen by: Oscar Bergstr�m
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergstr�m
*/

#pragma once

#include <cstdio>
#include <ctime>
#include "Console/Console.h"
#include "Block/Block.h"
#include "GameField/GameFieldSize.h"
#include "GameField/GameField.h"

#define TICK_FRAME(x)      \
if(!x)                     \
{				           \
	continue;			   \
}						   \

void run();
