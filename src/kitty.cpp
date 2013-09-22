#ifndef KITTY_CPP
#define KITTY_CPP

#include "animation.cpp"
#include "character.cpp"

int KITTY_W = 7;
int KITTY_H = 5;
Animation KITTY_ANIMATIONS[2];

class Kitty : public Character {
    public:
        Kitty() {
           skin.SetAnimations(KITTY_ANIMATIONS);
           position.w = KITTY_W;
           position.h = KITTY_H;
        }
};

#endif // KITTY_CPP
