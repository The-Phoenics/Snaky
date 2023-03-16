#pragma once
#include <iostream>
#include <random>
#include <time.h>

#include "./headers/sprite.h"
#include "./headers/board.h"
#include "./headers/fruit.h"


// default constructor
Fruit::Fruit()
	: m_fruit('F'), m_fruitEaten(true), m_fposX(-1), m_fposY(-1)

{

}

// destructor
Fruit::~Fruit()
{
}

void Fruit::set_fruitEaten(bool tmp)
{
	m_fruitEaten = tmp;
}

bool Fruit::get_fruitEaten()
{
	return m_fruitEaten;
}

char Fruit::get_fruit() { return m_fruit; }

void Fruit::print_fruit()
{
	board::move_cursor(m_fposY, m_fposX);
	std::cout << 'F';
}

int Fruit::randNumber(int t_num)
{
	static std::default_random_engine rEngine(time(NULL));

	// generate a random int in range 1 to t_num
	std::uniform_int_distribution<int> rInt(1, t_num);

	return rInt(rEngine);
}

void Fruit::set_fruit_position(board& b_obj)
{
	REPEAT_GOTO:
	m_fposX = randNumber(22);
	m_fposY = randNumber(47);

	if (b_obj.get_char_at_board(m_fposX, m_fposY) == 'O')
	{
		goto REPEAT_GOTO;
	}
	b_obj.update_char_at_play_field(m_fposX, m_fposY, m_fruit);

	set_fruitEaten(false);
}
