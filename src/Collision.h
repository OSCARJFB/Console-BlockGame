#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>
#include "Tetromino.h"
#include "Keys.h"

#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

bool isBottomCollision(const char playField[HEIGHT][WIDTH], const Tetromino* tetromino);
void handleRotationCollision(const char playField[HEIGHT][WIDTH], const Tetromino* tetromino);

#endif