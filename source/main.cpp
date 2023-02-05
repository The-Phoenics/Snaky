#include <iostream>
#include "./headers/board.h"
#include "./headers/sprite.h"

int main()
{
	board b1(25, 50);
	sprite s1('X', 20, 15, b1);

	while (true)
	{
		system("cls");
		b1.print_field();
		s1.sprite_movement(b1);
	}

}


void sprite_spawn(board& obj)
{
	
}