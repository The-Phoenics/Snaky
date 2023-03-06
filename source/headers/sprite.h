#ifndef SPRITE_H
#define SPRITE_H

class board;

class Sprite 
{
public:
    Sprite(char ch, int posX, int posY, board& obj);
    ~Sprite() {}

    void keyboard_input();
    void update_sprite_position(int x, int y);
    void set_player(char ch);
    int sprite_movement(board& obj);

    void set_posx(int px);
    void set_posy(int py);

    int get_posx() const;
    int get_posy() const;
    char get_keystate() const;


private:
    char Player; // O          Snake head
    char m_keystate;
    int posx;    // column
    int posy;    // row
};
#endif
