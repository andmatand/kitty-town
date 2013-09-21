#ifndef KITTY_CPP
#define KITTY_CPP

#include "animation.cpp"
#include "sprite.cpp"

int KITTY_W = 7;
int KITTY_H = 5;
Animation KITTY_ANIMATIONS[1];

class Kitty : public Sprite {
    public:
        Kitty() {
           skin.SetAnimations(KITTY_ANIMATIONS);
           position.w = KITTY_W * GRAPHICS_SCALE;
           position.h = KITTY_H * GRAPHICS_SCALE;
        }
};

#endif // KITTY_CPP
