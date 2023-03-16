#ifndef FRUIT_H
#define FRUIT_H

class board;
class Sprite;

class Fruit
{
public:
	Fruit();
	~Fruit();

	void set_fruit_position(board& b_obj);
	void print_fruit();

	char get_fruit();
	bool get_fruitEaten();
	void set_fruitEaten(bool tmp);

	int randNumber(int t_num);

private:
	char m_fruit;
	bool m_fruitEaten;
	int m_fposX, m_fposY;
};
#endif
