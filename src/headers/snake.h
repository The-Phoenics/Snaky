#ifndef SNAKE_H
#define SNAKE_H

class Fruit;
class Board;

class Snake
{
public:

    Snake();
    Snake(Board& obj);
    ~Snake() {}

    void keyboardInput();
    void printSnakeBody(Board& bobj, Fruit& fobj);
    void updateSnakePosition(int x, int y);
    int  snakeMovement(Board& obj, Fruit& f_obj);

    void displayScore();
    void updateScore();
    void growSnake();

    // getters
    int  getPosx() const;
    int  getPosy() const;

    int  getScore    () const;
    int  getLength  () const;
    char getSnakeDirection () const;

    // setters
    void setPosx(int px);
    void setPosy(int py);

    void setLength(int len);
    void setSnakeHead(char ch);

private:
    
    int  m_score;
    char m_snakehead;

    int  m_length;

    char m_snakeDirection;
    int  posx, posy;
    int  prevX, prevY;
};
#endif
