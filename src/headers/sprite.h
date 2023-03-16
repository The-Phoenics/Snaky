#ifndef SPRITE_H
#define SPRITE_H

class Fruit;
class board;

class Sprite 
{
public:
    Sprite(char ch, int posX, int posY, board& obj);
    ~Sprite() {}

    void keyboard_input();
    void update_sprite_position(int x, int y);
    void set_player(char ch);
    int sprite_movement(board& obj, Fruit& f_obj);

    void set_posx(int px);
    void set_posy(int py);

    int get_posx() const;
    int get_posy() const;
    int get_score() const;
    char get_keystate() const;

    void display_score();
    void update_score();


private:
    int m_score;
    char Player; // O          Snake head
    char m_keystate;
    int posx;    // column
    int posy;    // row
};
#endif
