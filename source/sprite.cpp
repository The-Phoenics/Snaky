#include "./headers/sprite.h"
#include <iostream>
#include "ctype.h"

sprite::sprite(char ch, int posX, int posY, board& obj) : Player(ch), posx(posX), posy(posY)
{
	obj.set_player_position(posx, posy, Player);
	
}


void sprite::set_player(char ch)
{
	Player = ch;
}

void sprite::update_sprite_position(int x, int y)
{
	set_posx(x);
	set_posy(y);
}


// movement is done by updating the board
void sprite::sprite_movement(board& obj)
{
	char player_movement_input;
	std::cin >> player_movement_input;
	
	char temp = toupper(player_movement_input);


	if (temp == 'W')
	{
		if (obj.get_char_at_board(posx - 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');      
			obj.set_player_position(posx - 1, posy, Player);
			update_sprite_position(posx - 1, posy);
		}
	}

	if (temp == 'A')
	{
		if (obj.get_char_at_board(posx, posy - 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx, posy - 1, Player);
			update_sprite_position(posx, posy - 1);

		}
	}

	if (temp == 'S')
	{
		if (obj.get_char_at_board(posx + 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx + 1, posy, Player);
			update_sprite_position(posx + 1, posy);
		}
	}

	if (temp == 'D')
	{
		if (obj.get_char_at_board(posx, posy + 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx, posy + 1, Player);
			update_sprite_position(posx, posy + 1);
		}
	}
}


bool sprite::wall_collision_detection(char wall_character)
{
	if (wall_character == 'W')
	{
		if (get_posx() - 1 == '#')
		{
			return true;
		}
	}

	if (wall_character == 'A')
	{
		if (get_posy() - 1 == '#')
		{
			return true;
		}
	}

	if (wall_character == 'S')
	{
		if (get_posy() + 1 == '#')
		{
			return true;
		}
	}

	if (wall_character == 'D')
	{
		if (get_posx() + 1 == '#')
		{
			return true;
		}
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
	return posx;
}

int const sprite::get_posy()
{
	return posy;
}
