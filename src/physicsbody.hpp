#ifndef PHYSICSBODY_HPP
#define PHYSICSBODY_HPP

#include <vector>
#include "position.hpp"
#include "size.hpp"
#include "sprite.hpp"

class PhysicsBody : public Sprite {
    public:
        void Move(std::vector<Sprite*>*);
        void PostMove();
        static bool RectCollision(Position, Size, Position, Size);

    protected:
        Position positionDelta;
};

#endif // PHYSICSBODY_HPP
