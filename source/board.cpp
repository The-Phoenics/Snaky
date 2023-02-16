#include "./headers/board.h"
#include <iostream>
#include <Windows.h>

void board::move_cursor(int t_x, int t_y)
{
	COORD COORDINATE;
	COORDINATE.X = t_x + 25;
	COORDINATE.Y = t_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORDINATE);
}

board::board(int r, int c) : row(r), column(c)  
{
	initialize_field();
}

// copy the play_field into m_Buffer
void board::copy_into_buffer()
{
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 50; j++)
		{
			m_Buffer[i][j] = play_field[i][j];
		}
}

// compare both buffers and move the cursor
void board::screen_manager()
{
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 50; j++)
		{
			if (m_Buffer[i][j] == play_field[i][j]) { continue; }
			
			move_cursor(j, i);

			if (play_field[i][j] == '#') { continue; }

			std::cout << play_field[i][j];

			move_cursor(-25, 25);
		}
}


void const board::print_field()
{
	for (int i = 0; i < row; i++)
	{
		// blank spaces on the left side of field
		for (int space = 0; space < column/2; space++)
		{
			std::cout << " ";
		}

		// print field ( board array )
		for (int j = 0; j < column; j++)
		{
			std::cout << play_field[i][j];
		}
		std::cout << std::endl;

		std::cout.flush();
	}
}

void board::initialize_field()
{
	for (int i = 0; i < row; i++)
	{
		// rows between first and last row
		if (i > 0 && i < row - 1)
		{
			play_field[i][0] = '#';

			for (int m = 1; m <= column - 2; m++)
			{
				play_field[i][m] = ' ';
			}
			play_field[i][column - 1] = '#';
		}

		else
		{
			for (int j = 0; j < column; j++)
			{
				play_field[i][j] = '#';
			}
		}
	}
}

void board::set_player_position(int x, int y, char player)
{
	play_field[x][y] = player;
}

char board::get_char_at_board(int x, int y)
{
	return play_field[x][y];
}

void board::Update_buffer()
{
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 50; j++)
		{
			memset(m_Buffer, play_field[i][j], 1);
		}
}