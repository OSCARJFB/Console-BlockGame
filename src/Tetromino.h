#ifndef TETROMINO_H
#define TETROMINO_H

enum Type
{
	STRAIGHT,
	SQUARE,
	TSHAPE,
	LSHAPE,
	SKEW
};

enum State
{
	FIRST,
	SECOND,
	THIRD,
	FOURTH
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

void rotate(Tetromino* tetromino);

#endif
