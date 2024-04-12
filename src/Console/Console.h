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
	Console(BOOL bToogleMode = true);
	~Console();

public:
	void ClearScreen() const;
	WORD ReadArrowKey();
	CHAR ReadKey();
	void SetColor(WORD wColor);
	COORD GetCursorCoordinates();
	void SetCursorCoordinates(SHORT nX, SHORT nY);

public:
	template <typename T>
	void Print(T tOutPut, SHORT nX, SHORT nY)
	{
		DWORD lpNumberofCharsWritten = 0;
		SetConsoleCursorPosition(m_hOutput, COORD{ nX, nY });
		std::cout << tOutPut;
	}

	template <typename T>
	void Print(T tOutPut, SHORT nX, SHORT nY, WORD wColor)
	{
		SetColor(wColor);
		DWORD lpNumberofCharsWritten = 0;
		SetConsoleCursorPosition(m_hOutput, COORD{ nX, nY });
		std::cout << tOutPut;
		SetColor(m_wBaseColor);
	}

public:
	enum class Vk : WORD
	{
		left = 1,
		up,
		right,
		down,
	};

private:
	void SetHandlers();
	void SetBufferInfo();
	void SetMode(BOOL bToogleMode);

private:
	DWORD m_dMode = 0;
	HANDLE m_hInput = nullptr;
	HANDLE m_hOutput = nullptr;
	CONSOLE_SCREEN_BUFFER_INFO m_csbInfo;
	WORD m_wBaseColor = 0;
};
