#pragma once
#include <iostream>
#include <random>
#include <time.h>

#include "./headers/snake.h"
#include "./headers/board.h"
#include "./headers/fruit.h"
#include "./headers/console.h"


// default constructor
Fruit::Fruit()
	: m_fruit('F'), m_fruitEaten(true), m_fposX(-1), m_fposY(-1)

{
}

// destructor
Fruit::~Fruit()
{
}


void Fruit::printFruit()
{
	console::moveConsoleCursor(m_fposY, m_fposX);
	std::cout << 'F';
}

int Fruit::randNumber(int t_num)
{
	static std::default_random_engine randomEngine(std::time(NULL));

	// generate a random int from 1 to t_num
	std::uniform_int_distribution<int> randomInt(1, t_num);

	return randomInt(randomEngine);
}


// getters
bool Fruit::getFruitEaten() const { return m_fruitEaten; }

char Fruit::getFruit()      const { return m_fruit; }

int  Fruit::getfPosX()      const { return m_fposX; }

int  Fruit::getfPosY()      const { return m_fposY; }


// setters
void Fruit::setfPosX(int x) { m_fposX = x; }

void Fruit::setfPosY(int y) { m_fposY = y; }

void Fruit::setFruitEaten(bool tmp) { m_fruitEaten = tmp; }

void Fruit::setFruitPosition(Board& b_obj)
{
REPEAT_GOTO:
	m_fposX = randNumber(22);
	m_fposY = randNumber(47);

	if (b_obj.getCharAtBoard(m_fposX, m_fposY) == 'O' || b_obj.getCharAtBoard(m_fposX, m_fposY) == 'x')
	{
		goto REPEAT_GOTO;
	}
	b_obj.updateCharAtBoard(m_fposX, m_fposY, m_fruit);

	setFruitEaten(false);
}