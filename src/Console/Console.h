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

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#endif

class Console
{
public:
	Console();
	~Console();

public:
	void clearScreen() const;
	char kbhit();
	template <typename T>
	void print(T type, short x, short y) const;

private:

#ifdef _WIN32
	DWORD m_dMode = 0;
	HANDLE m_hInput = nullptr;
	HANDLE m_hOutput = nullptr;
#elif __linux__
	struct termios m_original_term, m_raw_term;
#endif

};
