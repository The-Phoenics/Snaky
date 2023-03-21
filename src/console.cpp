#include "./headers/console.h"
#define BOARD_LEFT_MARGIN 25

void console::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void console::moveConsoleCursor(int x, int y)
{
	COORD coordinate;
	coordinate.X = x + BOARD_LEFT_MARGIN;
	coordinate.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}