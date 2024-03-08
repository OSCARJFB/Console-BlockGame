/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once 

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <Windows.h>

class Console
{
public:
	Console();
	~Console();

public:
	void clearScreen() const;
	char kbhit();

public:	
	template <typename T>
	void print(T type, short x, short y)
	{
		DWORD lpNumberofCharsWritten = 0;
		SetConsoleCursorPosition(m_hOutput, COORD{ x, y });
		std::cout << type;
	}

private:
	DWORD m_dMode = 0;
	HANDLE m_hInput = nullptr;
	HANDLE m_hOutput = nullptr;
};
