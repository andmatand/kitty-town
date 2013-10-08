#ifndef PHYSICSBODY_HPP
#define PHYSICSBODY_HPP

#include <vector>
#include "collisionmask.hpp"
#include "position.hpp"
#include "size.hpp"
#include "skin.hpp"
#include "sprite.hpp"

class PhysicsBody : public Sprite {
    public:
        void Move(std::vector<Sprite*>*);
        void PostMove();

    protected:
        Position positionDelta;

    private:
        static bool IsCollision(Sprite*, Position, Sprite*);
};

#endif // PHYSICSBODY_HPP
