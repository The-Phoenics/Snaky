#include "./headers/sprite.h"
#include <iostream>
#include "ctype.h"
#include <Windows.h>

// initializing the sprite(X) at provided positions(posX, posY)
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

void sprite::keyboard_input()
{
	if (GetAsyncKeyState(0x41))
	{
		m_keystate = 'A';
	}
	if (GetAsyncKeyState(0x57))
	{
		m_keystate = 'W';
	}
	if (GetAsyncKeyState(0x53))
	{
		m_keystate = 'S';
	}
	if (GetAsyncKeyState(0x44))
	{
		m_keystate = 'D';
	}
}

// movement is done by updating the board
int sprite::sprite_movement(board& obj)
{

	if (m_keystate == 'W')
	{

		if (obj.get_char_at_board(posx - 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx - 1, posy, Player);
			update_sprite_position(posx - 1, posy);
		}
		else {
			return 1;
		}
	}

	else if (m_keystate == 'A')
	{
		if (obj.get_char_at_board(posx, posy - 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx, posy - 1, Player);
			update_sprite_position(posx, posy - 1);
		}
		else {
			return 1;
		}
	}

	else if (m_keystate == 'S')
	{
		if (obj.get_char_at_board(posx + 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx + 1, posy, Player);
			update_sprite_position(posx + 1, posy);
		}
		else {
			return 1;
		}
	}

	else if (m_keystate == 'D')
	{
		if (obj.get_char_at_board(posx, posy + 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');
			obj.set_player_position(posx, posy + 1, Player);
			update_sprite_position(posx, posy + 1);
		}
		else {
			return 1;
		}
	}

	else
	{
		return 0;
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
