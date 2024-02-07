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
  int x, y;
} Vector2;

typedef struct Tetromino
{
	int type, state;
	Vector2 vector2[4];
} Tetromino;

Tetromino spawn(void);
bool direction(Tetromino* tetromino, const char c);
void straightRotation(Tetromino* tetromino);
bool rotate(Tetromino* tetromino, const char playField[HEIGHT][WIDTH], char c);
void gravity(Tetromino* tetromino);
bool isBottomCollision(char playField[HEIGHT][WIDTH], Tetromino* tetromino);

#endif
