#include "kitty.hpp"

Animation* KITTY_ANIMATIONS = new Animation[NUM_KITTY_ANIMATIONS];

const int KITTY_W = 7;
const int KITTY_H = 5;

Kitty::Kitty() {
   skin.SetAnimations(KITTY_ANIMATIONS);
   size.w = KITTY_W;
   size.h = KITTY_H;
}
