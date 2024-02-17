/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

class Properties
{
public:
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

public:
	struct Vector2
	{
		int x, y;
	};

public:
	Type m_type;
	State m_state;
	Vector2 m_vector2[4];
};