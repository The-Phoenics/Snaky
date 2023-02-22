#include <iostream>
#include <ostream>
#include "./headers/board.h"
#include "./headers/sprite.h"
#include <Windows.h>


int main()
{

	board b1(25, 50);
	sprite s1('X', 20, 15, b1);  // put X at 20,15 index

	b1.copy_into_buffer();
	b1.print_field();

	while (true)
	{
		b1.copy_into_buffer();
		s1.sprite_movement(b1);
		b1.screen_manager();
	}
	std::cout << "\nYOU LOST\n";
	std::cin.get();
}
