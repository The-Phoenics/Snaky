#include "./headers/snake.h"
#include "./headers/board.h"
#include "./headers/fruit.h"
#include "./headers/console.h"

#include <iostream>
#include <ctype.h>
#include <Windows.h>

#define W_KEY_CODE 0x57  // Up
#define A_KEY_CODE 0x41  // Left
#define S_KEY_CODE 0x53  // Down
#define D_KEY_CODE 0x44  // Right

Snake::Snake()
{
}

// Initializing the snake head on board at posx and posy
Snake::Snake(Board& obj)
	: m_snakehead('O'), posx(ROW / 2), posy(COLUMN / 2),
	  m_snakeDirection('0'), m_score(0), m_length(1)
{
	obj.updateCharAtBoard(posx, posy, m_snakehead);
}


void Snake::updateSnakePosition(int x, int y)
{
	setPosx(x);
	setPosy(y);
}

void Snake::growSnake()
{
	setLength(getLength() + 1);
}

// Keyboard input for snake movement
void Snake::keyboardInput()
{
	if (GetAsyncKeyState(W_KEY_CODE))
	{
		m_snakeDirection = 'W';
	}
	if (GetAsyncKeyState(A_KEY_CODE))
	{
		m_snakeDirection = 'A';
	}
	if (GetAsyncKeyState(S_KEY_CODE))
	{
		m_snakeDirection = 'S';
	}
	if (GetAsyncKeyState(D_KEY_CODE))
	{
		m_snakeDirection = 'D';
	}
}

//////////////////////////
void Snake::printSnakeBody(Board& bobj, Fruit& fobj)
{
	// snake's length
	int len = getLength();

	int x = getPosx();
	int y = getPosy() + 1;

	/*
	for (int i = 0; i < len; i++)
	{	
		console::moveConsoleCursor(x, y);
		std::cout << "x";
	}
	*/

}

// Snake movement, by updating the Board
int Snake::snakeMovement(Board& obj, Fruit& f_obj)
{

	if (m_snakeDirection == 'W')
	{
		if (obj.getCharAtBoard(posx - 1, posy) != '#')
		{
			obj.updateCharAtBoard(posx, posy, ' ');
			////////////////
			printSnakeBody(obj, f_obj);

			// update score by 5 when Snake's eats the fruit
			if (obj.getCharAtBoard(posx - 1, posy) == f_obj.getFruit())
			{
				updateScore();
				growSnake(); ////////////////
				f_obj.setFruitEaten(true);
			}


			obj.updateCharAtBoard(posx - 1, posy, m_snakehead);
			updateSnakePosition(posx - 1, posy);
		}
		else {
			console::moveConsoleCursor(0, 25);
			return 1;
		}
	}

	else if (m_snakeDirection == 'A')
	{
		if (obj.getCharAtBoard(posx, posy - 1) != '#')
		{
			obj.updateCharAtBoard(posx, posy, ' ');

			// update score by 5 when Snake's eats the fruit
			if (obj.getCharAtBoard(posx, posy - 1) == f_obj.getFruit())
			{
				updateScore();
				f_obj.setFruitEaten(true);
			}

			obj.updateCharAtBoard(posx, posy - 1, m_snakehead);
			updateSnakePosition(posx, posy - 1);
		}
		else {
			console::moveConsoleCursor(0, 25);
			return 1;
		}
	}

	else if (m_snakeDirection == 'S')
	{
		if (obj.getCharAtBoard(posx + 1, posy) != '#')
		{
			obj.updateCharAtBoard(posx, posy, ' ');

			// update score by 5 when Snake's eats the fruit
			if (obj.getCharAtBoard(posx + 1, posy) == f_obj.getFruit())
			{
				updateScore();
				f_obj.setFruitEaten(true);
			}

			obj.updateCharAtBoard(posx + 1, posy, m_snakehead);
			updateSnakePosition(posx + 1, posy);
		}
		else {
			console::moveConsoleCursor(0, 25);
			return 1;
		}
	}

	else if (m_snakeDirection == 'D')
	{
		if (obj.getCharAtBoard(posx, posy + 1) != '#')
		{
			obj.updateCharAtBoard(posx, posy, ' ');

			// update score by 5 when Snake's eats the fruit
			if (obj.getCharAtBoard(posx, posy + 1) == f_obj.getFruit())
			{
				updateScore();
				f_obj.setFruitEaten(true);
			}
			obj.updateCharAtBoard(posx, posy + 1, m_snakehead);
			updateSnakePosition(posx, posy + 1);
		}
		else {
			console::moveConsoleCursor(0, 25);
			return 1;
		}
	}

	else
	{
		return 0;
	}
}

void Snake::displayScore()
{
	console::moveConsoleCursor(-20, 1);
	std::cout << "  SCORE : " << m_score;
}

// Increase score by 5 on Snake eating fruit
void Snake::updateScore()
{
	m_score += 5;
}

// Setters
void Snake::setSnakeHead (char ch) { m_snakehead = ch; }

void Snake::setPosx      (int px)  { posx = px; }

void Snake::setPosy      (int py)  { posy = py; }

void Snake::setLength    (int len) { m_length = len; }


// Getters
int Snake::getPosx()      const	{ return posx; }

int Snake::getPosy()      const { return posy; }

int Snake::getLength()    const	{ return m_length; }

int Snake::getScore()     const	{ return m_score; }

char Snake::getSnakeDirection() const { return m_snakeDirection; }
