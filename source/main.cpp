#include <iostream>
#include <Windows.h>
#include "./headers/board.h"
#include "./headers/sprite.h"


int main()
{
	board board(25, 50);
	sprite sprite('X', 20, 15, board);  // set position of sprite at 20, 15

	board.print_field();

	while (true)
	{
		sprite.keyboard_input();
		if (sprite.sprite_movement(board) == 1) {
			break;
		}

		board.render();
		board.update();
	}
	std::cout << "\nYOU LOST\n";
}
