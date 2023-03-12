#include <iostream>
#include <Windows.h>

#include "./headers/board.h"
#include "./headers/sprite.h"

void ShowConsoleCursor(bool showFlag);

int main()
{
	ShowConsoleCursor(false);
	board board(25, 50);
	Sprite sprite('O', 20, 15, board);  // set position of sprite at 20, 15

	board.print_field();

	while (true)
	{
		board.set_fruit_position(12, 26);       ////// new
		sprite.display_score();                 ////// addition today

		sprite.keyboard_input();
		if (sprite.sprite_movement(board) == 1) {
			break;
		}

		board.render(sprite);
		board.update_buffer();
	}
	std::cout << "\nYOU LOST\n";
}


void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}