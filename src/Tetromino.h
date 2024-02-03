#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Keys.h"

#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

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
	fourth,
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
bool direction(const Tetromino* tetromino, const char c);
bool rotate(Tetromino* tetromino, char c);
void lockToPlayfied(char playField[HEIGHT][WIDTH], const Tetromino* tetromino);
void gravity(Tetromino* tetromino);

#endif
