#include "./headers/board.h"
#include <iostream>


board::board(int r, int c) : row(r), column(c)  
{
	initialize_field();
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
