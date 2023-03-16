#include <iostream>
#include <Windows.h>

#include "./headers/board.h"
#include "./headers/sprite.h"
#include "./headers/fruit.h"

void ShowConsoleCursor(bool showFlag);

int main()
{
	ShowConsoleCursor(false);

	board board(25, 50);
	Sprite sprite = Sprite('O', 20, 15, board);
	Fruit fruit = Fruit();

	//board.print_field();

	while (true)
	{
		if (fruit.get_fruitEaten() == true)
		{
			fruit.set_fruit_position(board);
			fruit.print_fruit();
		}

		sprite.display_score();

		sprite.keyboard_input();
		if (sprite.sprite_movement(board, fruit) == 1) {
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