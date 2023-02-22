#pragma once
#include <stdlib.h>

class board
{
public:
	board(int r, int c);
	void const print_field();
	void set_player_position(int x, int y, char player);
	char get_char_at_board(int x, int y);

	void Update_buffer();

	void screen_manager();
	void copy_into_buffer();

	void move_cursor(int t_x, int t_y);

private:
	void initialize_field();


private :
	int row, column;
	char play_field[25][50];   // TODO : Fix this, place this inside the constructor and allocate this on heap.

	char m_Buffer[25][50];     // This is old-buffer. It stores the data of the previous frame of the game.

};