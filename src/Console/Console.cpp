/*
   	Writen by: Oscar Bergstr�m
	https://github.com/OSCARJFB

	MIT License
	Copyright (c) 2024 Oscar Bergstr�m
*/

#include "Console.h"

Console::Console(bool bToogleMode)
{
	SetHandlers();
	SetMode(bToogleMode);
	SetBufferInfo();
}

Console::~Console()
{
	SetConsoleMode(m_hInput, m_dMode);
#ifdef _DEBUG
	printf("Terminal was restored successfully");
#endif
}

void Console::SetHandlers()
{
	if ((m_hInput = GetStdHandle(STD_INPUT_HANDLE)) == INVALID_HANDLE_VALUE)
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get input handle.", dError);
		std::exit(dError);
	}

	if ((m_hOutput = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get output handle.", dError);
		std::exit(dError);
	}
}

void Console::SetMode(bool bToogleMode)
{
	if (!bToogleMode)
	{
		return;
	}

	if (!GetConsoleMode(m_hInput, &m_dMode))
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get the current console mode.", dError);
		std::exit(dError);
	}

	SetConsoleMode(m_hInput, m_dMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	if ((m_hOutput = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get output handle.", dError);
		std::exit(dError);
	}
}

void Console::SetBufferInfo()
{
	if ((m_hInput = GetStdHandle(STD_INPUT_HANDLE)) == INVALID_HANDLE_VALUE)
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get input handle.", dError);
		std::exit(dError);
	}

	if ((m_hOutput = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get output handle.", dError);
		std::exit(dError);
	}
}

void Console::ClearScreen(void) const
{
	std::system("cls");
}

char Console::ReadKey()
{
	CHAR cAsciiKey = 0;
	DWORD dEvents = 0;
	INPUT_RECORD inputRecord;

	if (PeekConsoleInput(m_hInput, &inputRecord, 1, &dEvents) && dEvents > 0)
	{
		ReadConsoleInput(m_hInput, &inputRecord, 1, &dEvents);
		if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown)
		{
			cAsciiKey = inputRecord.Event.KeyEvent.uChar.AsciiChar;
		}
	}
	return (char)cAsciiKey;
}

void Console::SetConsoleColor(int nColor)
{
}