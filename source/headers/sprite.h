#pragma once
#include "board.h"

class sprite 
{
public:
    sprite(char ch, int posX, int posY, board& obj);

    void keyboard_input();
    void update_sprite_position(int x, int y);
    void set_player(char ch);
    int sprite_movement(board& obj);

    void set_posx(int px);
    void set_posy(int py);

    int const get_posx();
    int const get_posy();


private:
    char Player; // X
    char m_keystate;
    int posx;    // column
    int posy;    // row
};

