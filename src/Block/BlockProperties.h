/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once

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

public:
	struct Vector2
	{
		int x, y;
	};

public:
	Type m_type;
	Vector2 m_vector2[6];
};