#ifndef FRUIT_H
#define FRUIT_H

class Board;
class Snake;

class Fruit
{
public:
	Fruit();
	~Fruit();

	char  getFruit() const;
	bool  getFruitEaten() const;

	int   getfPosX() const;
	int   getfPosY() const;
	
	void  setfPosX(int x);
	void  setfPosY(int y);

	void  setFruitEaten(bool tmp);
	void  setFruitPosition(Board& b_obj);

	void  printFruit();
	int   randNumber(int t_num);

private:
	char m_fruit;
	int  m_fposX, m_fposY;
	bool m_fruitEaten;
};
#endif
