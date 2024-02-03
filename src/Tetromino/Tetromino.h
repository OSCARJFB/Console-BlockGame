#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../Keys.h"


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
bool direction(Tetromino* tetromino, const char c);
bool rotate(Tetromino* tetromino, const char playField[HEIGHT][WIDTH], char c);
void gravity(Tetromino* tetromino);
bool isBottomCollision(char playField[HEIGHT][WIDTH], Tetromino* tetromino);
void handleRotationCollision(const char playField[HEIGHT][WIDTH], Tetromino* tetromino);

#endif
