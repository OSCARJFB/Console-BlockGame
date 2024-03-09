/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once 

#include <iostream>
#include <Windows.h>

class Console
{
public:
	Console(bool bToogleMode);
	~Console();

public:
	void ClearScreen() const;
	char ReadKey();
	void SetConsoleColor(int nColor);

public:	
	template <typename T>
	void Print(T tOutPut, short nX, short nY)
	{
		DWORD lpNumberofCharsWritten = 0;
		SetConsoleCursorPosition(m_hOutput, COORD{ nX, nY });
		std::cout << tOutPut;
	}

private: 
	void SetHandlers();
	void SetMode(bool bToogleMode);
	void SetBufferInfo();

private:
	DWORD m_dMode = 0;
	HANDLE m_hInput = nullptr;
	HANDLE m_hOutput = nullptr;
	CONSOLE_SCREEN_BUFFER_INFO csbInfostdin;
	CONSOLE_SCREEN_BUFFER_INFO csbInfostdout;
	WORD wBaseColor = 0;
};
