/*
   	Writen by: Oscar Bergström
	https://github.com/OSCARJFB

	MIT License
	Copyright (c) 2024 Oscar Bergström
*/

#include "Console.h"

#ifdef _WIN32

Console::Console()
{
	if ((m_hInput = GetStdHandle(STD_INPUT_HANDLE)) == INVALID_HANDLE_VALUE)
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get current handle.", dError);
		std::exit(dError);
	}

	if (!GetConsoleMode(m_hInput, &m_dMode))
	{
		DWORD dError = GetLastError();
		std::printf("Error %d while trying to get the current console mode.", dError);
		std::exit(dError);
	}
	SetConsoleMode(m_hInput, m_dMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
}

Console::~Console()
{
	SetConsoleMode(m_hInput, m_dMode);
#ifdef _DEBUG
	printf("Terminal was restored successfully");
#endif
}

char Console::kbhit()
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

void Console::clearScreen(void) const 
{
	std::system("cls");
}

#elif __linux__

Console::Console()
{
	if(tcgetattr(STDIN_FILENO, &m_original_term) == -1)
	{
		std::perror("tcgetattr");
		std::exit(-1);
	}

	m_raw_term = m_original_term;
	m_raw_term.c_lflag &= ~(ICANON | ECHO);

	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &m_raw_term) == -1)
	{
		std::perror("tcsetattr");
		std::exit(-1);
	}
}

Console::~Console()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &m_original_term);
#ifdef _DEBUG
	printf("Terminal was restored successfully");
#endif
}

char Console::kbhit()
{
	long bytes = 0;
	char cr = 0;
	ioctl(STDIN_FILENO, FIONREAD, &bytes);
	if (bytes > 0)
	{
		read(STDIN_FILENO, &cr, sizeof(char));
	}
	std::fflush(stdout);
	return cr;
}

void Console::clearScreen()
{
	std::system("clear");
}

#endif





















