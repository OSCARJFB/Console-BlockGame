/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once 

#include <cstdlib>
#include <cstdio>

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

private:

#ifdef _WIN32
	DWORD m_dMode = 0;
	HANDLE m_hInput = nullptr;
#elif __linux__
	struct termios m_original_term, m_raw_term;
#endif

};
