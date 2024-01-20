#ifndef TETROMINO_H
#define TETROMINO_H
#include <stdlib.h>

#define width 10

extern unsigned int _positions[4][4];

enum Type
{
	STRAIGHT,
	SQUARE,
	TSHAPE,
	LSHAPE,
	SKEW
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

#endif
