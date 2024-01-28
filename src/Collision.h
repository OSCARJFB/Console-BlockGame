#ifndef COLLISION_H
#define COLLISION_H

#include "Tetromino.h"
#include "Keys.h"

#ifndef HEIGHT
#define HEIGHT 20
#endif

#ifndef WIDTH
#define WIDTH 20
#endif

void handleCollision(char **playField, Tetromino* tetromino);

#endif