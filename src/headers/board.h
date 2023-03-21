#ifndef BOARD_H
#define BOARD_H

#define ROW				  25
#define COLUMN			  50

class Snake;
class Fruit;


class Board
{
public:
	Board();
	~Board() {}

	void initializeField();
	void const printBoard();

	char getCharAtBoard(int x, int y);
	void updateCharAtBoard(int x, int y, char ch);

	void updatePrevBuffer();
	void renderSnake(Snake& snakeObj);       // move to Snake class

private:

	char m_board[ROW][COLUMN];
	char m_prevBoardState[25][50];
};
#endif