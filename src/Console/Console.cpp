/*
	Writen by: Oscar Bergstr�m
	https://github.com/OSCARJFB

	MIT License
	Copyright (c) 2024 Oscar Bergstr�m
*/

#include "Console.h"

Console::Console(BOOL bToogleMode)
{
	SetHandlers();
	SetBufferInfo();
	SetMode(bToogleMode);
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
	if ((m_hInput = GetStdHandle(STD_INPUT_HANDLE)) == INVALID_HANDLE_VALUE) {
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get input handle.", dError);
		std::exit(dError);
	}
	if ((m_hOutput = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE) {
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get output handle.", dError);
		std::exit(dError);
	}
}

void Console::SetBufferInfo()
{
	if (!GetConsoleScreenBufferInfo(m_hOutput, &m_csbInfo)) {
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get output buffer info.", dError);
		std::exit(dError);
	}
	m_wBaseColor = m_csbInfo.wAttributes;
}

void Console::SetMode(BOOL bToogleMode)
{
	if (!bToogleMode)
		return;
	if (!GetConsoleMode(m_hInput, &m_dMode)) {
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get the current console mode.", dError);
		std::exit(dError);
	}
	SetConsoleMode(m_hInput, m_dMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
}

void Console::ClearScreen(void) const
{
	std::system("cls");
}

WORD Console::ReadArrowKey()
{
	DWORD dEvents = 0;
	WORD wKeyValue = 0, wKey = 0;
	INPUT_RECORD inputRecord;
	if (PeekConsoleInput(m_hInput, &inputRecord, 1, &dEvents) && dEvents > 0) {
		ReadConsoleInput(m_hInput, &inputRecord, 1, &dEvents);
		if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown)
			wKey = inputRecord.Event.KeyEvent.wVirtualKeyCode;
	}

	switch (wKey)
	{
	case VK_LEFT:
		wKeyValue = static_cast<WORD>(Vk::left);
		break;
	case VK_UP:
		wKeyValue = static_cast<WORD>(Vk::up);
		break;
	case VK_RIGHT:
		wKeyValue = static_cast<WORD>(Vk::right);
		break;
	case VK_DOWN:
		wKeyValue = static_cast<WORD>(Vk::down);
		break;
	default:
		break;
	}
	return wKeyValue;
}

CHAR Console::ReadKey()
{
	CHAR cAsciiKey = '\0';
	DWORD dEvents = 0;
	INPUT_RECORD inputRecord;
	if (PeekConsoleInput(m_hInput, &inputRecord, 1, &dEvents) && dEvents > 0) {
		ReadConsoleInput(m_hInput, &inputRecord, 1, &dEvents);
		if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown)
			cAsciiKey = inputRecord.Event.KeyEvent.uChar.AsciiChar;
	}
	return static_cast<char>(cAsciiKey);
}

void Console::SetColor(WORD wColor)
{
	if (!SetConsoleTextAttribute(m_hOutput, wColor)) {
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to set the console attribute.", dError);
		std::exit(dError);
	}
}

COORD Console::GetCursorCoordinates()
{
	SetBufferInfo();
	return m_csbInfo.dwCursorPosition;
}

void Console::SetCursorCoordinates(SHORT nX, SHORT nY)
{
	SetConsoleCursorPosition(m_hOutput, COORD{ nX, nY });
}