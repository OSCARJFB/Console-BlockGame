/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

#include <cstdio>
#include <ctime>
#include "Console/Console.h"
#include "Block/Block.h"
#include "gameField/gameFieldSize.h"
#include "gameField/gameField.h"

#define TICK_FRAME(x)      \
if(!x)                     \
{				           \
	continue;			   \
}						   \

void run();
