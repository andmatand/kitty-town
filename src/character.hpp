#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "key.hpp"
#include "sprite.hpp"

class Character : public Sprite {
    public:
        void KeyPressed(KEY);
        void Update();
};

#endif // CHARACTER_HPP
