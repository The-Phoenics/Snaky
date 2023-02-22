#include "./headers/sprite.h"
#include <iostream>
#include "ctype.h"
#include <Windows.h>


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
	char temp = '0';
	
	if (GetAsyncKeyState(0x41))
	{
		temp = 'A';
	}
	if (GetAsyncKeyState(0x57))
	{
		temp = 'W';
	}
	if (GetAsyncKeyState(0x53))
	{
		temp = 'S';
	}
	if (GetAsyncKeyState(0x44))
	{
		temp = 'D';
	}

	if (temp == 'W')
	{

		if (obj.get_char_at_board(posx - 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx - 1, posy, Player);
			update_sprite_position(posx - 1, posy);
		}
	}

	else if (temp == 'A')
	{
		if (obj.get_char_at_board(posx, posy - 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx, posy - 1, Player);
			update_sprite_position(posx, posy - 1);
		}
	}

	else if (temp == 'S')
	{
		if (obj.get_char_at_board(posx + 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx + 1, posy, Player);
			update_sprite_position(posx + 1, posy);
		}
	}

	else if (temp == 'D')
	{
		if (obj.get_char_at_board(posx, posy + 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx, posy + 1, Player);
			update_sprite_position(posx, posy + 1);
		}
	}

}


bool sprite::wall_collision_detection(char check_wall_character_variable)
{
	if (check_wall_character_variable == 'W')
	{
		if (get_posx() - 1 == '#')
			return true;			
	}

	if (check_wall_character_variable == 'A')
	{
		if (get_posy() - 1 == '#')
			return true;
	}

	if (check_wall_character_variable == 'S')
	{
		if (get_posy() + 1 == '#')
			return true;
	}

	if (check_wall_character_variable == 'D')
	{
		if (get_posx() + 1 == '#')
			return true;
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
