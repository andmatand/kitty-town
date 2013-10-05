#include "kitty.hpp"

Kitty::Kitty() {
    size.w = SPRITE_RECTS[0].w;
    size.h = SPRITE_RECTS[0].h;

    static_cast<CharacterSkin*>(skin)->SetAnimationIndicies(0, 1);
}
