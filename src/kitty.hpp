#ifndef KITTY_HPP
#define KITTY_HPP

#include "animation.hpp"
#include "character.hpp"

#define NUM_KITTY_ANIMATIONS 2
extern Animation* KITTY_ANIMATIONS;

extern const int KITTY_W;
extern const int KITTY_H;

class Kitty : public Character {
    public:
        Kitty();
        ~Kitty() {};
};

#endif // KITTY_HPP
