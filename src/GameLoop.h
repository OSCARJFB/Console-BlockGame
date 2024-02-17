#pragma once

#include <cstdio>
#include <ctime>
#include "Console/Console.h"
#include "Tetromino/Tetromino.h"
#include "PlayField/playField.h"

#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

#define TICK_FRAME(x)      \
if(!x)                     \
{				           \
	continue;			   \
}						   \

void run();
