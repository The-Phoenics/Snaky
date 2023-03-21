#pragma once
#include <Windows.h>

namespace console
{
	void ShowConsoleCursor(bool showFlag);
	void moveConsoleCursor(int x, int y);
}