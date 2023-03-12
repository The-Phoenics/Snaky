#ifndef BOARD_H
#define BOARD_H

class Sprite;

class board
{
public:
	board(int r, int c);
	~board() {}

	void const print_field();

	char get_char_at_board(int x, int y);
	void set_player_position(int x, int y, char player);
	void set_fruit_position(int fruitX, int fruitY);

	void update_buffer();

	void render(Sprite& sprite);
	static void move_cursor(int t_x, int t_y);

	char get_fruit();

private:
	void initialize_field();

private :

	char m_fruit;
	int row, column;
	char play_field[25][50];
	char m_Buffer[25][50];     // This is previous buffer or pevious state of the board array.
							   //  It stores the data of the previous frame of the game.
};
#endif