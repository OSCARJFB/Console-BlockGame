#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "Keys.h"

enum Type
{
	straight,
	square,
	tshape,
	lshape,
	skew
};

enum State
{
	first,
	second,
	third,
	fourth
};

typedef struct Vector2
{
	unsigned int x, y;
} Vector2;

typedef struct Tetromino
{
	Vector2 vector2[4];
	unsigned int type;
	unsigned int state;
} Tetromino;

Tetromino spawn(void);
void reverseState(Tetromino* tetromino);
bool rotate(Tetromino* tetromino, char c);

#endif
