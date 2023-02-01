#include "./headers/sprite.h"
#include <iostream>
#include "ctype.h"

sprite::sprite(char ch, int posX, int posY, board& obj) : Player(ch), posx(posX), posy(posY)
{
	obj.set_player_position(posX, posY, Player);
}


void sprite::set_player(char ch)
{
	this->Player = ch;
}


void sprite::sprite_movement(board& obj)
{
	char player_movement_input;
	std::cin >> player_movement_input;
	
	char temp = toupper(player_movement_input);

	if (temp == 'W')
	{
		obj.set_player_position(posx, posy, ' ');
		obj.set_player_position(posx - 1, posy, Player);
	}

	else if (temp == 'A')
	{
		obj.set_player_position(posx, posy, ' ');
		obj.set_player_position(posx , posy - 1, Player);
	}

	else if (temp == 'D')
	{
		obj.set_player_position(posx, posy, ' ');
		obj.set_player_position(posx , posy + 1, Player);
	}

	else if (temp == 'S')
	{
		obj.set_player_position(posx, posy, ' ');
		obj.set_player_position(posx + 1, posy, Player);
	}
}


void sprite::set_posx(int px)
{
	posx = px;
}
void sprite::set_posy(int py)
{
	posy = py;
}

int const sprite::get_posx()
{

}

int const sprite::get_posy()
{

}
