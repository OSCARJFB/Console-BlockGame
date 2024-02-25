/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

class Block;
class BlockTypeOne;
class BlockTypeTwo;
class BlockTypeThree;
class BlockTypeFour;

class BlockProperties
{
public:
	enum Type
	{
		BlockOne,
		BlockTwo,
		BlockThree,
		BlockFour,
		None,
	};

	enum State
	{
		first,
		second,
		third,
		fourth,
	};

public:
	struct Vector2
	{
		int x, y;
	};

public:
	Type m_type;
	State m_state;
	Vector2 m_vector2[6];
};