#include "Tetromino.h"

static unsigned int spawn(void)
{
	unsigned int base = rand() % (width + 1);
	base += spawn == width ? -1 : 0;
	return base;
}

void setBasePosition(Tetromino* tetromino)
{
	const unsigned int base = spawn();
	
	switch (tetromino->type)
	{
	case STRAIGHT:
		setBaseStraight(tetromino, base);
		break;
	case SQUARE:
		break;
	case TSHAPE:
		break;
	case LSHAPE:
		break;
	case SKEW:
		break;
	}
}