#ifndef KITTY_CPP
#define KITTY_CPP

#include "animation.cpp"
#include "character.cpp"

int KITTY_W = 7;
int KITTY_H = 5;
#define NUM_KITTY_ANIMATIONS 2
Animation* KITTY_ANIMATIONS;

class Kitty : public Character {
    public:
        Kitty() {
           skin.SetAnimations(KITTY_ANIMATIONS);
           size.w = KITTY_W;
           size.h = KITTY_H;
        }
        
        ~Kitty() {
        }
};

#endif // KITTY_CPP
