#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "characterskin.hpp"
#include "key.hpp"
#include "physicsbody.hpp"

class Character : public PhysicsBody {
    public:
        Character();
        void KeyPressed(KEY);
        void Update();
};

#endif // CHARACTER_HPP
