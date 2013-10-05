#ifndef COLLISIONMASK_HPP
#define COLLISIONMASK_HPP

#include <SDL2/SDL.h>
#include <stdint.h>
#include "size.hpp"

class CollisionMask {
    public:
        CollisionMask(SDL_Surface*, SDL_Rect*);
        ~CollisionMask();
        bool IsCollision(int x, int y, bool flipHorizontal, bool flipVertical);

    private:
        bool* map;
        Size size;
};

#endif // COLLISIONMASK_HPP
