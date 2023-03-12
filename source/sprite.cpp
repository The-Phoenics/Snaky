#include "./headers/sprite.h"
#include "./headers/board.h"

#include <iostream>
#include <ctype.h>
#include <Windows.h>


// initializing the snake head at provided positions(posX, posY)
Sprite::Sprite(char ch, int posX, int posY, board& obj)
	: Player(ch), posx(posX), posy(posY), m_keystate('L'), m_score(0)
{
	obj.set_player_position(posx, posy, Player);
}


void Sprite::update_sprite_position(int x, int y)
{
	set_posx(x);
	set_posy(y);
}

// keyboard input ( W A S D )
void Sprite::keyboard_input()
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
int Sprite::sprite_movement(board& obj)
{

	if (m_keystate == 'W')
	{

		if (obj.get_char_at_board(posx - 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');

			// update score by 5 when Snake's head hits the fruit
			if (obj.get_char_at_board(posx - 1, posy) == obj.get_fruit())
			{
				update_score();
			}

			obj.set_player_position(posx - 1, posy, Player);
			update_sprite_position(posx - 1, posy);
		}
		else {
			board::move_cursor(0, 25);
			return 1;
		}
	}

	else if (m_keystate == 'A')
	{
		if (obj.get_char_at_board(posx, posy - 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');

			// update score by 5 when Snake's head hits the fruit
			if (obj.get_char_at_board(posx, posy - 1) == obj.get_fruit())
			{
				update_score();
			}

			obj.set_player_position(posx, posy - 1, Player);
			update_sprite_position(posx, posy - 1);
		}
		else {
			board::move_cursor(0, 25);
			return 1;
		}
	}

	else if (m_keystate == 'S')
	{
		if (obj.get_char_at_board(posx + 1, posy) != '#')
		{
			obj.set_player_position(posx, posy, ' ');

			// update score by 5 when Snake's head hits the fruit
			if (obj.get_char_at_board(posx + 1, posy) == obj.get_fruit())
			{
				update_score();
			}

			obj.set_player_position(posx + 1, posy, Player);
			update_sprite_position(posx + 1, posy);
		}
		else {
			board::move_cursor(0, 25);
			return 1;
		}
	}

	else if (m_keystate == 'D')
	{
		if (obj.get_char_at_board(posx, posy + 1) != '#')
		{
			obj.set_player_position(posx, posy, ' ');

			// update score by 5 when Snake's head hits the fruit
			if (obj.get_char_at_board(posx, posy + 1) == obj.get_fruit())
			{
				update_score();
			}
			obj.set_player_position(posx, posy + 1, Player);
			update_sprite_position(posx, posy + 1);
		}
		else {
			board::move_cursor(0, 25);
			return 1;
		}
	}

	else
	{
		return 0;
	}
}

void Sprite::display_score()
{
	board::move_cursor(-20, 1);
	std::cout << "  SCORE : " << m_score;
}

void Sprite::update_score()
{
	m_score += 5;
}

void Sprite::set_player(char ch) { Player = ch; }

void Sprite::set_posx(int px) { posx = px; }

void Sprite::set_posy(int py) { posy = py; }

int Sprite::get_posx() const { return posx; }

int Sprite::get_posy() const { return posy; }

char Sprite::get_keystate() const { return m_keystate; }
