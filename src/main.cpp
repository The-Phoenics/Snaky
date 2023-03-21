#include <iostream>
#include <Windows.h>

#include "./headers/board.h"
#include "./headers/snake.h"
#include "./headers/fruit.h"
#include "./headers/console.h"


int main()
{
	console::ShowConsoleCursor(false);

	Board board = Board();
	Snake snake = Snake(board);
	Fruit fruit = Fruit();

	while (true)
	{
		if (fruit.getFruitEaten() == true)
		{
			fruit.setFruitPosition(board);
			fruit.printFruit();
		}

		snake.keyboardInput();
		if (snake.snakeMovement(board, fruit) == 1)
			break;

		board.renderSnake(snake);
		board.updatePrevBuffer();

		snake.displayScore();
	}
	std::cout << "\nYOU LOST\n";
}