#pragma once
#include <stdlib.h>

class board
{
public:
	board(int r, int c);
	void const print_field();
	void set_player_position(int x, int y, char player);

private:
	void initialize_field();

protected:
	

private :
	int row, column;
	char play_field[25][50];   // TODO : Fix this, place this inside the constructor and allocate this on heap

};