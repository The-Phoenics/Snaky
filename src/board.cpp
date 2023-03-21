#include <iostream>
#include <random>
#include <time.h>
#include <Windows.h>;

#include "./headers/board.h"
#include "./headers/snake.h"
#include "./headers/fruit.h"
#include "./headers/console.h"

Board::Board()
{
	initializeField();
	updatePrevBuffer();
	printBoard();
}

// copy the m_board into m_prevBoardState
void Board::updatePrevBuffer()
{
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 50; j++)
		{
			m_prevBoardState[i][j] = m_board[i][j];
		}
}

// compare both buffers and move the cursor
void Board::renderSnake(Snake& snakeObj)
{
	// Increase game speed as the score increases
	unsigned int GAME_PACE = 100 - ((snakeObj.getScore() / 80) * 5);

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 50; j++)
		{
			if (m_prevBoardState[i][j] == m_board[i][j]) { continue; }

			if (m_board[i][j] == '#') { continue; }
			if (m_board[i][j] == 'F') { continue; }
			//if (m_board[i][j] == 'x') { continue; }     /////////////


			if (snakeObj.getSnakeDirection() == 'W')
			{
				console::moveConsoleCursor(j, i);
				std::cout << " ";
			}

			if (snakeObj.getSnakeDirection() == 'A')
			{
				console::moveConsoleCursor(j + 1, i);
				std::cout << " ";
			}

			console::moveConsoleCursor(j, i);

			Sleep(GAME_PACE);
			std::cout << m_board[i][j];

		}
}


void const Board::printBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		// blank spaces on the left side of field
		for (int space = 0; space < COLUMN/2; space++)
		{
			std::cout << " ";
		}

		// print field ( Board array )
		for (int j = 0; j < COLUMN; j++)
		{
			std::cout << m_board[i][j];
		}
		std::cout << std::endl;

		std::cout.flush();
	}
}

void Board::initializeField()
{
	for (int i = 0; i < ROW; i++)
	{
		// ROWs between first and last ROW
		if (i > 0 && i < ROW - 1)
		{
			m_board[i][0] = '#';

			for (int m = 1; m <= COLUMN - 2; m++)
			{
				m_board[i][m] = ' ';
			}
			m_board[i][COLUMN - 1] = '#';
		}

		else
		{
			for (int j = 0; j < COLUMN; j++)
			{
				m_board[i][j] = '#';
			}
		}
	}
}


char Board::getCharAtBoard(int x, int y)
{
	return m_board[x][y];
}

void Board::updateCharAtBoard(int x, int y, char ch)
{
	m_board[x][y] = ch;
}
