#ifndef SKIN_HPP
#define SKIN_HPP

#include "collisionmask.hpp"
#include "drawable.hpp"

class Skin {
    public:
        virtual ~Skin();
        virtual Drawable* GetDrawable() = 0;
        virtual CollisionMask* GetCollisionMask() = 0;
};

#endif // SKIN_HPP
